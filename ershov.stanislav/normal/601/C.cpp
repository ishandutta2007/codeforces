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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1100;
int n, m;
int x[maxn];
ld dp[maxn * maxn], ndp[maxn * maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    ll sumUs = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", x + i);
        sumUs += x[i];
    }
    if (m == 1) {
        printf("1\n");
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        ld cursum = 0;
        for (int j = 0; j <= n * m; j++) {
            ndp[j] = cursum;
            cursum += dp[j];
            if (j - m >= 0) {
                cursum -= dp[j - m];
            }
        }
        for (int j = x[i]; j <= n * m; j++) {
            ndp[j] -= dp[j - x[i]];
        }
        for (int j = 0; j <= n * m; j++) {
            ndp[j] /= m - 1;
        }
        swap(ndp, dp);
    }
    ld ans = 0;
    for (int i = 0; i < sumUs; i++) {
        ans += dp[i];
    }
    ans *= (m - 1);
    printf("%.18f\n", 1 + (double) ans);
    return 0;
}