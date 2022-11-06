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
  int n;
  scanf("%d", &n);
  vector<int> v1, v2;
  for (vector<int> &v : {ref(v1), ref(v2)}) {
    v = vector<int>(n);
    for (int &val : v) scanf("%d", &val);
    v.erase(find(v.begin(), v.end(), 0));
    auto it = min_element(v.begin(), v.end());
    rotate(v.begin(), it, v.end());
  }

  if (v1 == v2) printf("YES\n");
  else printf("NO\n");

  return 0;
}