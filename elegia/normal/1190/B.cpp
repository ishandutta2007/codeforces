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

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a, a + n);
  if (count(a, a + n, 0) == n) {
    puts("cslnb");
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i < n; ++i)
    cnt += a[i - 1] == a[i];
  if (cnt > 1) {
    puts("cslnb");
    return 0;
  }
  bool f = false;
  if (cnt == 1) {
    for (int i = 0; i < n - 1; ++i)
      if (a[i] == a[i + 1]) {
        if ((i == 0 && a[i] > 0) || a[i] - 1 > a[i - 1]) {
          f = true;
          --a[i];
        } else {
          puts("cslnb");
          return 0;
        }
      }
  }
  for (int i = 0; i < n; ++i)
    f ^= (a[i] & 1) ^ (i & 1);
  if (!f)
    puts("cslnb");
  else
    puts("sjfnb");
  return 0;
}