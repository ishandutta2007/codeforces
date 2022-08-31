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

const int N = 110;

int n;
char s[N];
int cnt[241];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    bool f = s[i] == '1';
    for (int j = 0; j <= 240; ++j) {
      if (j >= b && j % a == b % a)
        f = !f;
      cnt[j] += f;
    }
  }
  printf("%d\n", *max_element(begin(cnt), end(cnt)));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}