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
typedef pair<int, int> PI;
typedef pair<LL, LL> PL;

const int N = 1 << 19;
const int P = 998244353;
const int G = 3;
const int NUM = 20;

int wn[NUM];
int mul(int x,int y) {
    LL z = 1LL * x * y;
    return z - z / P * P;
}

int add(int x,int y) {
    x += y;
    if(x >= P) x -= P;
    return x;
}

int quick_mod(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = mul(ans,a);
        b >>= 1;
        a = mul(a,a);
    }
    return ans;
}

void GetWn() {
    for(int i = 0; i < NUM; i++) {
        int t = 1 << i;
        wn[i] = quick_mod(G, (P - 1) / t);
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
        LL inv = quick_mod(len, P - 2);
        for(int i = 0; i < len; i++)  a[i] = mul(a[i],inv);
    }
}

int a[N], b[N];
void solve()
{
    GetWn();
    int n, k, f, len;
    cin >> n >> k >> f;
    for (len = 1; len <= max(k, f) * 2; len <<= 1);

    for (int i = 0; i <= k; i++) a[i] = 1;
    for (int i = 1; i < n; i++) {
        NTT(a, len, 1);
        for (int j = 0; j < len; j++) b[j] = mul(a[j], a[j]);
        NTT(b, len, -1);

        for (int j = len - 1, pre = 0; j >= 0; j--) {
            pre = add(pre, b[j]);
            if (j > k) a[j] = 0;
            else {
                a[j] = pre; // val[u] == j
                a[j] = add(a[j], mul(k - j, b[j])); // val[u] > j
            }
        }
    }

    NTT(a, len, 1);
    for (int j = 0; j < len; j++) b[j] = mul(a[j], a[j]);
    NTT(b, len, -1);
    cout << b[f] << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("input.txt", "r", stdin);
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