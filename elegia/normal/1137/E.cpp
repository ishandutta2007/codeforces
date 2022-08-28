#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef ll Num;
typedef long double BNum;

struct Vec {
	Num x, y;

	Vec() : x(), y() {}

	Vec(Num x, Num y) : x(x), y(y) {}

	bool operator<(const Vec &rhs) const {
		return x < rhs.x;
	}

	Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
	Vec operator-(const Vec& rhs) const { return Vec(x - rhs.x, y - rhs.y); }

	BNum operator*(const Vec& rhs) const { return x * (BNum) rhs.y - y * (BNum) rhs.x; }
	BNum operator^(const Vec& rhs) const { return x * (BNum) rhs.x + y * (BNum) rhs.y; }
};


const int N = 600010;

int l, r;
ll pos;
ll pl, pr;
ll lk, lb;
Vec hull[N];

ll gv(ll x, ll y) {
  return x * lk + lb + y;
}

ll gv(const Vec& v) {
  return gv(v.x, v.y);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%lld%d", &pr, &m);
  l = m;
  r = m;
  hull[l] = Vec(0, 0);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 1) {
      pl -= y;
      Vec ins(pl, -lk * pl - lb);
      while (r > l && (ins - hull[l + 1]) * (ins - hull[l]) >= 0)
        ++l;
      hull[--l] = ins;
    } else if (x == 2) {
      Vec ins(pr, -lk * pr - lb);
      pr += y;
      while (r > l && (ins - hull[r - 1]) * (hull[r] - hull[r - 1]) >= 0)
        --r;
      hull[++r] = ins;
    } else {
      int z;
      scanf("%d", &z);
      lb += y - z * pl;
      lk += z;
    }
    int ml = l, mr = r;
    while (ml < mr) {
      int mid = (ml + mr) >> 1;
      if (gv(hull[mid]) > gv(hull[mid + 1]))
        ml = mid + 1;
      else
        mr = mid;
    }
    printf("%lld %lld\n", hull[ml].x - pl + 1, gv(hull[ml]));
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}