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

const int mod = 998244353;
const int maxn = 5e5 + 5;

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

int a[15], m;
int f[13][12][12];

void dfs(int id, int x)
{
    if (x > 11) return;

    if (id > m) {
        int mask = 0;
        for (int i = 1; i < m; i++) {
            mask |= 1 << (a[i] - 1);
            if (mask == ((1 << i) - 1)) return;
        }

        int y = 0;
        for (int i = 1; i < m; i++) {
            if (a[i] > a[i + 1]) y++;
        }
        f[m][x][y]++;

        //if (m == 3 && x == 1) cout << "!!!!" << endl;

        return;
    }

    dfs(id + 1, x);
    for (int i = id; i > 1; i--) {
        swap(a[i], a[i - 1]);
        x++;
        dfs(id + 1, x);
    }

    for (int i = 1; i < id; i++) swap(a[i], a[i + 1]);
}

LL dp[55][25][25][25];

void preInit()
{
    for (int i = 1; i <= 12; i++) {
        m = i;
        for (int j = 1; j <= m; j++) a[j] = j;
        dfs(1, 0);
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int u = 0; u < 25; u++) {
        for (int v = 0; v < 12; v++) {
            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11; j++) {
                    if (!dp[u][v][i][j]) continue;
                    dp[u][v][i][j] %= mod;

                    for (int aa = 2; aa <= 12; aa++) {
                        for (int bb = 1; bb <= 11; bb++) {
                            for (int cc = 1; cc <= 11; cc++) {
                                dp[u + aa][v + 1][i + bb][j + cc] += dp[u][v][i][j] * f[aa][bb][cc] % mod;
                            }
                        }
                    }
                }
            }
        }
    }
}

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    LL ans = 0;
    for (int i = 2; i <= min(n, 24); i++) {
        for (int j = 1; j <= 11; j++) {
            int w = dp[i][j][k][d];
            if (w == 0) continue;
            //cout << i << " " << j << " " << w << endl;
            LL f1 = 1, f2 = 1;
            for (int r = 0; r < j; r++) f1 = mul(f1, n - i + j - r);
            for (int r = 1; r <= j; r++) f2 = mul(f2, r);
            ans += w * f1 % mod * powt(f2, mod - 2) % mod;
        }
    }
    cout << ans % mod << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    preInit();

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}