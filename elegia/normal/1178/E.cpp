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

char s[N];
bool vis[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s", s + 1);
  int n = strlen(s + 1);
  {
    int i = 1, j = n;
    for (; i + 1 < j - 1; i += 2, j -= 2) {
#define CHK(I, J) if (s[I] == s[J]) { vis[I] = vis[J] = true; continue; }
      CHK(i, j);
      CHK(i + 1, j);
      CHK(i, j - 1);
      CHK(i + 1, j - 1);
    }
    vis[i] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (vis[i])
      putchar(s[i]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}