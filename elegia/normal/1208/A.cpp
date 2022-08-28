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

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    n %= 3;
    if (n == 0) printf("%d\n", a);
    if (n == 1) printf("%d\n", b);
    if (n == 2) printf("%d\n", a ^ b);
  }
  return 0;
}