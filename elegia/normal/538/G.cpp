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

const int N = 200010;

int n, l;
pair<int, pair<ll, pair<ll, ll>>> p[N];

void gg() {
  puts("NO");
  exit(0);
}

ll ffrac(ll x, ll y) {
  if (x >= 0) return x / y;
  return -((-x + y - 1) / y);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    ll t, x, y;
    cin >> t >> x >> y;
    if ((t ^ x ^ y) & 1)
      gg();
    p[i] = make_pair(int(t % l), make_pair(-(t / l), make_pair(x + y, x - y)));
  }
  p[++n] = make_pair(0, make_pair(0LL, make_pair(0LL, 0LL)));
  p[++n] = make_pair(l, make_pair(1LL, make_pair(0LL, 0LL)));
  sort(p + 1, p + n + 1);
  ll lx = -2e18, rx = 2e18, ly = -2e18, ry = 2e18;
  for (int i = 1; i < n; ++i) {
    ll k = p[i].second.first - p[i + 1].second.first;
    ll dx = p[i].second.second.first - p[i + 1].second.second.first;
    ll dy = p[i].second.second.second - p[i + 1].second.second.second;
    int dist = p[i + 1].first - p[i].first;
    if (k < 0) {
      k = -k;
      dx = -dx;
      dy = -dy;
    }
    if (k == 0) {
      if (abs(dx) > dist || abs(dy) > dist)
        gg();
    } else {
      lx = max(lx, ffrac(-dx - dist + k - 1, k));
      rx = min(rx, ffrac(-dx + dist, k));
      ly = max(ly, ffrac(-dy - dist + k - 1, k));
      ry = min(ry, ffrac(-dy + dist, k));
    }
  }
  if (lx > rx || ly > ry) gg();
  ll ansx = (lx + ly) / 2, ansy = (lx - ly) / 2;
  for (int i = -2; i <= 2; ++i)
    for (int j = -2; j <= 2; ++j) {
      if (lx <= (ansx + ansy + i + j) && (ansx + ansy + i + j) <= rx &&
              ly <= (ansx - ansy + i - j) && (ansx - ansy + i - j) <= ry &&
              !((ansx ^ ansy ^ i ^ j ^ l) & 1)) {
        ansx += i;
        ansy += j;
        goto TAG;
      }
    }
  TAG:;
  for (int i = 1; i < n; ++i) {
    int d = p[i + 1].first - p[i].first;
    ll k = p[i].second.first - p[i + 1].second.first;
    ll dx = p[i].second.second.first - p[i + 1].second.second.first;
    ll dy = p[i].second.second.second - p[i + 1].second.second.second;
    k = -k; dx = -dx; dy = -dy;
    dx += k * (ansx + ansy);
    dy += k * (ansx - ansy);
    ll gx = (dx + dy) / 2, gy = (dx - dy) / 2;
    d -= abs(gx) + abs(gy);
    while (gx < 0) {
      putchar('L');
      ++gx;
    }
    while (gx > 0) {
      putchar('R');
      --gx;
    }
    while (gy < 0) {
      putchar('D');
      ++gy;
    }
    while (gy > 0) {
      putchar('U');
      --gy;
    }
    while (d) {
      putchar('L');
      putchar('R');
      d -= 2;
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}