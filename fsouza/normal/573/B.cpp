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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool possible(const vector<int> &height, int dist) {
  int n = height.size();
  vector<pair<int, int>> ranges;
  for (int x = -1; x <= (int)height.size(); ++x) {
    int y;
    if (0 <= x && x < (int)height.size()) y = height[x];
    else y = 0;

    int withdistx = dist - 1 - y;
    if (withdistx >= 0) {
      pair<int, int> range = make_pair(max(x - withdistx, 0),
				       min(x + withdistx, (int)height.size()-1));
      if (range.first <= range.second) {
	ranges.push_back(range);
      }
    }
  }

  sort(ranges.begin(), ranges.end());

  int manyimpossible = 0;
  int last = -1;
  for (pair<int, int> range : ranges) {
    manyimpossible += max(0, range.second - max(last+1, range.first) + 1);
    last = max(last, range.second);
  }

  return manyimpossible < n;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> height(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &height[i]);

  int left = 0, right = n;
  while (left < right) {
    int m = left + (right-left+1)/2;
    if (possible(height, m)) left = m;
    else right = m-1;
  }

  printf("%d\n", left);

  return 0;
}