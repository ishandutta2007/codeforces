#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>

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

const int MAXN = 100005;

int N, Y, K, X;
int Ki;

int add(int a, int b) { return (a + b) % Y; }
int sub(int a, int b) { return add(a, Y - b); }
int mul(int a, int b) { return (llint)a * b % Y; }

int power(int a, int b) {
  int ret = 1;
  for (int i = 0; (1 << i) <= b; ++i) {
    if (((b >> i) & 1) == 1)
      ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}

int pwK[MAXN];
int pwKi[MAXN];

int inverse(int n) {
  return power(n, Y - 2);
}

int v[MAXN];
vector< int > T[MAXN];

bool blocked[MAXN];
int wei[MAXN];

int calc_weights(int n, int dad) {
  if (blocked[n]) return 0;
  wei[n] = 1;

  for (int m : T[n])
    if (m != dad)
      wei[n] += calc_weights(m, n);

  return wei[n];
}

int find_root(int n) {
  calc_weights(n, -1);

  int dad = -1;
  int now = n;
  int tot = wei[n];

  for (;;) {
    int best = -1;

    for (int m : T[now]) {
      if (blocked[m]) continue;
      if (m == dad) continue;
      if (best == -1 || wei[m] > wei[best]) best = m;
    }

    if (best == -1) break;
    if (wei[best] <= tot / 2) break;

    dad = now;
    now = best;
  }

  return now;
}

int in0[MAXN], out0[MAXN];
int in1[MAXN], out1[MAXN];

int dep[MAXN];
int from[MAXN];
int to[MAXN];

vector< int > all_from, all_to, all_nodes;
vector< int > subtree_from, subtree_to, subtree_nodes;

void calc_from_to_dep_and_collect(int n, int dad, int d) {
  if (blocked[n]) return;

  dep[n] = d;

  from[n] = add(mul(from[dad], K), v[n]);
  to[n] = add(to[dad], mul(v[n], pwK[d]));

  subtree_from.push_back(mul(sub(X, from[n]), pwKi[d]));
  subtree_to.push_back(to[n]);
  subtree_nodes.push_back(n);

  for (int m : T[n])
    if (m != dad)
      calc_from_to_dep_and_collect(m, n, d + 1);
}

int range_len(int x, vector< int > &v) {
  auto er = equal_range(v.begin(), v.end(), x);
  return er.second - er.first;
}

void append(vector< int > &a, vector< int > &b) {
  b.insert(b.end(), a.begin(), a.end());
}

void go(function< int(int, int) > f, int r, vector< int > &nodes, vector< int > &froms, vector< int > &tos) {
  sort(froms.begin(), froms.end());
  sort(tos.begin(), tos.end());

  for (int i : nodes) {
    out0[i] = f(out0[i], range_len(add(mul(sub(X, from[i]), pwKi[dep[i]]), v[r]), tos));
    in0[i] = f(in0[i], range_len(sub(to[i], v[r]), froms));
  }
}

void solve(int n) {
  if (blocked[n]) return;

  int r = find_root(n);
  blocked[r] = true;

  for (int m : T[r]) solve(m);
  
  from[r] = to[r] = v[r];
  dep[r] = 0;

  all_from = { sub(X, from[r]) };
  all_to = { to[r] };
  all_nodes = { r };

  for (int m : T[r]) {
    subtree_from.clear();
    subtree_to.clear();
    subtree_nodes.clear();

    calc_from_to_dep_and_collect(m, r, 1);

    go([](int a, int b) { return a - b; }, r, subtree_nodes, subtree_from, subtree_to);

    append(subtree_from, all_from);
    append(subtree_to, all_to);
    append(subtree_nodes, all_nodes);
  }

  go([](int a, int b) { return a + b; }, r, all_nodes, all_from, all_to);

  blocked[r] = false;
}

int main(void)
{
  scanf("%d%d%d%d", &N, &Y, &K, &X);
  REP(i, N) scanf("%d", &v[i]);

  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    T[a].push_back(b);
    T[b].push_back(a);
  }

  Ki = inverse(K);
  pwK[0] = pwKi[0] = 1;
  FOR(i, 1, N + 1) {
    pwK[i] = mul(pwK[i - 1], K);
    pwKi[i] = mul(pwKi[i - 1], Ki);
  }

  solve(0);

  llint p = 0;

  REP(i, N) in1[i] = N - in0[i], out1[i] = N - out0[i];
  REP(i, N) 
    p += 2LL * in0[i] * in1[i] + 2LL * out0[i] * out1[i] + 1LL * in0[i] * out1[i] + 1LL * in1[i] * out0[i];

  printf("%I64d\n", (llint)N * N * N - p / 2);

  return 0;
}