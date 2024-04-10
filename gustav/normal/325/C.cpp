#include <cstdio>
#include <cassert>
#include <cstring>
#include <set>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXV = 314000000;
const int INF = MAXV + 1;
const int MAXM = 100005;
const int MAXN = 100005;

int n, m;
int who[MAXM];
vector< int > T[MAXM]; // transformacije
vector< int > Q[MAXN]; // za svaki cvor lista transformacija
vector< int > P[MAXN];
vector< int > PP[MAXN];
int deg[MAXM]; 
int val[MAXM];
int in[MAXN];
int stk[MAXN], top;

vector< int > G[MAXN];
vector< int > DAG[MAXN];

int tick;
int dis[MAXN];
int low[MAXN];
int com[MAXN], coms;
int csz[MAXN];
int endable[MAXM];
int node_endable[MAXN];
int loop[MAXN];

void tarjan(int i) {
  dis[i] = low[i] = ++tick;
  in[i] = 1;
  stk[top++] = i;

  for (int j : G[i]) {
    if (dis[j] == 0) {
      tarjan(j);
      low[i] = min(low[i], low[j]);
    } else if (in[j]) {
      low[i] = min(low[i], dis[j]);
    }
  }

  if (low[i] < dis[i]) return;

  int cur;

  do {
    cur = stk[--top];
    for (int i : P[cur]) PP[coms].push_back(i);
    in[cur] = 0;
    com[cur] = coms;
    ++csz[coms];
  } while (cur != i);

  coms++;
}

int bio[MAXN];
int dp_max[MAXN];

void calc_dp(int i) {
  if (bio[i]) return;
  bio[i] = 1;

  dp_max[i] = 0;
  for (int j : DAG[i]) calc_dp(j);

  for (int t : PP[i]) {
    if (!endable[t]) continue;
    int cmax = 0;

    for (int j : T[t]) {
      if (j < 0)
	cmax = min(MAXV, cmax + 1);
      else {
	cmax = min(MAXV, cmax + dp_max[com[j]]);
	if (loop[com[j]]) loop[i] = 1;
      }
    }

    dp_max[i] = max(dp_max[i], cmax);
  }
}

int D[MAXN];

struct cmp {
  bool operator()(int a, int b) {
    if (D[a] != D[b]) return D[a] < D[b];
    return a < b;
  }
};

set< int, cmp > pq;

void dijkstra() {
  memset(D, 0x3f, sizeof D);

  REP(i, m) {
    if (!endable[i]) continue;
    deg[i] = 0;
    val[i] = 0;
    for (int j : T[i]) if (j >= 0) ++deg[i]; else ++val[i];
    if (deg[i] == 0) {
      pq.erase(who[i]);
      D[who[i]] = min(D[who[i]], val[i]);
      pq.insert(who[i]);
    }
  }

  while (!pq.empty()) {
    int cur = *pq.begin();
    pq.erase(pq.begin());

    for (int i : Q[cur]) {
      if (!endable[i]) continue;
      if (who[i] == cur) continue;
      val[i] = min(MAXV, val[i] + D[cur]);
      if (--deg[i] == 0 && D[who[i]] > val[i]) {
	pq.erase(who[i]);
	D[who[i]] = val[i];
	pq.insert(who[i]);
      }
    }
  }
}

int main(void) 
{
  scanf("%d%d", &m, &n);

  REP(i, m) {
    scanf("%d", who + i); --who[i];
    P[who[i]].push_back(i);
    int l; scanf("%d", &l);
    REP(j, l) {
      int id;
      scanf("%d", &id); --id;
      T[i].push_back(id);
      if (id >= 0) Q[id].push_back(i), ++deg[i];
    }
  }

  REP(i, m) {
    if (deg[i] == 0) {
      endable[i] = 1;
      if (!in[who[i]]) 
	in[who[i]] = 1, stk[top++] = who[i];
    }
  }

  while (top) {
    int cur = stk[--top];
    node_endable[cur] = 1;
    for (int i : Q[cur]) {
      if (--deg[i] == 0) {
	endable[i]= 1;
	if (!in[who[i]]) 
	  in[who[i]] = 1, stk[top++] = who[i];
      }
    }
  }

  dijkstra();

  REP(i, m) {
    if (!endable[i]) continue;
    for (int j : T[i]) 
      if (j >= 0) 
	G[who[i]].push_back(j);
  }

  REP(i, n) in[i] = 0;
  REP(i, n) if (!dis[i] && node_endable[i]) tarjan(i);
  REP(i, coms) if (csz[i] > 1) loop[i] = true;

  REP(i, m) {
    if (!endable[i]) continue;
    for (int j : T[i]) {
      if (j >= 0) {
	if (com[who[i]] != com[j]) {
	  DAG[com[who[i]]].push_back(com[j]);
	} else {
	  loop[com[j]] = true;
	}
      }
    }
  }
  
  REP(i, coms) calc_dp(i);

  REP(i, n) {
    if (!node_endable[i])
      puts("-1 -1");
    else {
      int mi = D[i];
      int ma = loop[com[i]] ? -2 : dp_max[com[i]];
      printf("%d %d\n", mi, ma);
    }
  }
  
  return 0;
}