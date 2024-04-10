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
#include <unordered_map>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
unordered_map<int, int> m;
int M = 0;

vector<int> moments[MAXN], f[MAXN];
unordered_map<int, int> mm;

int A[MAXN], T[MAXN], X[MAXN];

void fadd(int id, int x, int val) {
  while (x < f[id].size()) {
    f[id][x] += val;
    x += x & (-x);
  }
}
int fget(int id, int x) {
  int ans = 0;
  while (x) {
    ans += f[id][x];
    x -= x & (-x);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int Q;
  scanf("%d", &Q);
  REP(i, Q) scanf("%d%d%d", T + i, A + i, X + i);
  REP(i, Q) {
    if (!m.count(X[i])) {
      f[M].push_back(0);
      m[X[i]] = M++;
    }
    int id = m[X[i]];
    moments[id].push_back(A[i]);
    f[id].push_back(0);
  }
  REP(i, M) {
    sort(moments[i].begin(), moments[i].end());
    REP(j, moments[i].size()) mm[moments[i][j]] = j;
  }
  REP(i, Q) {
    int id = m[X[i]];
    if (T[i] == 1)        fadd(id, mm[A[i]] + 1, 1);
    else if (T[i] == 2)   fadd(id, mm[A[i]] + 1, -1);
    else printf("%d\n", fget(id, mm[A[i]]));
  }
  return 0;
}