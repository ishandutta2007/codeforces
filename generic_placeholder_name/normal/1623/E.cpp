#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

constexpr int N = 200005;
int l[N], r[N];
string s, t;
vi ord{-1};
int dvg[N];
int par[N];
bool good[N];
bool dup[N];

void dfs(int u) {
    if(l[u]) par[l[u]] = u, dfs(l[u]);
    t.pb(s[u]);
    ord.pb(u);
    if(r[u]) par[r[u]] = u, dfs(r[u]);
}

int k;
void solve(int u) {
    int id = -1, v = u;
    rep(_, k) {
        if(good[v]) id = v;
        v = l[v];
        if(!v) break;
    }
    if(!~id) return;
    for(int v = u; ; v = l[v]) {
        dup[v] = 1; k--;
        if(v == id) break;
    }
    if(!k) return;
    for(int v = id; ; v = par[v]) {
        solve(r[v]);
        if(v == u) break;
    }
}

int32_t main() {
    fastio;
    int n; cin >> n >> k;
    cin >> s; s = 'A' + s + 'A';
    rep1(i, n) cin >> l[i] >> r[i];
    dfs(1);
    t = 'A' + t + 'A';
    dvg[n] = n;
    for(int i = n - 1; i; i--) {
        if(t[i] != t[i + 1]) dvg[i] = i;
        else dvg[i] = dvg[i + 1];
    }
    rep1(i, n) if(t[i] < t[i + 1] || (t[i] == t[i + 1] && t[dvg[i + 1]] < t[dvg[i + 1] + 1])) good[ord[i]] = 1;
    solve(1);
    string ans;
    rep1(i, n) {
        ans.pb(t[i]);
        if(dup[ord[i]]) ans.pb(t[i]);
    }
    cout << ans << endl;
}