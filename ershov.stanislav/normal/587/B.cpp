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

const int N = 2e6 + 100;
const int MOD = 1e9 + 7;

ll n, l, k;
int a[N], b[N];
vector<int> dp[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf(LLD "" LLD "" LLD, &n, &l, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b, b + n);
    vector<pair<int, int> > v;
    for (int i = 0, cnt = 0; i < n; i++) {
        cnt++;
        if (i == n - 1 || b[i + 1] != b[i]) {
            v.eb(b[i], cnt);
            cnt = 0;
        }
    }
    int m = sz(v);
    dp[0].resize(m, 1);
    for (int i = 1; i <= k; i++) {
        dp[i].resize(m);
        for (int j = 0; j < m; j++) {
            dp[i][j] = (dp[i - 1][j] * 1ll * v[j].sc) % MOD;
        }
        for (int j = 1; j < m; j++) {
            dp[i][j] += dp[i][j - 1];
            if (dp[i][j] >= MOD) {
                dp[i][j] -= MOD;
            }
        }
    }
//    for (int i = 0; i < 3; i++) {
//
//        for (int j = 0; j < m; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
    ll ans = 0;
    for (int i = 1; i <= min(k, l / n); i++) {
        ans = (ans + dp[i][m - 1] * 1ll * ((l / n - i + 1) % MOD) % MOD) % MOD;
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < m; i++) {
            dp[j][i] = (dp[j][i] + dp[j - 1][i]) % MOD;
        }
    }
    int cnt = l % n;
    for (int j = 0; j < cnt; j++) {
        int it = (int) (lower_bound(all(v), mp(a[j], 0)) - v.begin());
        ans = (ans + dp[min(k - 1, l / n)][it]) % MOD;
    }
    printf("%d\n", (int) ((ans % MOD + MOD) % MOD));
    return 0;
}