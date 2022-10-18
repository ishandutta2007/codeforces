#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long val[1000006];
int pdiv[1000005];

int main() {
  for (int i = 2; i <= 1000000; ++i)
    if (pdiv[i] == 0) {
      for (int j = i; j <= 1000000; j += i) {
        if (pdiv[j] == 0) pdiv[j] = i;
      }
    }

  int n, p;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p);
    scanf("%lld", &val[p]);
  }
  long long k;
  scanf("%lld", &k);
  for (int i = 0; k > 0 && i < 20; ++i) {
    for (int j = 2; j < 1000000; ++j) {
      if (val[j] > 0) {
        --val[j];
        long long cur = j - 1;
        while (cur > 1) {
          val[pdiv[cur]]++;
          cur /= pdiv[cur];
        }
      }
    }
    --k;
  }

  for (int j = 999999; j >= 2; --j) {
    long long sub = min(k, val[j]);
    if (val[j] > 0) {
      val[j] -= sub;
      long long cur = j - 1;
      while (cur > 1) {
        val[pdiv[cur]] += sub;
        cur /= pdiv[cur];
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i <= 1000000; ++i) {
    if (val[i] > 0) ++cnt;
  }
  printf("%d\n", cnt);
  for (int i = 2; i <= 1000000; ++i)
    if (val[i] > 0)
      printf("%d %lld\n", i, val[i]);
  return 0;
}