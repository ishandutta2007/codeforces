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
#define log(...) fprintf(stderr, ##__VA_ARGS__)

#define MAXN 100005

int n, a, b;
vector< int > T[MAXN];
int dep[MAXN];

void dfs(int n, int dad, int d = 1) {
  dep[n] = d;
  for (int m : T[n]) 
    if (m != dad) dfs(m, n, d + 1);
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n - 1) {
    scanf("%d%d", &a, &b); --a; --b;
    T[a].push_back(b);
    T[b].push_back(a);
  }

  dfs(0, -1);

  double sol = 0.0;
  REP(i, n) sol += 1.0 / dep[i];

  printf("%.8lf\n", sol);

  return 0;
}