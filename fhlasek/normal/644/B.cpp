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
#include <iostream>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

queue<int> q;

#define MAXN 222222
long long ans[MAXN];
int T[MAXN], D[MAXN];

int main(int argc, char *argv[]) {

  int N, B;
  scanf("%d%d", &N, &B);
  REP(i, N) scanf("%d%d", T + i, D + i);

  int pos = 0;
  long long last_t = 0;

  while (pos != N || !q.empty()) {
    if (q.empty()) {
      q.push(pos++);
      continue;
    }

    int id = q.front(); q.pop();
    last_t = ans[id] = max(last_t, (long long)T[id]) + D[id];

    while (pos < N && T[pos] < last_t) {
      if (q.size() < B) q.push(pos++);
      else ans[pos++] = -1;
    }

  }

  REP(i, N) {
    if (i) printf(" ");
    cout << ans[i];
  }
  printf("\n");

  return 0;
}