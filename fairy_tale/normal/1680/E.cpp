#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 2e5 + 5;
const int mod = 998244353;

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

string s[2];
int dp[maxn][2];
void solve()
{
    int n, l, r;
    cin >> n;
    cin >> s[0] >> s[1];

    l = 0;
    r = n - 1;
    while (s[0][l] == '.' && s[1][l] == '.') l++;
    while (s[0][r] == '.' && s[1][r] == '.') r--;

    dp[l][0] = dp[l][1] = 0;
    for (int i = l; i <= r; i++) {
        if (s[0][i] == '*' && s[1][i] == '*') {
            dp[i + 1][0] = min(dp[i][0] + 2, dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 2);
        } else if (s[0][i] == '*') {
            dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 2);
        } else if (s[1][i] == '*') {
            dp[i + 1][0] = min(dp[i][0] + 2, dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 1);
        } else {
            dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1] + 2);
            dp[i + 1][1] = min(dp[i][1] + 1, dp[i][0] + 2);
        }
    }

    cout << min(dp[r + 1][0], dp[r + 1][1]) - 1 << endl;
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