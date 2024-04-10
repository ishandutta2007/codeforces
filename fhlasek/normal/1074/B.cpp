/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 1111
int N, a[MAXN], b[MAXN], A, B;

vector<int> graph[MAXN];
queue<int> q;
bool done[MAXN], subset[MAXN];

int solve() {
  int x_li = b[0];
  printf("B %d\n", x_li + 1); fflush(stdout);
  int x_me;
  scanf("%d", &x_me);
  x_me--;

  REP(i, N) done[i] = subset[i] = false;
  REP(i, A) subset[a[i]] = true;

  while (!q.empty()) q.pop();
  q.push(x_me);
  while (!q.empty()) {
    x_me = q.front(); q.pop();
    if (subset[x_me]) break;
    REP(i, graph[x_me].size()) {
      int n = graph[x_me][i];
      if (done[n]) continue;
      done[n] = true;
      q.push(n);
    }
  }

  printf("A %d\n", x_me + 1); fflush(stdout);
  scanf("%d", &x_li);
  x_li--;

  REP(i, B) if (b[i] == x_li) return x_me + 1;
  return -1;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    REP(i, N - 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--; y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    scanf("%d", &A);
    REP(i, A) { scanf("%d", a + i); a[i]--; }
    scanf("%d", &B);
    REP(i, B) { scanf("%d", b + i); b[i]--; }
    printf("C %d\n", solve());
    fflush(stdout);
    REP(i, N) graph[i].clear();
  }
  return 0;
}