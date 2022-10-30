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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n;

int dp[1000000 + 100], prev[1000000 + 100], pow1[10];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    pow1[0] = 1;
    for (int i = 1; i < 10; i++) {
        pow1[i] = pow1[i - 1] * 10;
    }
    if (n == 1e6) {
        cout << "1\n1000000\n";
        return 0;
    }
    dp[0] = 0;
    dp[1] = 1;
    prev[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = INF;
        for (int k = 0; k < 64; k++) {
            int last = 0;
            for (int j = 0; j < 6; j++) {
                if (k & (1 << j)) {
                    last += pow1[j];
                }
            }
            if (i >= last && dp[i] > 1 + dp[i - last]) {
                dp[i] = 1 + dp[i - last];
                prev[i] = i - last;
            }
        }
    }
    printf("%d\n", dp[n]);
    for (int i = n; i != 0; i = prev[i]) {
        printf("%d ", i - prev[i]);
    }
    return 0;
}