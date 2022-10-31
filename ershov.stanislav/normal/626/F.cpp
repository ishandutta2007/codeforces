#include <bits/stdc++.h>

using namespace std;

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

const int MOD = (int) 1e9 + 7;

const int maxn = 1100;

void add(int & a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

int dp[300][maxn], ndp[300][maxn];
int n, k, a[maxn];

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  dp[0][0] = 1;
  a[n] = a[n - 1];
  for (int pos = 0; pos < n; pos++) {
    for (int j = 0; j <= n; j++) {
      for (int r = 0; r <= k; r++) {
        ndp[j][r] = 0;
      }
    }
    for (int i = 0; i <= pos; i++) {
      for (int j = 0; j <= k; j++) {
        {
          int can = j + i * (a[pos + 1] - a[pos]);
          if (can <= k) {
            add(ndp[i][can], mult(dp[i][j], i));
          }
        }
        {
          int can = j + i * (a[pos + 1] - a[pos]);
          if (can <= k) {
            add(ndp[i][can], dp[i][j]);
          }
        }
        {
          int can = j + (i + 1) * (a[pos + 1] - a[pos]);
          if (can <= k) {
            add(ndp[i + 1][can], dp[i][j]);
          }
        }
        if (i > 0) {
          int can = j + (i - 1) * (a[pos + 1] - a[pos]);
          if (can <= k) {
            add(ndp[i - 1][can], mult(dp[i][j], i));
          }
        }
      }
    }
    swap(dp, ndp);
    /*for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;*/
  }
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    add(ans, dp[0][i]);
  }
  printf("%d\n", ans);
  return 0;
}