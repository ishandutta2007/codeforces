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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1100;
const int MOD = 1e9 + 7;

ll c[N * 2][N * 2];
int k;
vector<int> a;
ll dp[N], dp2[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    for (int i = 0; i < N * 2; i++) {
        c[i][0] = 1;
    }
    for (int i = 1; i < N * 2 - 1; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int b;
        scanf("%d", &b);
        a.pb(b);
    }
    reverse(all(a));
    dp[0] = 1;
    for (auto i : a) {
        for (int j = N - 2; j >= 0; j--) {
            dp[j] = dp[j] + dp[j + 1];
            dp[j] %= MOD;
        }
        for (int j = 0; j + i < N; j++) {
            dp2[j + i - 1] = dp[j] * c[i + j][j] % MOD;
            if (j > 0) {
                dp2[j + i - 1] -= dp[j] * c[i + j - 1][j - 1] % MOD;
                dp2[j + i - 1] += MOD;
                dp2[j + i - 1] %= MOD;
            }
        }
        for (int i = 0; i < N; i++) {
            dp[i] = dp2[i];
            dp2[i] = 0;
//            cout << dp[i] << ' ';
        }
//        cout << endl;
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + dp[i];
        sum %= MOD;
    }
    printf(LLD"\n", sum);
    return 0;
}