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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 3e5 + 100;

int n, k;
int A[N];
int dp[5050][5050];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    int c1 = n / k, c2 = ((n + k - 1) / k);
    int d1 = k - (n % k), d2 = n % k;
    sort(A + 1, A + n + 1);
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i * c1 + j * c2] - A[i * c1 + j * c2 - c1 + 1]);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i * c1 + j * c2] - A[i * c1 + j * c2 - c2 + 1]);
                }
            }
        }
    }
    cout << dp[d1][d2] << endl;
    return 0;
}