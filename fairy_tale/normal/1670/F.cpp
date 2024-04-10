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
typedef pair<int, int> P;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

void upd(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
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


int dp[65][1005], c[1005][1005];
int work(LL m, int n, LL x)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= 60; i++) {
        int k = (x >> (60 - i)) & 1;
        for (int j = 0; j <= n; j++) {
            int d = j * 2 + ((m >> (60 - i)) & 1);
            for (int r = k; r <= min(d, n); r += 2) {
                upd(dp[i + 1][min(d - r, n)], mul(dp[i][j], c[n][r]));
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= n; i++) upd(res, dp[61][i]);
    return res;
}


void solve()
{
    int n;
    LL L, R, z;

    cin >> n >> L >> R >> z;

    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
    //work(R, n, z);
    cout << add(work(R, n, z), mod - work(L - 1, n, z)) << endl;
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