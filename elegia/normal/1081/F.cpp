#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 310, P = 1000000007;

int n, a, tt, cnt;
int cur[N], tmp[N];
int bas[N][N], bv[N];

int ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int t;
  scanf("%d", &t);
  if (t == -1) {
    exit(0);
  }
  return t;
}

void exGcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  if (x < 0)
    x += P;
  return x;
}

void ins() {
  int vv = a;
  for (int i = 1; i <= n; ++i)
    if (cur[i] == 1)
      tmp[i] = 1;
    else
      tmp[i] = P - 1;
//  for (int i = 1; i <= n; ++i)
//    LOG("%d ", cur[i]);
//  LOG("| %d\n", vv);
  for (int i = 1; i <= n; ++i) {
    if (tmp[i]) {
      if (bas[i][i]) {
        vv = (vv + (P - 1) * (ll)tmp[i] % P * bv[i]) % P;
        for (int j = i + 1; j <= n; ++j)
          tmp[j] = (tmp[j] + (P - 1) * (ll)bas[i][j] % P * tmp[i]) % P;
        tmp[i] = 0;
      } else {
        int in = inv(tmp[i]);
//        LOG("%d %d\n", tmp[i], in);
        for (int j = i; j <= n; ++j)
          bas[i][j] = tmp[j] * (ll)in % P;
        bv[i] = vv * (ll)in % P;
        ++cnt;
        return;
      }
    }
  }
}

int main() {
  srand(time(NULL));
  scanf("%d%d", &n, &tt);
  for (int i = 1; i <= n; ++i)
    cur[i] = 1;
  a = tt;
  ins();
  while (cnt < n) {
    int l, r;
    while (true) {
      l = rand() % n + 1;
      r = rand() % n + 1;
      if (l > r)
        swap(l, r);
      if ((l ^ r ^ n ^ 1) & 1)
        break;
    }
    int t = ask(l, r);
    if (((tt ^ t) & 1) == ((r) & 1)) {
      for (int i = 1; i <= r; ++i)
        cur[i] = -cur[i];
    } else {
      for (int i = l; i <= n; ++i)
        cur[i] = -cur[i];
    }
    a = t;
    for (int i = 1; i <= n; ++i)
      if (cur[i] == -1)
        --a;
    if (a < 0)
      a += P;
    ins();
    tt = t;
  }
  for (int i = n; i; --i)
    for (int j = 1; j < i; ++j)
      bv[j] = (bv[j] + (P - 1) * (ll)bv[i] % P * bas[j][i]) % P;
  printf("! ");
  for (int i = 1; i <= n; ++i)
    putchar('0' + bv[i]);
  return 0;
}