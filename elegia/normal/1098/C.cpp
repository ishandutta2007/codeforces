#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <deque>
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

const int N = 100010;

int n;
int dep[N], deg[N];
deque<int> exist[N];
ll s;

bool pred(int x) {
  ll res = 1;
  int cur = 1, rest = x;
  dep[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dep[i] = dep[cur] + 1;
    res += dep[i];
    if (--rest == 0) {
      ++cur;
      rest = x;
    }
  }
  return res <= s;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%lld", &n, &s);
  if (s > n * (n + 1LL) / 2 || s < n * 2 - 1) {
    puts("No");
    return 0;
  }
  int l = 1, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pred(mid))
      r = mid;
    else
      l = mid + 1;
  }
  ll sub = n * (n + 1LL) / 2 - s;
  exist[1].push_back(1);
  int cur = 1, ptr = 1;
  puts("Yes");
  for (int i = 2; i <= n; ++i) {
    ++cur;
    while (exist[ptr].empty() || (cur - ptr - 1LL) * (n - i + 1) > sub)
      ++ptr;
    printf("%d ", exist[ptr].front());
    fflush(stdout);
    if (++deg[exist[ptr].front()] == l)
      exist[ptr].pop_front();
    sub -= (cur - ptr - 1LL) * (n - i + 1);
    cur = ptr + 1;
    exist[cur].push_back(i);
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}