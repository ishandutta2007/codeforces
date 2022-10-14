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

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n, m; cin>>n>>m;
        vvi a(n, vi(m));
        rep(i, n) rep(j, m) cin>>a[i][j];
        vector<pii> idx;
        rep(i, n) rep(j, m) idx.eb(i, j);
        sort(all(idx), [&](const pii& x, const pii& y) {return a[x.fi][x.se]<a[y.fi][y.se];});
        vvi ans(n, vi(m, -1));
        vvi rem(n);
        rep(i, idx.size()) {
            if(i<m) ans[idx[i].fi][i]=idx[i].se;
            else rem[idx[i].fi].pb(idx[i].se);
        }
        rep(i, n) rep(j, m) if(!~ans[i][j]) {
            ans[i][j]=rem[i].back();
            rem[i].pop_back();
        }
        rep(i, n) rep(j, m) cout<<a[i][ans[i][j]]<<" \n"[j+1==m];
    }
}