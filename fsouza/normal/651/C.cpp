#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);

  map<int, int> atx, aty;
  map<pair<int, int>, int> atpos;
  
  lint result = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    result += atx[x]++;
    result += aty[y]++;
    result -= atpos[{x, y}]++;
  }
  cout << result << "\n";
  
  return 0;
}