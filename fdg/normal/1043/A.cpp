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
  int n, sum = 0, a, mx = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    mx = max(mx, a);
    sum += a;
  }
  for (;n * mx - sum <= sum; ++mx);
  cout << mx << endl;
  return 0;
}