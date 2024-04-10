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
  vector<int> values(n);
  for (int i = 0; i < n; ++i) scanf("%d", &values[i]);

  vector<int> diff = values;
  sort(diff.begin(), diff.end());
  diff.resize(unique(diff.begin(), diff.end())-diff.begin());

  unordered_map<int, int> many;
  for (int v : values) ++many[v];

  int result = 0;
  
  vector<int> seq;
  for (int j = 0; j < (int)diff.size(); ++j) {
    int v0 = diff[j];
    if (many[v0] <= 0) continue;
    --many[v0];
    for (int k = 0; k < (int)diff.size(); ++k) {
      int v1 = diff[k];
      if (many[v1] <= 0) continue;
      --many[v1];

      int res = 2;
      int a = v0, b = v1;
      seq.clear();
      while (many[a+b] > 0) {
	--many[a+b];
	seq.push_back(a+b);
	a = a+b;
	swap(a, b);
	++res;
      }
      result = max(result, res);

      for (int v : seq) ++many[v];
      ++many[v1];
    }
    ++many[v0];
  }

  printf("%d\n", result);
  
  return 0;
}