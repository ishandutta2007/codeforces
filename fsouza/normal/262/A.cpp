#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int n, k;

  cin >> n >> k;

  int ret = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    int nl = 0;
    while (v) {
      int d = v%10;
      if (d == 4 || d == 7)
        nl++;
      v /= 10;
    }
    if (nl <= k)
      ret++;
  }

  cout << ret << endl;

  return 0;
}