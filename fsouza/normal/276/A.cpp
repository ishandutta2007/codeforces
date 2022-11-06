#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>

typedef long long lint;

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int ret = INT_MIN;

  for (int i = 0; i < n; i++) {
    int f, t;
    cin >> f >> t;
    ret = max(ret, f - max(t-k, 0));
  }

  cout << ret << endl;

  return 0;
}