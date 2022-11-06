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
  int nodd = 0, minodd = INT_MAX;
  lint sum = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    sum += v;
    if (v%2 == 1) {
      ++nodd;
      minodd = min(minodd, v);
    }
  }
  if (nodd%2 == 1) sum -= minodd;

  cout << sum << "\n";
  
  return 0;
}