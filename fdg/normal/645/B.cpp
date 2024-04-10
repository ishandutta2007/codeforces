#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  k = min(k, n / 2);
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += 2 * (n - 2 * (i + 1)) + 1;
  }
  cout << ans << endl;
  return 0;
}