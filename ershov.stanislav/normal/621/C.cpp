#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

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

using namespace std;

const int maxn = (int) 1e5 + 100;
int n, p;

int l[maxn], r[maxn];

ld solve(int l1, int r1, int l2, int r2) {
  ll all = (ll) (r1 - l1 + 1) * (r2 - l2 + 1);
  ll cnt1 = r1 / p - (l1 - 1) / p;
  ll cnt2 = r2 / p - (l2 - 1) / p;
  eprintf(LLD " " LLD "\n", cnt1, cnt2);
  return (ld) ((ll) cnt1 * (r2 - l2 + 1) + (ll) cnt2 * (r1 - l1 + 1) - (ll) cnt1 * cnt2) / all;
}

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
  freopen("text.out", "w", stdout);
#endif
  scanf("%d%d", &n, &p);

  for (int i = 0; i < n; i++) {
    scanf("%d%d", l + i, r + i);
  }

  ld ans = 0;

  for (int i = 0; i < n; i++) {
    ans += solve(l[i], r[i], l[(i + 1) % n], r[(i + 1) % n]);
  }

  printf("%.18f\n", (double) ans * 2000);

  return 0;
}