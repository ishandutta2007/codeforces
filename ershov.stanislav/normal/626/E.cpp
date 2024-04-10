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

struct Ratio {
  ll a, b;
  Ratio (ll a = 0, ll b = 1) : a(a), b(b) {}
  
  bool operator<(const Ratio & x) const {
    return a * x.b < b * x.a;
  }
};

const int maxn = 5e5;
int n;
ll x[maxn], sum[maxn];

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(LLD, x + i);
  }
  sort(x, x + n);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + x[i];
  }
  Ratio best(0, 1);
  int besti = 0, bestlen = 0;
  for (int i = 1; i < n; i++) {
    int l = 0, r = i;
    while (l < r) {
      int mid = (l + r) / 2;
      Ratio x(sum[i + 1] - sum[i - mid] + sum[n] - sum[n - mid], 2 * mid + 1);
      Ratio y(sum[i + 1] - sum[i - mid - 1] + sum[n] - sum[n - mid - 1], 2 * mid + 3);
      if (y < x) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    Ratio cur(sum[i + 1] - sum[i - l] + sum[n] - sum[n - l], 2 * l + 1);
    cur.a -= cur.b * x[i];
    if (best < cur) {
      best = cur;
      besti = i;
      bestlen = l;
    }
  }
  printf("%d\n", bestlen * 2 + 1);
  vector<int> ans;
  for (int i = besti - bestlen; i <= besti; i++) {
    ans.pb(x[i]);
  }
  for (int i = n - bestlen; i < n; i++) {
    ans.pb(x[i]);
  }
  for (int i = 0; i < sz(ans); i++) {
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
  }
  return 0;
}