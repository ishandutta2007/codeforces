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

#define MAXN 2000

int n;
int uf[MAXN];
int w[MAXN][MAXN];

int find(int n) { return n == uf[n] ? n : uf[n] = find(uf[n]); }

vector< pair< int, pair< int, int > > > e;
vector< pair< int, int > > T[MAXN];

void check(int n, int dad, int root, llint cost) {
  if (cost != w[root][n]) {
    puts("NO");
    exit(0);
  }

  for (auto ed : T[n]) {
    int m = ed.first;
    int c = ed.second;
    
    if (c == 0) {
      puts("NO");
      exit(0);
    }
    
    if (m == dad) continue;

    check(m, n, root, cost + c);
  }
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) REP(j, n)
    scanf("%d", &w[i][j]);

  REP(i, n) REP(j, n) {
    if (i < j) {
      e.push_back({w[i][j], {i, j}});
    }
  }

  sort(e.begin(), e.end());
  REP(i, n) uf[i] = i;

  for (auto ed : e) {
    int a = ed.second.first;
    int b = ed.second.second;
    int c = ed.first;

    if (find(a) == find(b)) continue;

    uf[find(a)] = find(b);

    T[a].push_back({b, c});
    T[b].push_back({a, c});
  }

  REP(i, n) check(i, -1, i, 0);

  puts("YES");

  return 0;
}