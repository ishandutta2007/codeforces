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

#define pb push_back
#define x first
#define y second

#define MAXN 100005

typedef pair< int, int > edge;

int n, m;
int a, b;
vector< int > sol;
vector< int > G[MAXN];

int dis[MAXN], tick;

void dfs(int n) {
  dis[n] = ++tick;
  for (auto a : G[n]) if (!dis[a]) dfs(a);

  int last = -1;
  while (!G[n].empty()) {
    int t = G[n].back(); G[n].pop_back();
    if (dis[t] < dis[n]) continue;

    if (!G[t].empty()) {
      sol.pb(n);
      sol.pb(t);
      sol.pb(G[t].back());
      G[t].pop_back();
    } else {
      if (last != -1) {
        sol.pb(t);
        sol.pb(n);
        sol.pb(last);
        last = -1;
      } else {
        last = t;
      }
    }
  }

  if (last != -1) G[n].pb(last);
}

int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    G[a].pb(b);
    G[b].pb(a);
  }

  dfs(0);

  if (!G[0].empty()) {
    puts("No solution");
    return 0;
  }

  for (int i = 0; i < sol.size(); i += 3)
    printf("%d %d %d\n", sol[i] + 1, sol[i + 1] + 1, sol[i + 2] + 1);

  return 0;
}