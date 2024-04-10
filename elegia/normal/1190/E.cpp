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
#include <complex>
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

typedef complex<double> Vec;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100010, L = 19;
const double EPS = 1e-8, PI = acos(-1);

int n, m;
Vec p[N];
double argp[N], len[N];
int jmp[N * 2][L];
pair<double, double> rg[N * 2];


bool pred(double r) {
  for (int i = 1; i <= n; ++i) {
    double th = acos(r / len[i]);
    rg[i] = make_pair(argp[i] - th, argp[i] + th);
    if (rg[i].first < -PI) {
      rg[i].first += PI * 2;
      rg[i].second += PI * 2;
    } else if (rg[i].first > PI) {
      rg[i].first -= PI * 2;
      rg[i].second -= PI * 2;
    }
  }
  sort(rg + 1, rg + n + 1);
  for (int i = n + 1; i <= n * 2; ++i)
    rg[i] = make_pair(rg[i - n].first + PI * 2, rg[i - n].second + PI * 2);
  static double que[N * 2];
  static int sz[N * 2];
  int ql = 0, qr = 0, tot = 0;
  for (int i = n * 2; i; --i) {
    double l = rg[i].first, r = rg[i].second;
    int cur = 1;
    while (qr > ql && que[qr - 1] > r)
      cur += sz[--qr];
    sz[qr] = cur;
    que[qr] = r;
    ++tot;
    ++qr;
    while (rg[i + tot - 1].first > que[ql]) {
      --tot;
      if (--sz[ql] == 0) ++ql;
    }
    jmp[i][0] = i + tot;
  }
  jmp[n * 2 + 1][0] = n * 2 + 1;
  for (int i = n * 2 + 1; i; --i)
    for (int j = 1; j < L; ++j)
      jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
  for (int i = 1; i <= n; ++i) {
    int cur = 0;
    int k = i;
    for (int j = L - 1; j >= 0; --j) {
      if (jmp[k][j] - i < n) {
        k = jmp[k][j];
        cur |= 1 << j;
      }
    }
    if (cur + 1 <= m)
      return true;
  }
   return false;
}

int main() {
  scanf("%d%d", &n, &m);
  double l = 0, r = 1e9;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i].real(x);
    p[i].imag(y);
    r = min(r, len[i] = abs(p[i]));
    argp[i] = arg(p[i]);
  }
  while (r - l > EPS) {
    double mid = (l + r) / 2;
    if (pred(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf\n", l);
  return 0;
}