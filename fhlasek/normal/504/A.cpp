/* Written by Filip Hlasek 2014 */
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

#define MAXN 1111111
int deg[MAXN], s[MAXN];
vector<pair<int, int> > ans;
int N;

queue<int> q;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) { scanf("%d%d", deg + i, s + i); if (deg[i] == 1) q.push(i); }
  while (!q.empty()) {
    int v = q.front(); q.pop();
    if (deg[v] == 1) {
      ans.push_back(make_pair(v, s[v]));
      s[s[v]] ^= v;
      if (--deg[s[v]] == 1) q.push(s[v]);
    }
  }
  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}