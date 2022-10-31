#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 5500;
const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

int n;
char s[maxn];
int nxt[maxn][maxn];
int dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    scanf(" %s", &s);
    s[n] = '9' + 1;
    for (int l = 1; l < n; l++) {
        for (int i = n - 1 - l, j = n - l; i >= 0; i--) {
            if (s[i] != s[i + l]) {
                j = i;
            }
            nxt[i][i + l] = j;
        }
    }
    for (int i = 0; i < maxn; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i - j] == '0') {
                continue;
            }
            //cout << i << ' ' << j << endl;
            dp[i][j] = add(dp[i][j], dp[i - j][j - 1]);
            if (2 * j <= i) {
                int tocmp = nxt[i - 2 * j][i - j];
                if (tocmp < i - j && s[tocmp] < s[tocmp + j]) {
                    dp[i][j] = add(dp[i][j], add(dp[i - j][j], MOD - dp[i - j][j - 1]));
                }
            }
        }
        for (int j = 1; j < maxn; j++) {
            dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n", dp[n][n]);
    return 0;
}