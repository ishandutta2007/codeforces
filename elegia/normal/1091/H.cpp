#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int n, pc;
int pr[N], sg[N];
bitset<N> tr[100];
bool vis[N];
bitset<N> goods;

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, f;
  scanf("%d%d", &n, &f);
  for (int x = 2; x < N; ++x) {
    if (!vis[x]) {
      pr[++pc] = x;
      goods.set(x);
      for (int j = x + x; j < N; j += x)
        vis[j] = true;
    }
  }
  for (int i = 1; i <= pc; ++i)
    for (int j = i; pr[i] * (ll)pr[j] < N; ++j) {
      goods.set(pr[i] * pr[j]);
    }
  goods.set(f, false);
  tr[0] = goods;
  for (int i = 1; i < N; ++i) {
    while (tr[sg[i]][i])
      ++sg[i];
    tr[sg[i]] |= goods << i;
  }
  int res = 0;
  while (n--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    res ^= sg[b - a - 1] ^ sg[c - b - 1];
  }
  if (res)
    puts("Alice\nBob");
  else
    puts("Bob\nAlice");

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}