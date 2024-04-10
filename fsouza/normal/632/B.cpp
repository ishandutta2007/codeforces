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
  for (int &v: values) scanf("%d", &v);
  string who(n, ' ');
  scanf("%s", &who[0]);

  lint score = 0;
  for (int i = 0; i < n; ++i)
    if (who[i] == 'B')
      score += values[i];

  lint best = 0;
  {
    lint delta = 0;
    for (int i = 0; i < n; ++i) {
      if (who[i] == 'A') delta += values[i];
      else delta -= values[i];
      best = max(best, delta);
    }
  }
  {
    lint delta = 0;
    for (int i = n-1; i >= 0; --i) {
      if (who[i] == 'A') delta += values[i];
      else delta -= values[i];
      best = max(best, delta);
    }
  }

  cout << score + best << "\n";

  return 0;
}