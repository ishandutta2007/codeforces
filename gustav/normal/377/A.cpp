#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

#define MAX 505

int n, m, k;
char maze[MAX][MAX];
int bio[MAX][MAX];

queue< pair< int, int > > q;

int main(void)
{
  scanf("%d%d%d", &n, &m, &k);
  REP(i, n) scanf("%s", maze[i]);

  int s = 0;
  REP(i, n) REP(j, m) 
    if (maze[i][j] == '.' && !s++)
      q.push({i, j});
 
  int taken = 0;
  while (!q.empty() && taken < s - k) {
    auto c = q.front(); q.pop();
    int x = c.first;
    int y = c.second;

    if (bio[x][y]) continue;

    bio[x][y] = 1;
    ++taken;

    REP(d, 4) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx == n) continue;
      if (ny < 0 || ny == m) continue;
      if (maze[nx][ny] != '.') continue;
      if (bio[nx][ny]) continue;

      q.push({nx, ny});
    }
  }

  REP(i, n) REP(j, m)
    if (!bio[i][j] && maze[i][j] == '.')
      maze[i][j] = 'X';

  REP(i, n) puts(maze[i]);

  return 0;
}