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

const int N = 300010;

int n;
int p[N], pos[N];
vector<pair<int, int>> ans;

void ope(int x, int y) {
  ans.emplace_back(x, y);
  swap(p[x], p[y]);
  swap(pos[p[x]], pos[p[y]]);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 2; i < n; ++i) {
    int x = pos[i];
    if (x <= n / 2) {
      ope(x, n);
      if (i <= n / 2) {
        ope(i, n);
      } else {
        ope(1, n);
        ope(1, i);
      }
    } else {
      ope(1, x);
      if (i <= n / 2) {
        ope(1, n);
        ope(i, n);
      } else {
        ope(1, i);
      }
    }
  }
  if (p[1] != 1)
    ope(1, n);
    printf("%lu\n", ans.size());
  for (const auto& pr : ans)
    printf("%d %d\n", pr.first ,pr.second);


#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}