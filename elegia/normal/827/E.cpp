#include <cstdio>
#include <cmath>
#include <cassert>
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
#include <complex>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int L = 21;

const int P = 998244353, R = 3;

int a[1 << L], b[1 << L];
bool res[1 << L], ans[1 << L];


void ntt(int* arr, int lgn, bool inv);
int mpow(int a, int k);
void exGcd(int a, int b, int& x, int& y);
int rev(int a, int p = P);
char s[1 << L];

int main() {
#ifdef CAI_WEI_HAN
  freopen("test.in", "r", stdin);
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s", &n, s + 1);
    int l = 1;
    while ((1 << l) <= n)
      ++l;
    ++l;
    memset(a, 0, sizeof(int) << l);
    memset(b, 0, sizeof(int) << l);
    memset(res, 0, sizeof(bool) << l);
    for (int i = 1; i <= n; ++i) {
      if (s[i] == 'V')
        a[i - 1] = 1;
      else if (s[i] == 'K')
        b[n - i] = 1;
    }
    ntt(a, l, false);
    ntt(b, l, false);
    for (int i = 0; i < 1 << l; ++i)
      a[i] = a[i] * (ll)b[i] % P;
    ntt(a, l, true);
    for (int i = 0; i < 1 << l; ++i)
      if (a[i]) {
        int delt = i - n + 1;
        res[abs(delt)] = true;
      }
    for (int i = 1; i <= n; ++i) {
      ans[i] = true;
      for (int j = i; j < n; j += i)
        if (res[j]) {
          //LOG("OCCUR %d\n", j);
          ans[i] = false;
          break;
        }
    }
    printf("%lu\n", count(ans + 1, ans + n + 1, true));
    for (int i = 1; i <= n; ++i)
      if (ans[i])
        printf("%d ", i);
    putchar('\n');
  }
}



int mpow(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = (ll)ret * a % P;
    a = a * (ll)a % P;
    k >>= 1;
  }
  return ret;
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

int rev(int a, int p) {
  int x, y;
  exGcd(a, p, x, y);
  if (x < 0)
    x += p;
  return x;
}

void ntt(int* arr, int lgn, bool inv) {
  static int rev[1 << L];
  int n = 1 << lgn;
  for (int i = 1; i < n; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lgn - 1));
  for (int i = 0; i < n; ++i)
    if (i < rev[i])
      swap(arr[i], arr[rev[i]]);
  int rt = inv ? ::rev(R) : R;
  for (int i = 0; i < lgn; ++i) {
    int t = 1 << i, g = mpow(rt, (P - 1) >> (i + 1));
    for (int j = 0; j < n; j += t << 1) {
      int w = 1;
      for (int k = j; k < j + t; ++k) {
        int a0 = arr[k], a1 = arr[k + t];
        arr[k] = (a0 + a1 * (ll)w) % P;
        arr[k + t] = (a0 + a1 * (ll)(P - w)) % P;
        w = w * (ll)g % P;
      }
    }
  }
  if (inv) {
    int rm = ::rev(n);
    for (int i = 0; i < n; ++i)
      arr[i] = arr[i] * (ll)rm % P;
  }
}