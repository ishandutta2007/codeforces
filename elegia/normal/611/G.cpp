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

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 1000000007;

struct Vec {
  ll x, y;

  Vec(ll x = 0, ll y = 0) : x(x), y(y) {}

  Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
  Vec operator-() const { return Vec(-x, -y); }
  Vec operator-(const Vec& rhs) const { return *this + (-rhs); }

  ll operator^(const Vec& rhs) const { return x * rhs.x + y * rhs.y; }
  ll operator*(const Vec& rhs) const { return x * rhs.y - y * rhs.x; }

  Vec mod() const { return Vec(x % P, y % P); }
};

const int N = 500010;

int n;
Vec a[N * 2];
int s1[N * 2], s2[N * 2];
Vec vs1[N * 2];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = n; i; --i)
    scanf("%lld%lld", &a[i].x, &a[i].y);
  copy(a + 1, a + n + 1, a + n + 1);
  ll whole = 0;
  for (int i = 1; i <= n; ++i)
    whole += (a[i] - a[1]) * (a[i + 1] - a[1]);

  for (int i = 1; i < n * 2; ++i)
    s1[i] = (s1[i - 1] + (a[i] * a[i + 1])) % P;
  for (int i = 1; i < n * 2; ++i)
    s2[i] = (s2[i - 1] + (a[i] * a[i + 1]) % P * i) % P;
  for (int i = 1; i < n * 2; ++i)
    vs1[i] = (vs1[i - 1] + a[i]).mod();

  function<int(int, int)> getsum = [&](int l, int r) {
    int ret = 0;
    ret = (ret + s2[r] - s2[l - 1]) % P;
    ret = ((s1[r] - s1[l - 1]) * (ll)r % P - ret) % P;
    return ret;
  };

  function<int(int, int)> shapesum = [&](int l, int r) {
    int ret = 0;
    ret = getsum(l, r);
    Vec vsum = ((vs1[r] - vs1[l]) - Vec(a[l].x * (r - l), a[l].y * (r - l))).mod();
    ret = (ret + (vsum * a[l])) % P;
    /*int ret2 = 0, cur = 0;
    for (int i = l + 1; i < r; ++i)
      ret2 += (cur += (a[i] - a[l]) * (a[i + 1] - a[l]));
    */
    return ret;
  };
  // sum_{k <= i <= n} sum_{k < j <= i} (a[j - 1] - a[k]) * (a[j] - a[k])
  // a[j - 1] * a[j] - a[k] * a[j] - a[j - 1] * a[k]
  // = a[j - 1] * a[j] + (a[j] - a[j - 1]) * a[k]

  int ans2 = 0;
  int p = 1, ans = 0;
  ll cur = 0;
  for (int i = 1; i <= n; ++i) {
    while (cur < 0 || (ull)cur * 2 < whole) {
      cur += (a[p] - a[i]) * (a[p + 1] - a[i]);
      ++p;
    }
//    cerr << cur << ' ' << whole << ' ' << a[p].x << ' ' << a[p].y << '\n';
    cur -= (a[i + 1] - a[i]) * (a[p] - a[i]);
    int tmp = ans;
    ans = (ans + whole % P * (n - 3)) % P;
    ans = (ans - shapesum(i, p - 1) * 2LL) % P;
    ans = (ans - (whole % P * (n + i - p) % P - (shapesum(i, i + n - 1) - shapesum(i, p - 1))) * 2LL) % P;

    /*
    {
      int res = 0, to = 0;
      for (int j = 2; j < n - 1; ++j) {
        res += (a[i + j - 1] - a[i]) * (a[i + j] - a[i]);
        if (res * 2 < whole)
          to += whole - res * 2;
        else
          to += res * 2 - whole;
        cerr << res << "(" << abs(whole - res * 2) << ") ";
      }
      cerr << "  |  " << to << ' ';
      ans2 += to;
    }
    cerr << (ans - tmp) << '\n';*/
  }
  ans = ans * ((P + 1LL) >> 1) % P;
  if (ans < 0) ans += P;
  printf("%d\n", ans);


#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}