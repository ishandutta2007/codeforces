#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

double dp[111][111][111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    for (int i = 0; i < 111; i++) {
        for (int j = 0; j < 111; j++) {
            for (int k = 0; k < 111; k++) {
                if (i == 0 && j == 0 && k == 0) {
                    continue;
                }
                if (i > 0 && k == 0 && j == 0) {
                    dp[i][j][k] = 1;
                }
                if (j > 0 && i == 0 && k == 0) {
                    dp[i][j][k] = 0;
                }
                if (k > 0 && i == 0 && j == 0) {
                    dp[i][j][k] = 0;
                }
                int cnt = i * j + i * k + j * k;
                if (i > 0 && j > 0) {
                    dp[i][j][k] += dp[i][j - 1][k] * i * j / (double) cnt;
                }
                if (i > 0 && k > 0) {
                    dp[i][j][k] += dp[i - 1][j][k] * i * k / (double) cnt;
                }
                if (k > 0 && j > 0) {
                    dp[i][j][k] += dp[i][j][k - 1] * k * j / (double) cnt;
                }
            }
        }
    }

    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    printf("%.15f %.15f %.15f", dp[r][s][p], dp[s][p][r], dp[p][r][s]);

    return 0;
}