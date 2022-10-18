#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int mod = 1000000007;

int modit(int x) { 
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return (llint)a * b % mod; }
int sq(int x) { return mul(x, x); }

struct PowerSums {
  int sum[3];

  PowerSums() {
    memset(sum, 0, sizeof sum);
  }

  PowerSums append(int x) {
    PowerSums ret;
    ret.sum[0] = sum[0];
    x = modit(x);
    ret.sum[2] = add(sum[2], add(mul(2, mul(x, sum[1])), mul(sq(x), sum[0])));
    ret.sum[1] = add(sum[1], mul(x, sum[0]));
    return ret;
  }

  PowerSums add_zero() {
    PowerSums ret = *this;
    ret.sum[0] = add(1, sum[0]);
    return ret;
  }

  int get() { return sum[2]; }
};

PowerSums apply(const PowerSums &a, const PowerSums &b, int f(int,int)) {
  PowerSums ret;
  REP(i, 3) ret.sum[i] = f(a.sum[i], b.sum[i]);
  return ret;
}

PowerSums operator+(const PowerSums &a, const PowerSums &b) {
  return apply(a, b, add);
}

PowerSums operator-(const PowerSums &a, const PowerSums &b) {
  return apply(a, b, sub);
}

const int MAXN = 100005;
const int MAXL = 18;
typedef pair< int, int > Edge;

PowerSums down[MAXN];
PowerSums tot[MAXN];
PowerSums up[MAXN];

int N, Q;
vector< Edge > T[MAXN];
int rdist[MAXN];

void calc_down(int i, int dad, int rd) {
  rdist[i] = rd;
  for (auto e : T[i]) {
    int j = e.first;
    int d = e.second;
    if (j != dad) {
      calc_down(j, i, add(rd, d));
      down[i] = down[i] + down[j].append(d);
    }
  }
  down[i] = down[i].add_zero();
}

void calc_tot(int i, int dad) { // tot[i] je vec izracunat
  for (auto e : T[i]) {
    int j = e.first;
    int d = e.second;
    if (j != dad) {
      tot[j] = down[j] + (tot[i] - down[j].append(d)).append(d);
      calc_tot(j, i);
    }
  }
  up[i] = tot[i] - down[i];
}

void calc_all() {
  calc_down(0, -1, 0);
  tot[0] = down[0];
  calc_tot(0, -1);
}

int dad[MAXN];
int dep[MAXN];
int anc[MAXN][MAXL];

void dfs(int i, int d) {
  dep[i] = d;
  for (auto it : T[i]) {
    int j = it.first;
    if (j != dad[i]) {
      dad[j] = i;
      dfs(j, d + 1);
    }
  }
}

void lca_precalc() {
  dfs(0, 0);
  REP(i, N) anc[i][0] = dad[i];
  FOR(p, 1, MAXL) REP(i, N) 
    anc[i][p] = anc[anc[i][p - 1]][p - 1];
}

int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);

  for (int p = MAXL - 1; p >= 0; --p)
    if (dep[anc[a][p]] >= dep[b])
      a = anc[a][p];

  if (a == b) return a;

  for (int p = MAXL - 1; p >= 0; --p)
    if (anc[a][p] != anc[b][p])
      a = anc[a][p], b = anc[b][p];

  return dad[a];
}

int dist(int a, int b) {
  return sub(add(rdist[a], rdist[b]), mul(2, rdist[lca(a, b)]));
}

bool is_ancestor(int a, int b) {
  return lca(a, b) == a;
}

int main(void)
{
  scanf("%d", &N);

  REP(i, N - 1) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d); --a; --b;
    T[a].push_back(Edge(b, d));
    T[b].push_back(Edge(a, d));
  }

  lca_precalc();
  calc_all();

  scanf("%d", &Q);

  REP(i, Q) {
    int u, v;
    scanf("%d%d", &u, &v); --u; --v;

    if (is_ancestor(v, u)) 
      printf("%d\n", sub(tot[u].get(), mul(2, up[v].append(dist(u, v)).get())));
    else
      printf("%d\n", sub(mul(2, down[v].append(dist(u, v)).get()), tot[u].get()));
  }

  return 0;
}