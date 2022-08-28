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

const int N = 1000010;

int n, w;
int a[N];
ll ans[N];

int ql, qr;
int q[N], c[N];

void clr() {
  ql = 1;
  qr = 0;
}

void push(int x) {
  int cnt = 1;
  while (ql <= qr && q[qr] <= x) cnt += c[qr--];
  ++qr;
  q[qr] = x;
  c[qr] = cnt;
}

void pop() { if (!--c[ql]) ++ql; }

int main() {
  scanf("%d%d", &n, &w);
  while (n--) {
    int l;
    scanf("%d", &l);
    for (int i = 1; i <= l; ++i)
      scanf("%d", &a[i]);
    if (l * 2 <= w) {
      int cur = 0;
      for (int i = 1; i <= l; ++i) {
        cur = max(cur, a[i]);
        ans[i - 1] -= cur; ans[i] += cur;
      }
      ans[l] -= cur; ans[w - l] += cur;
      cur = 0;
      for (int i = l; i; --i) {
        cur = max(cur, a[i]);
        ans[w - (l - i + 1)] -= cur; ans[w - (l - i + 1) + 1] += cur;
      }
    } else {
      clr();
      for (int i = 1; i <= w; ++i) {
        if (i <= l) push(a[i]);
        if (w - i + 1 < l) pop();
        int th = q[ql];
        if (i > l || w - i >= l) th = max(th, 0);
        ans[i - 1] -= th; ans[i] += th;
      }
    }
  }
  for (int i = w; i; --i) ans[i] += ans[i + 1];
  for (int i = 1; i <= w; ++i) printf("%lld ", ans[i]);
  return 0;
}