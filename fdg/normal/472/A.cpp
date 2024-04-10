#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool pr[1000002];

int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (!pr[i])
      for (int j = i + i; j <= n; j += i)
        pr[j] = true;
  }
  for (int i = 2; i < n; ++i) {
    if (pr[i] && pr[n - i] && n - i > 1) {
      printf("%d %d\n", i, n - i);
      return 0;
    }
  }
  return 0;
}