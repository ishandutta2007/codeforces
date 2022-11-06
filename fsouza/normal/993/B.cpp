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

vector<pair<int, int>> read(int n) {
  vector<pair<int, int>> result(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &result[i].first, &result[i].second);
    if (result[i].first > result[i].second)
      swap(result[i].first, result[i].second);
  }
  return result;
}

int get_common(pair<int, int> a, pair<int, int> b) {
  bool a_first_common = b.first == a.first || b.second == a.first;
  bool a_second_common = b.first == a.second || b.second == a.second;
  if (a_first_common && a_second_common)
    return -1;
  if (a_first_common) return a.first;
  if (a_second_common) return a.second;
  return -2;
}

bool possible_pair_pair(pair<int, int> a, pair<int, int> b) {
  return get_common(a, b) >= 0;
}

bool solve2(const vector<pair<int, int>> &p1s,
            const vector<pair<int, int>> &p2s) {
  int n = p1s.size();
  int m = p2s.size();

  for (int i = 0; i < n; ++i) {
    vector<bool> possible_first(10, false);

    for (int j = 0; j < m; ++j) {
      if (possible_pair_pair(p1s[i], p2s[j])) {
        int common = get_common(p1s[i], p2s[j]);
        possible_first[common] = true;
      }
    }

    int nposs = count(possible_first.begin(), possible_first.end(), true);
    if (nposs >= 2) {
      return false;
    }
  }

  return true;
}

int solve(const vector<pair<int, int>> &p1s,
          const vector<pair<int, int>> &p2s) {
  int n = p1s.size();
  int m = p2s.size();
  vector<bool> possible_me(10, false);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (possible_pair_pair(p1s[i], p2s[j])) {
        int common = get_common(p1s[i], p2s[j]);
        possible_me[common] = true;
      }
    }
  if (count(possible_me.begin(), possible_me.end(), true) == 1) {
    int result =
      find(possible_me.begin(), possible_me.end(), true) - possible_me.begin();
    return result;
  }

  if (solve2(p1s, p2s) && solve2(p2s, p1s))
    return 0;

  return -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> p1s = read(n);
  vector<pair<int, int>> p2s = read(m);
  printf("%d\n", solve(p1s, p2s));
  return 0;
}