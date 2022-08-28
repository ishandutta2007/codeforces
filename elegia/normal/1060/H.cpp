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

const int N = 12, P0 = 5000, P1 = 4999, TMP = 4998;

int n, p, cur = 2;
int val[N], a[N];
int binom[N][N];
//vector<tuple<bool, int, int, int>> op;

int norm(int x) { return x >= p ? x - p : x; }

int add(int pos, int qos, int to = ++cur) {
  printf("+ %d %d %d\n", pos, qos, to);
  //op.emplace_back(false, pos, qos, to);
  return to;
}

int pw(int pos, int to = ++cur) {
  printf("^ %d %d\n", pos, to);
  //op.emplace_back(true, pos, to, 0);
  return to;
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % p;
    x = x * (ll)x % p;
    k >>= 1;
  }
  return ret;
}

int mv(int pos, int to = ++cur) {
  add(pos, P0, to);
  return to;
}

int mul(int pos, int x, int to = ++cur) {
  if (x == 0) {
    mv(P0, to);
    return to;
  }
  mv(pos, TMP);
  int k = 30;
  while (!(x >> k & 1))
    --k;
  for (--k; k >= 0; --k) {
    add(TMP, TMP, TMP);
    if (x >> k & 1)
      add(pos, TMP, TMP);
  }
  mv(TMP, to);
  return to;
}

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, p, x, y);
  return norm(x + p);
}

int pw2(int x) {
  int c = mv(P0);
  memset(a, 0, sizeof(a));
  for (int d = 0; d <= n - 2; ++d) {
    int coe = ((n ^ d) & 1) ? (p - binom[n - 2][d]) : binom[n - 2][d];
    add(c, mul(pw(add(x, val[d])), coe), c);
    int w = 1;
    for (int i = n; i >= 0; --i) {
      a[i] = (a[i] + w * (ll)coe % p * binom[n][i]) % p;
      w = w * (ll)d % p;
    }
  }
  add(c, mul(P1, norm(p - a[0])), c);
  add(c, mul(x, norm(p - a[1])), c);
  mul(c, inv(a[2]), c);
  return c;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &p);
  {
    int k = 30;
    while (!(p >> k & 1))
      --k;
    for (--k; k >= 0; --k) {
      add(P0, P0, P0);
      if (p >> k & 1)
        add(P0, P1, P0);
    }
  }
  for (int i = 0; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      binom[i][j] = norm(binom[i - 1][j - 1] + binom[i - 1][j]);
  }
  int xpy = add(1, 2);
  val[0] = P0;
  for (int i = 1; i < n; ++i)
    val[i] = add(val[i - 1], P1);
  int dest = mul(add(pw2(xpy), mul(add(pw2(1), pw2(2)), p - 1)), inv(2));
  //int dest = pw2(1);
  printf("f %d\n", dest);
/*
  for (int x = 0; x < p; ++x)
    for (int y = 0; y < p; ++y) {
      static int pool[5001];
      fill(pool, pool + 5001, 1);
      pool[1] = x;
      pool[2] = y;
      for (const auto& tup : op)
        if (!get<0>(tup))
          pool[get<3>(tup)] = norm(pool[get<1>(tup)] + pool[get<2>(tup)]);
        else
          pool[get<2>(tup)] = mpow(pool[get<1>(tup)], n);
      printf("%d * %d %% %d = %d\n", x, y, p, pool[dest]);
    }*/

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}