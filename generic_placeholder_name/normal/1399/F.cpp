#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        //coordinate compression
        set<int> s; map<int, int> m;
        vector<pii> line(n); rep(i, n) cin>>line[i].fi>>line[i].se, s.insert(line[i].fi), s.insert(line[i].se);
        int cur=0, M=s.size(); while(!s.empty()) m[*s.begin()]=++cur, s.erase(s.begin());
        rep(i, n) line[i].fi=m[line[i].fi], line[i].se=m[line[i].se];
        //end
        //dp
        vvi dp(M+1, vi(M+1, 0));
        vvb vis(M+1, vb(M+1, 0));
        vvi pt(M+1);
        rep(i, n) pt[line[i].fi].pb(line[i].se);
        rep(i, M+1) sort(all(pt[i]));
        function<void(int, int)> solve = [&](int l, int r) {
            if(vis[l][r]) return;
            vis[l][r]=1;
            if(l!=r) solve(l+1, r), dp[l][r]=dp[l+1][r];
            int cnt=0;
            auto lf=lower_bound(all(pt[l]), l);
            for(auto i=lf; i<pt[l].end(); i++) {
                int m=*i;
                if(m>r) break;
                else if(m==r) {cnt++; continue;}
                //i literally have no idea why this works
                //but the last one didn't
                solve(l, m);
                solve(m+1, r);
                dp[l][r]=max(dp[l][r], dp[l][m]+dp[m+1][r]);
            }
            dp[l][r]+=cnt;
        };
        solve(0, M);
        cout<<dp[0][M]<<endl;
    }
}