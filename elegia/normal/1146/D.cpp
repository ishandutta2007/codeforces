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

struct Node {
  int v, step;

  Node(int v, int step) : v(v), step(step) {}

  bool operator<(const Node &rhs) const {
    return step < rhs.step;
  }

  bool operator>(const Node &rhs) const {
    return rhs < *this;
  }

  bool operator<=(const Node &rhs) const {
    return !(rhs < *this);
  }

  bool operator>=(const Node &rhs) const {
    return !(*this < rhs);
  }
};

const int N = 100010;

int m, a, b;
int dis[N];

ll calc(int m, int r) {
  if (m < r)
    return 0;
  // sum i = r -> m, floor((i-r)/b) + 1
  m -= r;
  int cnt = (m + 1) / a;
  return ((m + 1) % a) * (cnt + 1) + a * (ll)cnt * (cnt + 1) / 2;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &m, &a, &b);
  memset(dis, -1, sizeof(dis));
  dis[0] = 0;
  int pos = 0, cur = 0;
  while (true) {
    pos += a;
    cur = max(pos, cur);
    pos -= ((pos - a) / b + 1) * b;
    if (pos < 0)
      pos += b;
    while (pos >= 0) {
      if (dis[pos] != -1)
        break;
      dis[pos] = cur;
      pos -= b;
    }
    if (pos >= 0)
      break;
    pos += b;
  }
  ll ans = 0;
  for (int i = 0; i < a; ++i) {
    if (dis[i] != -1 && dis[i] <= m)
      ans += calc(m, i) - calc(dis[i] - 1, i);
  }
  printf("%lld\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}