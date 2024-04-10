#include <cstdio>
#include <ctime>

#include <algorithm>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2000010;

int k[N], pool[N], mp[N];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, q;
  scanf("%d%d", &n, &q);
  q += n;
  for (int i = 1; i <= q; ++i) scanf("%d", &k[i]);
  int rmv = 0;
  for (int i = 1; i <= q; ++i) if (k[i] > 0) ++pool[k[i]]; else ++rmv;
  for (int i = 1; i <= n; ++i) pool[i] += pool[i - 1];
  if (pool[n] == rmv) {
    puts("0");
    return 0;
  }
  int tot = pool[n];
  for (int& x : k)
    if (x > 0) {
      int u = x;
      x = pool[x];
      mp[pool[u]--] = u;
    }
  int l = 0, r = tot, sz = q;
  while (l < r) {
    int mid = (l + r) >> 1;
    int sumL = 0;
    int kL = 0, kR = N - 1;
    for (int i = 1; i <= sz; ++i) {
      int v = k[i];
      if (v > 0) {
        if (v <= mid) {
          pool[kL++] = v;
          ++sumL;
        } else pool[kR--] = v;
      } else {
        if (-v <= sumL) {
          --sumL;
          pool[kL++] = v;
        } else
          pool[kR--] = v + sumL;
      }
    }
    if (sumL) {
      for (int i = 0; i < kL; ++i)
        k[i + 1] = pool[i];
      sz = kL;
      r = mid;
    } else {
      for (int i = 0; i < N - 1 - kR; ++i)
        k[i + 1] = pool[N - 1 - i];
      sz = N - 1 - kR;
      l = mid + 1;
    }
  }
  printf("%d\n", mp[l]);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}