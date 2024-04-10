#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


#define mod (1000000007)
const int MaxN = 2100;


inline long long add (long long a, long long b) {
  long long c = a + b;
  if (c >= mod) {
    c -= mod;
  }
  return c;
}


inline long long mul (long long a, long long b) {
  return (a * b) % mod;
}


int n, m;
long long D[MaxN][MaxN], D2[MaxN][MaxN];


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 2; i <= m; i++) {
    D[0][i] = 1;
    D2[0][i] = 1;
  }
  for (int i = 1; i < n; i++) {
    long long sum = 0;
    for (int j = 2; j <= m; j++) {
      sum = add(sum, D[i - 1][j]), D[i][j] = add(D[i][j - 1],sum);
    }
    for (int j = 2; j <= m; j++) {
      D[i][j] = add(D[i][j], 1), D2[i][j] = add(D[i][j], mod - D[i - 1][j]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= m; j++) {
      ans = add(ans, mul(m - j + 1, mul(D[i][j], D2[n - i - 1][j])));
    }
  }
  printf("%I64d\n", ans);
  return 0;
}