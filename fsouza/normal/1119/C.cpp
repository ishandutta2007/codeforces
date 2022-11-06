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

vector<vector<int>> read(int n, int m) {
  vector<vector<int>> table(n, vector<int>(m, 0));
  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      scanf("%d", &table[y][x]);
  return table;
}

void answer_yes() {
  printf("Yes\n");
  exit(0);
}

void answer_no() {
  printf("No\n");
  exit(0);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> mat0 = read(n, m);
  vector<vector<int>> mat1 = read(n, m);
  set<int> active;
  for (int y = 0; y < n; ++y) {
    int row_changed = 0;
    for (int x = 0; x < m; ++x) {
      if (mat0[y][x] == mat1[y][x]) continue;
      ++row_changed;
      if (active.find(x) == active.end()) active.insert(x);
      else active.erase(x);
    }
    if (row_changed % 2 == 1) {
      answer_no();
    }
  }
  if (!active.empty()) answer_no();
  answer_yes();

  return 0;
}