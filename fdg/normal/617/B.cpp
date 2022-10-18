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
  long long ans = 1;
  int n, a = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      if (a > 0) ans *= a;
      a = 1;
    } else {
      if (a > 0) ++a;
    }
  }
  cout << (a == -1 ? 0 : ans) << endl;
  return 0;
}