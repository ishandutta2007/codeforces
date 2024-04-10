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

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 4444;
const int MOD = 1e9 + 7;

ll dp[N][N], bell[N];
int n;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

ll inv(ll a) {
    return power(a, MOD - 2);
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;
        }
        for (int j = 1; j <= i; j++) {
            bell[i] = (bell[i] + dp[i][j]) % MOD;
        }
//        cout << bell[i] << endl;
    }
    bell[0] = 1;
    ll ans = 0;
    ll c = 1;
    for (int i = 1; i <= n; i++) {
        c *= n - i + 1;
        c %= MOD;
        c *= inv(i);
        c %= MOD;
        ans = (ans + c * bell[n - i]) % MOD;
    }
    ans = ans % MOD;
    ans += MOD;
    ans = ans % MOD;
    printf("%d\n", (int) ans);
    return 0;
}