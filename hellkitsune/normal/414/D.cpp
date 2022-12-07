#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int m, k, p;
vector<int> e[100000];
int bfs[100000], d[100000] = {};
queue<int> q;

int main() {
  scanf("%d%d%d", &m, &k, &p);
  REP(i, m - 1) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    e[x].pb(y);
    e[y].pb(x);
  }
  q.push(0);
  REP(i, m)
    bfs[i] = -1;
  bfs[0] = 0;
  int maxd = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ++d[bfs[v]];
    maxd = max(maxd, bfs[v]);
    REP(i, e[v].size())
      if (bfs[e[v][i]] == -1) {
        q.push(e[v][i]);
        bfs[e[v][i]] = bfs[v] + 1;
      }
  }
  if (maxd == 1) {
    cout << min(p, d[1]) << endl;
    return 0;
  }
  int l, r = l = maxd - 1;
  int bu = 0, su = 0;
  int ans = 0;
  while (true) {
    while (LL(d[l] - bu) * (r - l + 1) <= p) {
      p -= (d[l] - bu) * (r - l + 1);
      su += d[l];
      --l;
      bu = 0;
      if (l == 0)
        break;
    }
    if (l && (r - l + 1 <= p)) {
      bu += p / (r - l + 1);
      p %= r - l + 1;
    }
    ans = max(ans, d[r + 1] + su + bu);
    if (l == 0)
      break;
    if (l == r) {
      p += bu;
      bu = 0;
      --l;
      if (l == 0)
        break;
    } else {
      p += su + bu;
      su -= d[r];
    }
    --r;
  }
  cout << min(ans, k) << endl;
  return 0;
}