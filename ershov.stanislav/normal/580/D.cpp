#include<bits/stdc++.h>

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
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 18;
const int POWERN = 1 << N;

int n, m, k;

ll a[N];
ll add[N][N];
ll dp[POWERN][N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf(LLD, &a[i]);
        for (int j = 0; j < n; j++) {
            add[j][i] = a[i];
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        x--, y--;
        add[x][y] += c;
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) {
                        dp[mask | (1 << i)][i] = max(dp[mask | (1 << i)][i], dp[mask][j] + add[j][i]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == m) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[mask][j]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}