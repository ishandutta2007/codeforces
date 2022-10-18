#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 2005;
const llint inf = 1000000000000000000LL;
typedef pair< int, int > Edge;

int n, m;
int s, t;
int p[MAX];

vector< Edge > G[MAX];

int cnt1[MAX][MAX], nxt1[MAX][MAX]; llint sum1[MAX][MAX];
int cnt2[MAX][MAX], nxt2[MAX][MAX]; llint sum2[MAX][MAX];

llint ds[MAX], dt[MAX];
vector< int > level[MAX];

vector< llint > wws, wwt;
void dijkstra(int s, llint *d, vector< llint > &w) {
  auto cmp = [&](int a, int b) {
    if (d[a] != d[b]) return d[a] < d[b];
    return a < b;
  };
  set< int, decltype(cmp) > pq(cmp);
  REP(i, n) d[i] = inf;
  d[s] = 0;
  pq.insert(s);
  while (!pq.empty()) {
    int i = *pq.begin(); pq.erase(pq.begin());
    for (auto jt : G[i]) {
      int j = jt.first;
      int w = jt.second;
      if (d[j] > d[i] + w) {
	pq.erase(j);
	d[j] = d[i] + w;
	pq.insert(j);
      }
    }
  }
  w.clear();
  REP(i, n) w.push_back(d[i]);
  w.push_back(-1);
  sort(w.begin(), w.end());
  w.resize(unique(w.begin(), w.end()) - w.begin());
}

void calc(int s, int t, int cnt[MAX][MAX], llint sum[MAX][MAX], int nxt[MAX][MAX]) {
  dijkstra(s, ds, wws); 
  dijkstra(t, dt, wwt); 

  REP(i, (int)wws.size()) level[i].clear(); 
  REP(i, n) level[lower_bound(wws.begin(), wws.end(), ds[i]) - wws.begin()].push_back(i);

  REP(r, (int)wwt.size()) {
    cnt[0][r] = 0;
    FOR(x, 1, (int)wws.size()) {
      cnt[x][r] = cnt[x - 1][r];
      sum[x][r] = sum[x - 1][r];
      for (int i : level[x]) {
	if (dt[i] > wwt[r]) {
	  cnt[x][r] += 1;
	  sum[x][r] += p[i];
	}
      }
    }
    nxt[wws.size() - 1][r] = wws.size() - 1;
    for (int x = wws.size() - 2; x >= 0; --x) {
      if (cnt[x][r] == cnt[x + 1][r])
	nxt[x][r] = nxt[x + 1][r];
      else
	nxt[x][r] = x + 1;
    }
  }
}

llint dp[MAX][MAX][2][2];
int bio[MAX][MAX][2][2];

llint f(int x1, int x2, int turn, int started) {
  if (nxt1[x1][x2] == MAX) return 0;
  
  llint &ret = dp[x1][x2][turn][started];
  if (bio[x1][x2][turn][started]) return ret;
  bio[x1][x2][turn][started] = 1;

  if (turn == 0) {
    ret = f(nxt1[x1][x2], x2, turn, 1) + sum1[nxt1[x1][x2]][x2] - sum1[x1][x2];
    if (started) ret = max(ret, f(x1, x2, !turn, 0));
  } else {
    ret = f(x1, nxt2[x2][x1], turn, 1) - sum2[nxt2[x2][x1]][x1] + sum2[x2][x1];
    if (started) ret = min(ret, f(x1, x2, !turn, 0));
  }

  return ret;
}

int main(void) 
{
  scanf("%d%d", &n, &m);
  scanf("%d%d", &s, &t); --s; --t;
  REP(i, n) scanf("%d", p + i);
  REP(i, m) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w); --a; --b;
    G[a].push_back({b, w});
    G[b].push_back({a, w});
  }

  calc(s, t, cnt1, sum1, nxt1);
  calc(t, s, cnt2, sum2, nxt2);

  llint delta = f(0, 0, 0, 0);

  if (delta > 0)
    puts("Break a heart");
  else if (delta < 0)
    puts("Cry");
  else
    puts("Flowers");

  return 0;
}