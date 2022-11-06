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

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  lint result = 0;
  
  for (int i = 0, j = n-1; i < j && k > 0; i++, j--, k--) {
    int mid = j-i-1;
    result += 2*mid + 1;
  }

  cout << result << "\n";
  
  return 0;
}