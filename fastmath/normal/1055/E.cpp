#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1507;
const int INF = 1e9 + 7;

int n, s, m, k;
int a[MAXN];
pair <int, int> d[MAXN];

void read() {
    cin >> n >> s >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < s; ++i) {
        cin >> d[i].first >> d[i].second;
        --d[i].first; --d[i].second;
    }
    
}

bool t[MAXN];
int pref[MAXN];
int dp[MAXN][MAXN];

int get(int i, int lp, int rp, int t) {
    int sum = pref[d[i].second + 1] - pref[d[i].first];

    int best = 0;
    int l = lp;
    int r = min(i - 1, rp);
    for (int p = l; p <= r; ++p) {
        int il = max(d[p].first, d[i].first);
        int ir = min(d[p].second, d[i].second);
        int add = sum;
        if (il <= ir) add -= pref[ir + 1] - pref[il];
        
        int newans = dp[t - 1][p] + add;
        if (dp[t][i] < newans) {
            dp[t][i] = newans;
            best = p;
        }   
    }   

    return best;
}   

void build(int tl, int tr, int lp, int rp, int t) {
    int tm = (tl + tr) >> 1;
    int p = get(tm, lp, rp, t);
    if (tl == tr) return;
    build(tl, tm, lp, p, t); build(tm + 1, tr, p, rp, t);
}   

int get() {
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + t[i];
    for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) dp[i][j] = -INF;

    for (int i = 0; i < s; ++i) {
        dp[1][i] = pref[d[i].second + 1] - pref[d[i].first];
    }   

    for (int t = 2; t <= m; ++t) {
        build(0, s - 1, 0, s - 1, t);
    }   

    int ans = 0;
    for (int i = 1; i <= m; ++i) for (int j = 0; j < s; ++j) ans = max(ans, dp[i][j]);
    return ans;
}   

bool check(int w) {
    for (int i = 0; i < n; ++i) t[i] = (a[i] <= w);
    int best = get();
    return k <= best;
}   

bool comp(pair <int, int> a, pair <int, int> b) {
    return (a.second < b.second) || (a.second == b.second && a.first > b.first);
}   

bool del[MAXN];
pair <int, int> nd[MAXN];
void upd() {
    int mn = INF;
    for (int i = s - 1; i >= 0; --i) {
        if (mn <= d[i].first) {
            del[i] = 1;
        }   
        mn = min(mn, d[i].first);
    }   
    int ns = 0;
    for (int i = 0; i < s; ++i) {
        if (!del[i]) {
            nd[ns++] = d[i];
        }   
    }   
    s = ns;
    m = min(m, s);
    for (int i = 0; i < s; ++i) d[i] = nd[i];
}   

int ans = -1;
void solve() {
    sort(d, d + s, comp);
    upd();

    vector <int> v;
    for (int i = 0; i < n; ++i) v.push_back(a[i]);
    sort(v.begin(), v.end());

    int l = -1;
    int r = n;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (!check(v[mid])) l = mid;
        else r = mid;
    }   
    
    if (r == n) cout << "-1\n";
    else cout << v[r] << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    //cout << (double)clock()/CLOCKS_PER_SEC << '\n';

    return 0;
}