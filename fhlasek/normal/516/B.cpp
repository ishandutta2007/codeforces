/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 2222
int N, M;
char m[MAXN][MAXN];

int deg[MAXN][MAXN];
queue<int> qx, qy;

bool is_empty(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < M && m[x][y] == '.';
}

bool solve() {
  REP(i, N) REP(j, M) if (is_empty(i, j)) {
    FOR(dx, -1, 1) FOR(dy, -1, 1) if (dx * dx + dy * dy == 1) {
      if (is_empty(i + dx, j + dy)) deg[i][j]++;
    }
    if (deg[i][j] == 1) { qx.push(i); qy.push(j); }
  }
  while (!qx.empty()) {
    // REP(i, N) printf("%s\n", m[i]); printf("-------\n");
    int x = qx.front(), y = qy.front(); qx.pop(); qy.pop();
    // printf("x: %d y: %d\n", x, y);
    if (m[x][y] != '.') continue;
    bool found = false;
    FOR(dx, -1, 1) FOR(dy, -1, 1) if (dx * dx + dy * dy == 1) {
      int nx = x + dx, ny = y + dy;
      if (!is_empty(nx, ny)) continue;
      found = true;
      if (dx == 1) { m[x][y] = '^'; m[nx][ny] = 'v'; }
      if (dx == -1) { m[x][y] = 'v'; m[nx][ny] = '^'; }
      if (dy == 1) { m[x][y] = '<'; m[nx][ny] = '>'; }
      if (dy == -1) { m[x][y] = '>'; m[nx][ny] = '<'; }
      FOR(Dx, -1, 1) FOR(Dy, -1, 1) if (Dx * Dx + Dy * Dy == 1) {
        {
          int Nx = nx + Dx, Ny = ny + Dy;
          // if (is_empty(Nx, Ny)) printf("Nx: %d Ny: %d deg: %d\n", Nx, Ny, deg[Nx][Ny]);
          if (is_empty(Nx, Ny) && (--deg[Nx][Ny]) == 1) {
            // printf("adding...\n");
            qx.push(Nx); qy.push(Ny);
          }
        }
        {
          int Nx = x + Dx, Ny = y + Dy;
          // if (is_empty(Nx, Ny)) printf("Nx: %d Ny: %d deg: %d\n", Nx, Ny, deg[Nx][Ny]);
          if (is_empty(Nx, Ny) && (--deg[Nx][Ny]) == 1) {
            qx.push(Nx); qy.push(Ny);
          }
        }
      }
    }
    if (!found) return false;
  }
  REP(i, N) REP(j, M) if (m[i][j] == '.') return false;
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%s", m[i]);
  if (!solve()) printf("Not unique\n");
  else REP(i, N) printf("%s\n", m[i]);
  return 0;
}