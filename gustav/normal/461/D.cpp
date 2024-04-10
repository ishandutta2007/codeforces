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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int mod = 1000000007;

#define MAXN 100005


int N, K;
int x, y;
char c[MAXN];
int l[MAXN];
int r[MAXN];

int uf[MAXN];

int f(int n) { return uf[n] == n ? n : uf[n] = f(uf[n]); }
void unite(int a, int b) { a += 2; b += 2; uf[f(a)] = f(b); }
int find(int n) { return f(n + 2) - 2; }

int bio[MAXN];
vector< int > G[MAXN];

void add_edge(int a, int b) {
  a += 2; b += 2;
  G[a].push_back(b);
  G[b].push_back(a);
}

bool bicolor(int n, int color) {
  if (bio[n]) return bio[n] == color;
  bio[n] = color;

  for (int m : G[n]) 
    if (!bicolor(m, 3 - color))
      return false;

  return true;
}

void no() {
  puts("0");
  exit(0);
}

int main(void)
{
  scanf("%d%d", &N, &K);
  REP(i, K) { 
    scanf("%d%d %c", &x, &y, &c[i]); --x; --y; 
    l[i] = abs(x - y);
    r[i] = min(x + y, 2 * N - 2 - x - y);
  }
  REP(i, N + 2) uf[i] = i;

  REP(i, K) if (c[i] == 'x') unite(l[i] - 2, r[i]);
  REP(i, K) if (c[i] == 'o') add_edge(find(l[i] - 2), find(r[i]));

  int cnt = 0;

  FOR(i, -2, N) {
    if (i != find(i)) continue;
    if (bio[i + 2]) continue;
    if (!bicolor(i + 2, 1)) no();
    ++cnt;
  }

  int sol = 1;
  REP(i, cnt - 2) {
    sol *= 2;
    if (sol >= mod) sol -= mod;
  }

  printf("%d\n", sol);

  return 0;
}