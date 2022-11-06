#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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
  vector<int> v(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());

  lint result = 0;
  int last = numeric_limits<int>::max();
  
  for (int i = n-1; i >= 0; --i) {
    int can = min(v[i], last-1);
    if (can > 0) {
      result += can;
      last = can;
    }
  }

  cout << result << "\n";
  
  return 0;
}