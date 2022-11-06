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

// RULD
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

array<bool, 4> parse(char c) {
  switch (c) {      // R     U      L      D
  case '+': return {true, true, true, true};
  case '-': return {true, false, true, false};
  case '|': return {false, true, false, true};
  case '^': return {false, true, false, false};
  case '>': return {true, false, false, false};
  case '<': return {false, false, true, false};
  case 'v': return {false, false, false, true};
  case 'L': return {true, true, false, true};
  case 'R': return {false, true, true, true};
  case 'U': return {true, false, true, true};
  case 'D': return {true, true, true, false};
  case '*': return {false, false, false, false};
  default: assert(0);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> table(n, string(m, ' '));
  for (string &s : table) scanf("%s", &s[0]);
  vector<vector<array<bool, 4>>> can(n, vector<array<bool, 4>>(m));

  int sy, sx, ey, ex;
  scanf("%d %d %d %d", &sy, &sx, &ey, &ex), --sy, --sx, --ey, --ex;

  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      can[y][x] = parse(table[y][x]);

  struct state {
    int y, x, rot;
  };
  auto id = [n, m](state &st) {
    return st.rot + 4*(st.x + m*st.y);
  };

  queue<state> q;
  vector<int> mindist(n*m*4, INT_MAX/2);
  state start = {sy, sx, 0};
  q.push(start);
  mindist[id(start)] = 0;
  while (!q.empty()) {
    state st = q.front(); q.pop();
    {
      state st2 = {st.y, st.x, (st.rot+1)%4};
      if (mindist[id(st2)] > mindist[id(st)]+1) {
	mindist[id(st2)] = mindist[id(st)]+1;
	q.push(st2);
      }
    }
    for (int d = 0; d < 4; ++d) {
      int y2 = st.y + dy[d], x2 = st.x + dx[d];
      if (0 <= y2 && y2 < n && 0 <= x2 && x2 < m) {
	state st2 = {y2, x2, st.rot};
	if (can[st.y][st.x][(d + st.rot)%4] && can[y2][x2][(d + st.rot + 2)%4]) {
	  if (mindist[id(st2)] > mindist[id(st)]+1) {
	    mindist[id(st2)] = mindist[id(st)]+1;
	    q.push(st2);
	  }
	}
      }
    }
  }

  int result = INT_MAX/2;
  for (int d = 0; d < 4; ++d) {
    state st{ey, ex, d};
    result = min(result, mindist[id(st)]);
  }

  if (result == INT_MAX/2) printf("-1\n");
  else printf("%d\n", result);

  return 0;
}