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

template<typename T, typename Comparator>
vi __lis(const vector<T>& a, const T& inf, const T& neg_inf, const Comparator& comp) {
    int n=a.size();
    vector<T> d(n+1, inf);
    d[0]=neg_inf;
    vi p(n, -1);
    vi id(n+1, -1);
    rep(i, n) {
        int j=upper_bound(all(d), a[i], comp)-d.begin();
        if(comp(d[j-1], a[i])&&comp(a[i], d[j])) {
            d[j]=a[i];
            id[j]=i;
            p[i]=id[j-1];
        }
    }
    int mx=0, pos=-1;
    rep(i, n+1) if(comp(d[i], inf)) mx=i, pos=id[i];
    vi ans;
    while(~pos) ans.pb(pos), pos=p[pos];
    reverse(all(ans));
    return ans;
}

__attribute__((always_inline)) auto LIS(vi& a) {return __lis<int, less<int>>(a, INT_MAX, INT_MIN, less<int>());}
__attribute__((always_inline)) auto LDS(vi& a) {return __lis<int, greater<int>>(a, INT_MIN, INT_MAX, greater<int>());}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        vi a(n);
        rep(i, n) cin>>a[i];
        vvi ans;
        while(!a.empty()) {
            auto lis=LIS(a);
            auto lds=LDS(a);
            if(lis.size()<lds.size()) lis.swap(lds);
            int sz=lis.size();
            if(sz*(sz+1)>2*a.size()) {
                ans.pb(vi{});
                for(int v: lis) ans.back().pb(a[v]);
                vi nxt;
                int ptr=0;
                rep(i, a.size()) {
                    if(ptr<lis.size()&&i==lis[ptr]) ptr++;
                    else nxt.pb(a[i]);
                }
                a=move(nxt);
            }
            else {
                vb vis(a.size());
                for(int cnt=a.size(); cnt; ) {
                    int s=INT_MAX;
                    ans.pb(vi{});
                    rep(i, a.size()) if(!vis[i]&&a[i]<s) {
                        ans.back().pb(a[i]);
                        s=a[i];
                        vis[i]=1;
                        cnt--;
                    }
                }
                break;
            }
        }
        cout<<ans.size()<<endl;
        for(auto& vec: ans) {
            cout<<vec.size()<<' ';
            for(auto& v: vec) cout<<v<<' ';
            cout<<endl;
        }
    }
}