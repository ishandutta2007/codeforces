#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 50005;
const int MAXM = 50005;

namespace sat {
  const int MAX = 5 * MAXM;
  int CMAX;
  vector< int > G[2 * MAX];

  int stk[2 * MAX], top;
  int got[2 * MAX];
  int com[2 * MAX], ccom;
  int val[MAX];

  int dis[2 * MAX], tick;
  int low[2 * MAX];

  void init(int cmax) {
    CMAX = cmax;
    REP(i, 2 * CMAX) {
      G[i].clear();
      stk[i] = 0;
      com[i] = 0;
      val[i] = -1;
      dis[i] = 0;
      low[i] = 0;
    }
    top = ccom = tick = 0;
  }

  void add_implies(int a, int b) {
    G[a].push_back(b);
    G[b ^ 1].push_back(a ^ 1);
  }

  void add_or(int a, int b) {
    add_implies(a ^ 1, b);
    add_implies(b ^ 1, a);
  }

  void add_xor(int a, int b) {
    add_or(a, b);
    add_or(a ^ 1, b ^ 1);
  }

  void disable(int x) { add_implies(x, x ^ 1); }
  void force(int x) { add_implies(x ^ 1, x); }

  bool tarjan(int n) {
    dis[n] = low[n] = ++tick;
    stk[top++] = n;
    got[n] = true;

    for (int m : G[n]) {
      if (dis[m] && got[m]) {
        low[n] = min(low[n], dis[m]);
      } else if (!dis[m]) {
        if (!tarjan(m)) return false;
        low[n] = min(low[n], low[m]);
      }
    }

    if (low[n] != dis[n]) return true;
    
    ++ccom;
    
    int m = -1;
    do {
      m = stk[--top];
      got[m] = false;
      com[m] = ccom;

      if (com[m ^ 1] == com[m]) return false;
      if (val[m / 2] == -1) val[m / 2] = m % 2;
    } while (m != n);

    return true;
  }

  bool solve() {
    REP(i, 2 * MAX) {
      if (dis[i]) continue;
      if (!tarjan(i)) return false;
    }
    return true;
  }

  int get(int x) {
    return val[x];
  }
};

int n, m;

int a[MAXM];
int b[MAXM];
int c[MAXM];
int t[MAXM];

struct Edge {
  int b, c, t, id;
};

bool operator<(const Edge &a, const Edge &b) {
  return a.c < b.c;
}

vector< Edge > G[MAXN];

bool check(vector< pair< int, int > > &xor_pairs, int T) {
  sat :: init(MAXM + 4 * MAXM);

  for (auto it : xor_pairs)
    sat :: add_xor(it.first * 2 + 1, it.second * 2 + 1);

  REP(i, m) 
    if (t[i] > T)
      sat :: disable(i * 2 + 1);

  int alloc = MAXM;

  FOR(i, 1, n + 1) {
    vector< int > pref;
    vector< int > suff;

    REP(j, (int)G[i].size()) {
      pref.push_back(alloc++);
      suff.push_back(alloc++);

      sat :: add_implies(pref[j] * 2 + 1, G[i][j].id * 2);
      sat :: add_implies(suff[j] * 2 + 1, G[i][j].id * 2);
    }

    FOR(j, 1, (int)G[i].size())
      sat :: add_implies(pref[j] * 2 + 1, pref[j - 1] * 2 + 1);

    REP(j, (int)G[i].size() - 1)
      sat :: add_implies(suff[j] * 2 + 1, suff[j + 1] * 2 + 1);

    REP(j, (int)G[i].size()) {
      if (j)
	sat :: add_implies(G[i][j].id * 2 + 1, pref[j - 1] * 2 + 1);
      if (j + 1 < (int)G[i].size())
	sat :: add_implies(G[i][j].id * 2 + 1, suff[j + 1] * 2 + 1);
    }
  }

  return sat :: solve();
}

int main(void) 
{
  scanf("%d%d", &n, &m);

  vector< int > ts;

  REP(i, m) {
    scanf("%d%d%d%d", a+i, b+i, c+i, t+i);
    G[a[i]].push_back({b[i], c[i], t[i], i});
    G[b[i]].push_back({a[i], c[i], t[i], i});
    ts.push_back(t[i]);
  }

  ts.push_back(0);
  sort(ts.begin(), ts.end());
  ts.resize(unique(ts.begin(), ts.end()) - ts.begin());

  vector< pair< int, int > > xor_pairs;

  FOR(i, 1, n + 1) {
    sort(G[i].begin(), G[i].end());
    for (int j = 0, k; j < (int)G[i].size(); j = k) {
      for (k = j + 1; k < (int)G[i].size() && G[i][j].c == G[i][k].c; ++k);
      if (k - j > 2) {
	puts("No");
	exit(0);
      }
      if (k - j == 2) {
	xor_pairs.push_back({G[i][j].id, G[i][k - 1].id});
      }
    }
  }

  int lo = 0, hi = (int)ts.size();

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(xor_pairs, ts[mid]))
      hi = mid;
    else
      lo = mid + 1;
  }

  if (lo == (int)ts.size()) {
    puts("No");
    exit(0);
  }

  check(xor_pairs, ts[lo]);

  puts("Yes");
  printf("%d ", ts[lo]);

  vector< int > matching;

  REP(i, m) if (sat :: get(i)) matching.push_back(i);

  printf("%d\n", (int)matching.size());
  REP(i, (int)matching.size())
    printf("%d%c", matching[i] + 1, " \n"[i + 1 == (int)matching.size()]);

  return 0;
}