#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);
  vector<int> next_use(n);
  map<int, int> last_appearance;
  for (int i = n-1; i >= 0; --i) {
    if (last_appearance.find(values[i]) == last_appearance.end())
      next_use[i] = n;
    else
      next_use[i] = last_appearance[values[i]];
    last_appearance[values[i]] = i;
  }
  set<int> active;
  priority_queue<pair<int, int>> next_use_active;
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (active.find(values[i]) == active.end()) {
      if ((int)active.size() == k) {
        pair<int, int> throw_away;
        do {
          throw_away = next_use_active.top();
          next_use_active.pop();
        } while (active.find(throw_away.second) == active.end());
        active.erase(throw_away.second);
      }
      ++result;
      active.insert(values[i]);
    }
    next_use_active.push(make_pair(next_use[i], values[i]));
  }

  printf("%d\n", result);

  return 0;
}