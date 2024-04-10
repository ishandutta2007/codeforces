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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222222
vector<int> graph[MAXN];
int N, X, Y;

pair<int, int> dfs(int v, int f = -1) {

  pair<int, int> ans(1, 1);

  int base = 0, wrong = 0, right = 0;

  REP(i, graph[v].size()) {
    int n = graph[v][i];
    if (n == f) continue;
    pair<int, int> tmp = dfs(n, v);
    base += tmp.second;
    if (tmp.first > tmp.second) wrong++;
    else right++;
  }

  if (right) ans.first = base;
  else ans.first = base + 1;

  ans.second = ans.first;
  if (right >= 2) ans.second = base - 1;

  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &X, &Y);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if (X <= Y) {
    int ways = dfs(0).second;
    cout << (ways - 1) * (long long)Y + (N - ways) * (long long)X << endl;
  }
  else {
    bool ok = true; // Wrong: ok = N > 4
    REP(i, N) if (graph[i].size() == N - 1) ok = false;
    long long ans = (long long)(N - 1) * Y;
    if (!ok) ans += X - Y;
    cout << ans << endl;
  }
  return 0;
}