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
  int n, nk, office_pos;
  scanf("%d %d %d", &n, &nk, &office_pos);
  vector<int> people(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &people[i]);
  sort(people.begin(), people.end());
  vector<int> keys(nk);
  for (int i = 0; i < nk; ++i)
    scanf("%d", &keys[i]);
  sort(keys.begin(), keys.end());

  int min_time = 0;
  int max_time = 2 * (max({people.back(), keys.back(), office_pos}) -
                      min({people.front(), keys.front(), office_pos}));

  vector<vector<bool>> possible(n + 1, vector<bool>(nk + 1));

  while (min_time < max_time) {
    int time = min_time + (max_time - min_time) / 2;
    for (int i = n; i >= 0; --i)
      for (int j = nk; j >= 0; --j) {
        bool res;
        if (i == n) res = true;
        else if (j == nk) res = false;
        else {
          res = possible[i][j + 1];
          if (abs(people[i] - keys[j]) + abs(keys[j] - office_pos) <= time)
            res |= possible[i + 1][j + 1];
        }
        possible[i][j] = res;
      }
    if (possible[0][0]) max_time = time;
    else min_time = time + 1;
  }

  printf("%d\n", min_time);

  return 0;
}