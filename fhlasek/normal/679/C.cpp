/* Written by Filip Hlasek 2016 */
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

int N, K;
#define MAXN 555
char m[MAXN][MAXN];
int pref[MAXN][MAXN];

bool done[MAXN][MAXN];
int component[MAXN][MAXN], C = 0;
queue<int> q;
int component_size[MAXN * MAXN];
int component_taken[MAXN * MAXN];

int is_inside[MAXN * MAXN], inside_count[MAXN * MAXN];

int tmp;
void upd(int row, int c) {
  if (component_taken[c] != C && (is_inside[c] != row || !inside_count[c])) {
    component_taken[c] = C;
    tmp += component_size[c];
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%s", m[i]);
  REP(i, N) REP(j, N) {
    pref[i + 1][j + 1] = (m[i][j] == 'X') + pref[i + 1][j] + pref[i][j + 1] - pref[i][j];
  }
  REP(i, N) REP(j, N) if (m[i][j] == '.' && !done[i][j]) {
    ++C;
    q.push(i); q.push(j); done[i][j] = true;
    while (!q.empty()) {
      int x = q.front(); q.pop(); int y = q.front(); q.pop();
      component_size[C]++;
      component[x + 1][y + 1] = C;
      FOR(dx, -1, 1) FOR(dy, -1, 1) if (dx * dx + dy * dy == 1) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && m[nx][ny] == '.' && !done[nx][ny]) {
          done[nx][ny] = true;
          q.push(nx); q.push(ny);
        }
      }
    }
  }
  int ans = 0;
  C = 0;
  REP(i, N - K + 1) {
    int inside_tmp = 0;
    REP(ki, K) REP(kj, K) {
      int c = component[i + ki + 1][kj + 1];
      if (is_inside[c] != i + 1) {
        inside_count[c] = 0;
        inside_tmp += component_size[c];
      }
      ++inside_count[c];
      is_inside[c] = i + 1;
    }
    REP(j, N - K + 1) {
      ++C;
      tmp = pref[i + K][j + K] - pref[i + K][j] - pref[i][j + K] + pref[i][j];
      tmp += inside_tmp;
      REP(k, K) {
        upd(i + 1, component[i][j + k + 1]);
        upd(i + 1, component[i + k + 1][j]);
        upd(i + 1, component[i + K + 1][j + k + 1]);
        upd(i + 1, component[i + k + 1][j + K + 1]);
      }
      ans = max(ans, tmp);
      REP(k, K) {
        int c = component[i + k + 1][j + 1];
        --inside_count[c];
        if (!inside_count[c]) inside_tmp -= component_size[c];
        c = component[i + k + 1][j + K + 1];
        if (is_inside[c] != i + 1) { inside_count[c] = 0; is_inside[c] = i + 1; }
        if (!inside_count[c]) inside_tmp += component_size[c];
        inside_count[c]++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}