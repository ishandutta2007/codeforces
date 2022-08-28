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

const int N = 100010;

int n, k;
char s[N];

int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  int min0 = n + 1, max0 = 0, min1 = n + 1, max1 = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      min0 = min(min0, i);
      max0 = max(max0, i);
    }
    if (s[i] == '1') {
      min1 = min(min1, i);
      max1 = max(max1, i);
    }
  }
  if (max0 == 0 || max1 == 0) {
    puts("tokitsukaze");
    return 0;
  }
  if (max0 - min0 + 1 <= k || max1 - min1 + 1 <= k) {
    puts("tokitsukaze");
    return 0;
  }
  if (max0 - min0 - 1 >= k || max1 - min1 - 1 >= k) {
    puts("once again");
    return 0;
  }
  bool f = false;
  int l0 = find(s + k + 1, s + n + 1, '0') - s, l1 = find(s + k + 1, s + n + 1, '1') - s;
  if (max0 - l0 + 1 > k || max1 - l1 + 1 > k)
    f = true;
  int r0 = n - k, r1 = n - k;
  while (s[r0] != '0') --r0;
  while (s[r1] != '1') --r1;
  if (r0 - min0 + 1 > k || r1 - min1 + 1 > k)
    f = true;
  if (f)
    puts("once again");
  else
    puts("quailty");
  return 0;
}