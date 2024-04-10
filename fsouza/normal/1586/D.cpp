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
  int n;
  scanf("%d", &n);
  vector<array<int, 2>> answers(n);

  vector<vector<int>> adj(n);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 2; ++j) {
      vector<int> query;
      if (j == 0) {
        query = vector<int>(n, 1);
        query[i] = 2;
      } else {
        query = vector<int>(n, 2);
        query[i] = 1;
      }
      printf("?");
      for (int v : query) printf(" %d", v);
      printf("\n");
      fflush(stdout);

      scanf("%d", &answers[i][j]), --answers[i][j];

      int res = answers[i][j];
      if (res != -1 && res != i) {
        adj[i].push_back(res);
        adj[res].push_back(i);
      }
    }

  for (int i = 0; i < n; ++i) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
  }

  int start = -1;
  for (int i = 0; i < n; ++i)
    if (adj[i].size() == 1 && answers[i][1] == -1) {
      start = i;
      break;
    }
  assert(start != -1);

  vector<int> perm(n);
  int prev_pos = -1;
  int cur_pos = start;
  for (int value = 0; value < n; ++value) {
    perm[cur_pos] = value;

    if (value + 1 < n) {
      if (adj[cur_pos].size() == 1) {
        prev_pos = cur_pos;
        cur_pos = adj[cur_pos][0];
      } else {
        assert(adj[cur_pos].size() == 2);
        int new_cur_pos = adj[cur_pos][0] + adj[cur_pos][1] - prev_pos;
        prev_pos = cur_pos;
        cur_pos = new_cur_pos;
      }
    }
  }

  printf("!");
  for (int v : perm) printf(" %d", v + 1);
  printf("\n");
  fflush(stdout);

  return 0;
}