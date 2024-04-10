#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int NS = 250;
const int N = 5e4 + 10;
const int BITS = 19;
int S;
int n, m;
int a[N], c[1000001];
int f[NS][N];
struct TRI {
    struct node {
        int son[2];
        int mn, mx;
        void clear() {
            mn = 1e9, mx = 0;
            son[0] = son[1] = 0;
        }
    } tri[N * 30];
    int L;
    void init() {
        L = 1;
        tri[1].clear();
    }
    void ins(int s, int v, int vv,int x) {
        tri[s].mx = max(tri[s].mx, vv);
        tri[s].mn = min(tri[s].mn, vv);
        if (!x) return;
        bool sig = ((v & x) > 0);
        if (!tri[s].son[sig])
            tri[tri[s].son[sig] = ++L].clear();
        ins(tri[s].son[sig], v, vv, (x >> 1));
    }
    int getL(int s, int v,int vv, int x) {
        if (tri[s].mn > vv) return 0;
        int w = 0;
        while (x) {
            bool sig = ((v & x) == 0);
            if (!tri[s].son[sig] || tri[tri[s].son[sig]].mn > vv) sig ^= 1;
            else
                w += x;
            x >>= 1;
            s = tri[s].son[sig];
        }
        return w;
    }

    int getR(int s, int v, int vv, int x) {
        if (tri[s].mx < vv) return 0;
        int w = 0;
        while (x) {
            bool sig = ((v & x) == 0);
            if (!tri[s].son[sig] || tri[tri[s].son[sig]].mx < vv) sig ^= 1;
            else
                w += x;
            x >>= 1;
            s = tri[s].son[sig];
        }
        return w;
    }
}TL, TR;
int L;
void pre_L(int*f, int x) {
    TL.init();
    TR.init();
    for (int i = x; i >= 1; i --) {
        TL.ins(1, c[a[i] - 1], a[i], 1 << 20);
        TR.ins(1, c[a[i]], a[i], 1 << 20);
        f[i] = max(TL.getL(1, c[a[i]], a[i], 1 << 20), TR.getR(1, c[a[i] - 1], a[i], 1 << 20));
        if (i != x)
            f[i] = max(f[i], f[i + 1]);
    }

}
void pre_R(int*f, int x) {
    TL.init();
    TR.init();
    for (int i = x; i <= n; i ++) {
        TL.ins(1, c[a[i] - 1], a[i], 1 << 20);
        TR.ins(1, c[a[i]], a[i], 1 << 20);
        f[i] = max(TL.getL(1, c[a[i]], a[i], 1 << 20), TR.getR(1, c[a[i] - 1], a[i], 1 << 20));
        if (i != x)
            f[i] = max(f[i], f[i - 1]);
    }
}
int work(const vector<int>&a) {
    TL.init();
    TR.init();
    int ans = 0;
    for (auto u:a) {
        TL.ins(1, c[u - 1], u, 1 << 20);
        TR.ins(1, c[u], u, 1 << 20);
        ans = max(ans, max(TL.getL(1, c[u], u, 1 << 20), TR.getR(1, c[u - 1], u, 1 << 20)));
    }
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    S = sqrt(n);
    for (int i = 1; i <= 1e6; i ++)
        c[i] = (c[i - 1] ^ i);
    for (int i = 1; i <=n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 0; i * S + 1 <= n; i ++)
    {
        pre_L(f[i], i * S + 1);
        pre_R(f[i], i * S + 1);
    }
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = 0;
        vector<int> b;
        if (r - l + 1 <= S) {
            for (int i = l ; i<= r; i ++)
                b.push_back(a[i]);
            ans = work(b);
        }  else {
            int ll = (l - 1) / S + 1;
            int rr = (r - 1) / S;
            ans = max(f[ll][r], f[rr][l]);
            for (int i = l; i < ll * S + 1; i ++)
                b.push_back(a[i]);
            for (int i = rr * S + 2; i <= r; i ++)
                b.push_back(a[i]);
            ans = max(ans, work(b));
        }
        printf("%d\n", ans);
    }
    return 0;
}