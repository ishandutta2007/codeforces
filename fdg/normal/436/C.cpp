#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[1002][11][11];
int dist[1002], what[1002], w, n, m;

int get(int a, int b) {
  int ret = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (f[a][i][j] != f[b][i][j]) {
        ret += w;
        if (ret >= dist[b])
          return ret + 1;
      }
    }
  return ret;
}

int main() {
  int k;
  scanf("%d%d%d%d\n", &n, &m, &k, &w);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j)
      gets(f[i][j]);
    dist[i] = n * m, what[i] = 0;
  }
  bool used[1002] = {0};
  int res = 0;
  vector<pair<int, int> > ans;
  for (int t = 0; t < k; ++t) {
    int ind = -1;
    for (int i = 0; i < k; ++i) {
      if (!used[i] && (ind == -1 || dist[i] < dist[ind]))
        ind = i;
    }
    used[ind] = true;
    res += dist[ind];
    ans.push_back(make_pair(ind + 1, what[ind]));
    for (int j = 0; j < k; ++j) {
      if (!used[j]) {
        int d = get(ind, j);
        if (dist[j] > d) {
          dist[j] = d;
          what[j] = ind + 1;
        }
      }
    }
  }
  printf("%d\n", res);
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}