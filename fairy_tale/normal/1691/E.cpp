#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int p[maxn], ans;
vector<P> f[maxn << 2];
int fg[maxn << 2];

int ff(int x) {
    if (p[x] != x) p[x] = ff(p[x]);
    return p[x];
}

void merge(int u, int v) {
    u = ff(u);
    v = ff(v);
    if (u != v) {
        ans--;
        p[u] = v;
    }
}

void init(int t, int l, int r) {
    f[t].clear();
    fg[t] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    init(LSON);
    init(RSON);
}

void update(int t, int l, int r, int ll, int rr, P u) {
    if (ll <= l && r <= rr) {
        f[t].push_back(u);
        fg[t] |= 1 << u.fi;
        return;
    }

    int mid = (l + r) >> 1;
    if (ll <= mid) update(LSON, ll, rr, u);
    if (rr > mid) update(RSON, ll, rr, u);
    fg[t] |= fg[t << 1] | fg[t << 1 | 1];
}

void build(int t, int l, int r) {
    P u0, u1;
    u0 = u1 = P(0, 0);
    //cout << t << " : " << l << " " << r << endl;
    for (auto e:f[t]) {
        //cout << e.fi << " " << e.se << endl;
        if (e.fi == 1) u1 = e;
        else u0 = e;
    }

    if ((fg[t] & 1) && !u0.se) u0 = u1;
    if ((fg[t] & 2) && !u1.se) u1 = u0;

    for (auto e:f[t]) {
        if (e.fi == 1) {
            if (u0.se) merge(e.se, u0.se);
        }
        else {
            if (u1.se) merge(e.se, u1.se);
        }
    }

    if (l == r) return;
    int mid = (l + r) >> 1;

    if (u0.se) {
        f[t << 1].push_back(u0);
        f[t << 1 | 1].push_back(u0);
    }
    if (u1.se) {
        f[t << 1].push_back(u1);
        f[t << 1 | 1].push_back(u1);
    }
    build(LSON);
    build(RSON);
}

array<int, 3> d[maxn];
void solve()
{
    int n;
    cin >> n;

    vector<int> w;
    for (int i = 1; i <= n; i++) {
        cin >> d[i][0] >> d[i][1] >> d[i][2];
        w.push_back(d[i][1]);
        w.push_back(d[i][2]);
    }

    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    int m = w.size();

    init(1, 1, m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        d[i][1] = lower_bound(w.begin(), w.end(), d[i][1]) - w.begin() + 1;
        d[i][2] = lower_bound(w.begin(), w.end(), d[i][2]) - w.begin() + 1;

        //cout << d[i][1] << " == " << d[i][2] << endl;
        update(1, 1, m, d[i][1], d[i][2], P(d[i][0], i));
    }

    ans = n;
    build(1, 1, m);
    cout << ans << endl;
}


int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}