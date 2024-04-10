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

//honestly the complexity is bad and the constant is bad
//and the solution is convoluted
//but here goes nothing

constexpr int N = 200005;

int lst[N];
vi d[N];
vector<pii> lf[N], rg[N];
int sf[N];
int a[N];
bool vis[N];

#define fmin eahiurghaieuh
constexpr int SEG_SZ = N << 2;
constexpr int INF = 69696969;
int fmin[SEG_SZ], smin[SEG_SZ];
int fcnt[SEG_SZ];
ll sum[SEG_SZ];

#define lc (v * 2)
#define rc (v * 2 + 1)

void push(int v) {
    if(fmin[v] > fmin[lc]) {
        sum[lc] += fcnt[lc] * 1LL * (fmin[v] - fmin[lc]);
        fmin[lc] = fmin[v];
    }
    if(fmin[v] > fmin[rc]) {
        sum[rc] += fcnt[rc] * 1LL * (fmin[v] - fmin[rc]);
        fmin[rc] = fmin[v];
    }
}

void pull(int v) {
    sum[v] = sum[lc] + sum[rc];
    if(fmin[lc] == fmin[rc]) {
        fmin[v] = fmin[lc];
        fcnt[v] = fcnt[lc] + fcnt[rc];
        smin[v] = min(smin[lc], smin[rc]);
    }
    else if(fmin[lc] < fmin[rc]) {
        fmin[v] = fmin[lc];
        fcnt[v] = fcnt[lc];
        smin[v] = min(smin[lc], fmin[rc]);
    }
    else {
        fmin[v] = fmin[rc];
        fcnt[v] = fcnt[rc];
        smin[v] = min(fmin[lc], smin[rc]);
    }
}

void bld(int a[], int v = 1, int l = 0, int r = N - 1) {
    if(l == r) {
        sum[v] = a[l];
        fmin[v] = a[l];
        fcnt[v] = 1;
        smin[v] = INF;
    }
    else {
        int m = (l + r) / 2;
        bld(a, lc, l, m);
        bld(a, rc, m + 1, r);
        pull(v);
    }
}

void upd(int ql, int qr, int val, int v = 1, int l = 0, int r = N - 1) {
    if(ql > r || qr < l || val <= fmin[v]) return;
    if(ql <= l && qr >= r && val < smin[v]) {
        sum[v] += fcnt[v] * 1LL * (val - fmin[v]);
        fmin[v] = val;
    }
    else {
        push(v);
        int m = (l + r) / 2;
        upd(ql, qr, val, lc, l, m);
        upd(ql, qr, val, rc, m + 1, r);
        pull(v);
    }
}

ll query(int ql, int qr, int v = 1, int l = 0, int r = N - 1) {
    if(ql > r || qr < l) return 0;
    if(ql <= l && qr >= r) return sum[v];
    else {
        push(v);
        int m = (l + r) / 2;
        return query(ql, qr, lc, l, m) + query(ql, qr, rc, m + 1, r);
    }
}

#undef lc
#undef rc

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> a[i];
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) d[j].pb(i);
        reverse(all(d[i]));
    }
    memset(lst, -1, sizeof(lst));
    memset(vis, 0, sizeof(vis));
    rep(i, n) {
        if(vis[a[i]]) continue;
        else vis[a[i]] = 1;
        for(int j: d[a[i]]) {
            if(~lst[j] && (lf[i].empty() || lst[j] > lf[i].back().se)) {
                lf[i].eb(j, lst[j]);
            }
            lst[j] = i;
        }
    }
    memset(lst, -1, sizeof(lst));
    memset(vis, 0, sizeof(vis));
    for(int i = n - 1; ~i; i--) {
        if(vis[a[i]]) continue;
        else vis[a[i]] = 1;
        for(int j: d[a[i]]) {
            if(~lst[j] && (rg[i].empty() || lst[j] > rg[i].back().se)) {
                rg[i].eb(j, lst[j]);
            }
            if(!~lst[j]) lst[j] = i;
        }
    }
    for(int i = n - 1; ~i; i--) {
        for(auto& [v, p]: lf[i]) {
            sf[p] = max(sf[p], v);
        }
    }
    ll ans = 0;
    for(int i = n - 2; ~i; i--) sf[i] = max(sf[i], sf[i + 1]);
    bld(sf);
    rep(i, n - 1) {
        ans += query(i + 1, n - 1);
        for(auto& [v, p]: rg[i]) upd(i + 1, p, v);
        if(!lf[i].empty()) upd(i + 1, n - 1, lf[i][0].fi);
    }
    int cur = 0;
    rep(i, n - 1) {
        if(!lf[i].empty()) cur = max(cur, lf[i][0].fi);
        ans += cur;
    }
    cout << ans << endl;
}