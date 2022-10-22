#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> PI;

const int mod = 998244353;
const int P = 998244353;
const int N = 1 << 19;
const int G = 3;
const int NUM = 20;
const int maxn = 2e5 + 5;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int p[maxn], inv[maxn], ans[maxn];
int wn[NUM];
int a[N], b[N], c[N];

void GetWn() {
    for(int i = 0; i < NUM; i++) {
        int t = 1 << i;
        wn[i] = powt(G, (P - 1) / t);
    }
}

void NTT(int a[],int len,int t) {
    for (int i = 0, j = 0; i < len; i++) {
        if (i > j) swap(a[i], a[j]);
        for (int l = len >> 1; (j ^= l) < l; l >>= 1);
    }
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            int w = 1;
            for(int k = j; k < j + h / 2; ++k) {
                int u = a[k];
                int t = mul(w,a[k + h / 2]);
                a[k] = add(u,t);
                a[k + h / 2] = add(u,P - t);
                w = mul(w,wn[id]);
            }
        }
    }
    if(t == -1) {
        for(int i = 1; i < len / 2; i++) swap(a[i], a[len - i]);
        LL inv = powt(len, P - 2);
        for(int i = 0; i < len; i++)  a[i] = mul(a[i],inv);
    }
}

int h[maxn];

void solve()
{
    int n;
    cin >> n;

    GetWn();
    int len = 1;
    while(len <= 2 * n) len <<= 1;

    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = mul(p[i - 1], i);
    inv[n] = powt(p[n], mod - 2);
    for (int i = n; i > 0; i--) inv[i - 1] = mul(inv[i], i);

    for (int i = n / 2; i + 1 < n; i++) a[i] = p[n - i - 2];
    for (int i = 0; i <= n; i++) b[i] = inv[i];

    NTT(a, len, 1);
    NTT(b, len, 1);
    for(int i = 0; i < len; ++i) c[i] = mul(a[i], b[i]);
    NTT(c, len, -1);

    for (int i = 1; i <= n; i++) h[i] = mul(p[n - i], c[n - i]);
    for (int i = n; i >= 1; i--) {
        h[i] = add(h[i], h[i + 1]);
        ans[i] = add(ans[i], h[i + 1]);
    }

    for(int i = 0; i < len; ++i) a[i] = 0;
    for (int i = 0; i < n / 2; i++) a[i] = p[n - i - 2];
    NTT(a, len, 1);
    for(int i = 0; i < len; ++i) c[i] = mul(a[i], b[i]);
    NTT(c, len, -1);

    for (int i = 1; i <= n; i++) {
        ans[i] = add(ans[i], mul(mul(p[n - i], i - 1), c[n - i]));
    }
    for (int i = 1; i <= n; i++) cout << add(p[n - 1], mod - ans[i]) << " ";
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}