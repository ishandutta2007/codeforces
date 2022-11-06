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

#define MAXN 200000

using namespace std;

typedef long long lint;

int link[MAXN], mark[MAXN];
vector<vector<int>> cycles;
stack<int> st;

void dfs(int v) {
  mark[v] = 1;
  st.push(v);

  int u = link[v];
  if (mark[u] == 0) dfs(u);
  else if (mark[u] == 2) { }
  else {
    vector<int> cycle;
    while (st.top() != u) {
      cycle.push_back(st.top());
      st.pop();
    }
    cycle.push_back(u);
    st.pop();
    cycles.push_back(move(cycle));
  }

  if (!st.empty() && st.top() == v) st.pop();
  mark[v] = 2;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &link[i]), --link[i];
    mark[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    if (!mark[i]) {
      dfs(i);
    }
  }

  int goodguy = -1;
  for (vector<int> &cycle : cycles)
    if (cycle.size() == 1) {
      goodguy = cycle[0];
      break;
    }

  int result = 0;
  for (vector<int> &cycle : cycles)
    if (cycle.size() == 1) {
      if (cycle[0] != goodguy) {
	++result;
	link[cycle[0]] = goodguy;
      }
    } else {
      if (goodguy == -1) {
	++result;
	link[cycle[0]] = cycle[0];
	goodguy = cycle[0];
      } else {
	++result;
	link[cycle[0]] = goodguy;
      }
    }

  printf("%d\n", result);
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", link[i]+1);
  }
  printf("\n");

  return 0;
}