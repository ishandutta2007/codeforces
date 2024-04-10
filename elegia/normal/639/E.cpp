#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 150010;
const double EPS = 1e-7;

int n, m, k;
ll tot;
int disc[N], id[N], al[N], ar[N];
double mn[N], mx[N], g[N];
pair<int, int> a[N];

bool pred(double c) {
  fill(mn + 1, mn + m + 1, 1e18);
  fill(mx + 1, mx + m + 1, -1);
  ll x = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = al[i]; j <= ar[i]; ++j) {
      double v = (1 - c * (x + a[j].second) / tot) * a[j].first;
      mx[id[j]] = max(mx[id[j]], v);
      g[j] = v;
      if (j > al[i]) g[j] = min(g[j], g[j - 1]);
    }
    for (int j = al[i]; j <= ar[i]; ++j) x += a[j].second;
    for (int j = al[i]; j <= ar[i]; ++j) {
      double v = (1 - c * x / tot) * a[j].first;
      mn[id[j]] = min(mn[id[j]], v);
      if (v > g[j - 1] && j > al[i] && a[j].first != a[j - 1].first) return true;
    }
  }
  //cerr << '\n';
  for (int i = 2; i <= m; ++i)
    mx[i] = max(mx[i], mx[i - 1]);
  for (int i = 2; i <= m; ++i)
    if (mn[i] < mx[i - 1]) return true;
  return false;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].first);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].second);
  for (int i = 1; i <= n; ++i) tot += a[i].second;
  sort(a + 1, a + n + 1, [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    ll x = lhs.first * (ll)rhs.second, y = rhs.first * (ll)lhs.second;
    if (x == y) return lhs.first > rhs.first;
    return x > y;
  });
  al[++k] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[al[k]].first * (ll)a[i].second != a[al[k]].second * (ll)a[i].first) {
      ar[k] = i - 1;
      al[++k] = i;
    }
  }
  ar[k] = n;
  for (int i = 1; i <= n; ++i) disc[i] = a[i].first;
  sort(disc + 1, disc + n + 1);
  m = unique(disc + 1, disc + n + 1) - disc - 1;
  for (int i = 1; i <= n; ++i) id[i] = lower_bound(disc + 1, disc + m + 1, a[i].first) - disc;
  double l = 0, r = 1;
  while (r - l > EPS) {
    double mid = (l + r) / 2;
    if (pred(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10f\n", l);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}