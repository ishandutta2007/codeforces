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

int dp[2][3];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char a;
        scanf(" %c", &a);
        int r = a - '0';
        for (int i = 2; i >= 0; i--) {
            dp[r][i] = max(dp[r][i], dp[r ^ 1][i] + 1);
            if (i > 0) {
                dp[r][i] = max(dp[r][i], dp[r][i - 1] + 1);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            mx = max(dp[i][j], mx);
        }
    }
    printf("%d\n", mx);
    return 0;
}