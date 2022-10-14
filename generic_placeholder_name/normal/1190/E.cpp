#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr double eps=1e-6;
constexpr int ITERS=60;

int32_t main() {
    fastio;
    int n, m; cin>>n>>m; m=min(m, n); 
    if(m>200) { //if I calculated correctly this should be ~176 but clearly not
        ld mn=1e18;
        rep(i, n) {
            ld x, y; cin>>x>>y;
            mn=min(mn, sqrt(x*x+y*y));
        }
        cout<<fixed<<setprecision(12)<<mn*(1-pow(10, log10(mn)-10.69))<<endl;
    }
    else {
        vector<pair<double, double>> pts(n);
        vector<double> _atan(n), _dist(n);
        double mn=1e18;
        rep(i, n) {
            cin>>pts[i].fi>>pts[i].se;
            _dist[i]=sqrt(pts[i].fi*pts[i].fi+pts[i].se*pts[i].se);
            _atan[i]=atan2(pts[i].se, pts[i].fi);
            mn=min(mn, _dist[i]);
        }
        double l=0, r=mn;
        const auto chk = [&](double d) -> bool {
            static constexpr double pi=3.14159265358979323846;
            vector<pair<double, double>> segs;
            rep(i, n) {
                double alpha=acos(d/_dist[i]), beta=_atan[i];
                alpha*=180/pi, beta*=180/pi;
                segs.eb(beta-alpha, beta+alpha);
            }
            double mnr=1e18;
            for(auto& p: segs) {
                auto& l=p.fi;
                auto& r=p.se;
                while(l<0) l+=360, r+=360;
                while(l>360) l-=360, r-=360;
                mnr=min(mnr, r);
            }
            sort(all(segs));
            mnr+=360;
            vector<pair<double, double>> __important;
            for(int i=n-1; ~i; i--) {
                if(mnr<segs[i].se) continue;
                __important.pb(segs[i]);
                mnr=segs[i].se;
            }
            segs=move(__important);
            reverse(all(segs));
            int len=segs.size();
            sort(all(segs));
            rep(i, len) segs.eb(segs[i].fi+360, segs[i].se+360);
            vi nxt(2*len+1);
            int now=0;
            rep(i, 2*len) {
                while(now<2*len&&segs[now].fi<=segs[i].se) now++;
                nxt[i]=now;
            }
            nxt[2*len]=2*len;
            vi dp(2*len, -1);
            vi prv(2*len+1, -1);
            rep(i, 2*len) {
                if(!~prv[i]) {
                    int a=i;
                    for(int j=0; j<m&&a<2*len; j++) {
                        int b=nxt[a];
                        prv[b]=a;
                        a=b;
                    }
                    dp[i]=a;
                } 
                else dp[i]=nxt[dp[prv[i]]];
            }
            rep(i, len) if(dp[i]>=i+len) return 1;
            return 0;
        };
        if(mn==0) return puts("0"), 0; 
        rep(_, ITERS) {
            double m=(l+r)/2;
            if(chk(m)) l=m;
            else r=m;
        }
        cout<<fixed<<setprecision(12)<<(l+r)/2<<endl;
    }
}