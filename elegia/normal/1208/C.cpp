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

int base[4][4] = {
{8, 9, 1, 13},
{3, 12, 7, 5},
{0, 2, 4, 11},
{6, 10, 15, 14}
};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d ", (((i >> 2) * (n >> 2) + (j >> 2)) << 4) | base[i & 3][j & 3]);
    putchar('\n');
  }
  return 0;
}