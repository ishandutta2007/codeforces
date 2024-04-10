#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

vector<vector<int>> get_dists(const vector<string> &board, char belong) {
  int n = board.size(), m = board[0].size();
  vector<vector<int>> mindist(n, vector<int>(m, INT_MAX));
  deque<pair<int, int>> q;
  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      if (board[y][x] == belong) {
	q.push_back({y, x});
	mindist[y][x] = 0;
      }

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front(); q.pop_front();
    for (int d = 0; d < 4; ++d) {
      int y2 = y + dy[d], x2 = x + dx[d];
      if (0 <= y2 && y2 < n && 0 <= x2 && x2 < m && !(board[y2][x2] == '#')) {
	int cost = (board[y2][x2] == '.');
	if (mindist[y2][x2] > mindist[y][x] + cost) {
	  mindist[y2][x2] = mindist[y][x] + cost;
	  if (cost == 1) q.push_back({y2, x2});
	  else q.push_front({y2, x2});
	}
      }
    }
  }

  return mindist;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> board(n, string(m, ' '));
  for (int i = 0; i < n; ++i) scanf(" %s", &board[i][0]);
  
  vector<vector<int>> dists[3];
  for (int i = 0; i < 3; ++i)
    dists[i] = get_dists(board, '0'+(i+1));

  int result = INT_MAX;
  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      if (board[y][x] != '#') {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
	  int d = dists[i][y][x];
	  if (d == INT_MAX) res = INT_MAX;
	  else if (res != INT_MAX) res += d;
	}
	if (board[y][x] == '.' && res != INT_MAX) res -= 2;
	result = min(result, res);
      }

  if (result == INT_MAX) printf("-1\n");
  else printf("%d\n", result);
  
  return 0;
}