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

const int maxn = 1e5 + 5;
const int mod = 998244353;

struct block {
    LL w[4][4];

    void update(int u, int v, int x) {
        if (x < w[u][v]) w[u][v] = w[v][u] = x;
    }

    void work() {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }

    void merge(block l, block r) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) w[i][j] = min(l.w[i][2] + r.w[0][j], l.w[i][3] + r.w[1][j]) + 1;
        }
    }
} B[maxn], f[maxn << 2];

void build(int t, int l, int r) {
    if (l == r) {
        f[t] = B[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(LSON);
    build(RSON);
    f[t].merge(f[t << 1], f[t << 1 | 1]);
}

block query(int t, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return f[t];
    int mid = (l + r) >> 1;
    if (rr <= mid) return query(LSON, ll, rr);
    if (ll > mid) return query(RSON, ll, rr);
    block ret;
    ret.merge(query(LSON, ll, rr), query(RSON, ll, rr));
    return ret;
}

LL dis(int x, int y, int xx, int yy) {
    int d = max(x, y);
    if (x == d && xx == d) return abs(y - yy);
    if (y == d && yy == d) return abs(x - xx);
    if (x == d && yy == d) return d - y + d - xx;
    if (y == d && xx == d) return d - x + d - yy;
}

int tp[maxn], lf[maxn];
void solve()
{
    int n, q, x, y, x2, y2;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tp[i] = y; // x == i
        cin >> x >> y;
        lf[i] = x; // y == i
    }

    tp[0] = lf[0] = 1;
    tp[n] = lf[n] = n;
    for (int i = 1; i <= n; i++) {
        y = tp[i - 1];
        x = lf[i - 1];
        y2 = tp[i];
        x2 = lf[i];

        B[i].w[0][2] = B[i].w[2][0] = abs(y - y2);
        B[i].w[1][3] = B[i].w[3][1] = abs(x - x2);
        B[i].w[0][3] = B[i].w[3][0] = i - y + i - x2;
        B[i].w[1][2] = B[i].w[2][1] = i - y2 + i - x;
        B[i].w[0][1] = B[i].w[1][0] = i - y + i - x;
        B[i].w[2][3] = B[i].w[3][2] = i - y2 + i - x2;
    }

    for (int i = 2; i <= n; i++) {
        B[i].update(0, 1, B[i - 1].w[2][3] + 2);
        B[i].work();
    }
    for (int i = n - 1; i > 0; i--) {
        B[i].update(2, 3, B[i + 1].w[0][1] + 2);
        B[i].work();
    }

    build(1, 1, n);
    cin >> q;
    LL L[4], R[4], k1, k2, ans;
    while (q--) {
        cin >> x >> y >> x2 >> y2;
        if (max(x, y) > max(x2, y2)) {
            swap(x, x2);
            swap(y, y2);
        }

        k1 = max(x, y);
        k2 = max(x2, y2);
        block e = query(1, 1, n, k1, k2);
        L[0] = dis(x, y, k1, tp[k1 - 1]);
        L[1] = dis(x, y, lf[k1 - 1], k1);
        L[2] = dis(x, y, k1, tp[k1]);
        L[3] = dis(x, y, lf[k1], k1);

        R[0] = dis(x2, y2, k2, tp[k2 - 1]);
        R[1] = dis(x2, y2, lf[k2 - 1], k2);
        R[2] = dis(x2, y2, k2, tp[k2]);
        R[3] = dis(x2, y2, lf[k2], k2);

        ans = 1e18;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) ans = min(ans, e.w[i][j] + L[i] + R[j]);
        }
        if (k1 == k2) ans = min(ans, dis(x, y, x2, y2));
        cout << ans << endl;
    }
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}