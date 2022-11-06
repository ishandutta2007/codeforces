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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;

int main() {
  int n;
  scanf("%d", &n);
  int tot0 = 0, tot1 = 0;
  ulint result = 1;
  int n0 = 0, n1 = 0;

  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    if (v == 0) {
      ++tot0;
      ++n0;
      n1 = 0;
    } else {
      ++tot1;
      if (n0 > 0) {
	if (tot1 > 1) {
	  result *= (n0+1);
	}
      }
      n0 = 0;
      ++n1;
    }
  }
  if (tot1 == 0) result = 0;

  cout << result << endl;
  
  return 0;
}