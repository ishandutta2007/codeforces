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

const int maxn = 1e5;
int n;
int a[maxn];

vector<ld> join(vector<ld> a, vector<ld> b) {
  vector<ld> ans(a.size() + b.size() + 10);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      ans[i + j] += a[i] * b[j];
    }
  }
  return ans;
}

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  vector<ld> dp(5100);
  ld prob = (ld) 1 / (n * (n - 1) / 2);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[a[j] - a[i]] += prob;
    }
  }
  vector<ld> dp2 = join(dp, dp);
  ld cur = 0, ans = 0;
  for (int i = 0; i < 5100; i++) {
    ans += cur * dp[i];
    cur += dp2[i];
  }
  printf("%.18f\n", (double) ans);
  return 0;
}