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
  ios::sync_with_stdio(false);
  int n, x, mx = -1;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x > mx + 1) {
      cout << i << endl;
      return 0;
    }
    mx = max(mx, x);
  }

  cout << -1 << endl;
  return 0;
}