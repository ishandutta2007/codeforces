#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100010;

int n;
char s[N], mx[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s", s + 1);
  n = strlen(s + 1);
  stack<char> stk;
  mx[n + 1] = 'z' + 1;
  for (int i = n; i; --i)
    mx[i] = min(mx[i + 1], s[i]);
  for (int i = 1; i <= n; ++i) {
    stk.push(s[i]);
    while (!stk.empty() && stk.top() <= mx[i + 1]) {
      putchar(stk.top());
      stk.pop();
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}