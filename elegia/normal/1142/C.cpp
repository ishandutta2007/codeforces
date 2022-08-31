#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Vec {
  ll x, y;

  Vec(ll x = 0, ll y = 0) : x(x), y(y) {}

  Vec operator+(const Vec &rhs) const { return Vec(x + rhs.x, y + rhs.y); }

  Vec operator-() const { return Vec(-x, -y); }

  Vec operator-(const Vec &rhs) const { return *this + -rhs; }

  ll operator*(const Vec& rhs) const { return x * rhs.y - y * rhs.x; }

  bool operator<(const Vec &rhs) const {
    if (x < rhs.x)
      return true;
    if (rhs.x < x)
      return false;
    return y > rhs.y;
  }
};

const int N = 100010;

int n;
Vec a[N], stk[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = Vec(x, y - x * (ll)x);
  }
  sort(a + 1, a + n + 1);
  int r = 0;
  a[0].x = numeric_limits<ll>::max();
  for (int i = 1; i <= n; ++i) {
    if (a[i].x == a[i - 1].x && a[i].y < a[i - 1].y)
      continue;
    while (r > 1 && (stk[r] - stk[r - 1]) * (a[i] - stk[r]) >= 0)
      --r;
    stk[++r] = a[i];
  }
  printf("%d\n", r - 1);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}