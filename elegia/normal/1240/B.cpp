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
int a[N], l[N], r[N];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  fill(l + 1, l + n + 1, n + 1);
  fill(r + 1, r + n + 1, 0);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (l[a[i]] == n + 1) {
      l[a[i]] = i;
      ++cnt;
    }
    r[a[i]] = i;
  }
  int cur = 0, ans = 0, curr = 0;
  for (int i = 1; i <= n; ++i)
    if (l[i] != n + 1)
      if (l[i] > curr) {
        ++cur;
        curr = r[i];
      } else {
        ans = max(ans, cur);
        cur = 1;
        curr = r[i];
      }
  ans = max(ans, cur);
  printf("%d\n", cnt - ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}