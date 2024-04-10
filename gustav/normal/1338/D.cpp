#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1e5 + 5;

int sol;
int dp[MAXN][2];
vector<int> T[MAXN];

void solve(int i, int dad = -1) {
  multiset<int> max0;
  multiset<int> max1;
  for (int j : T[i]) {
    if (j == dad) {
      continue;
    }
    solve(j, i);
    max0.insert(dp[j][0]);
    max1.insert(dp[j][1]);
  }

  int cnt = max0.size();
  if (cnt == 0) {
    dp[i][0] = 0;
    dp[i][1] = 1;
    return;
  }
  
  dp[i][0] = max(0, *--max1.end() + cnt - 1);
  dp[i][1] = max(*--max0.end() + 1, dp[i][0]);

  sol = max(sol, dp[i][1]);
  if (max0.size() >= 2) {
    {
      auto it = max0.end();
      int a = *--it;
      int b = *--it;
      sol = max(sol, a + b + 1);
    }
    {
      auto it = max1.end();
      int a = *--it;
      int b = *--it;
      sol = max(sol, a + b + cnt - 2 + (i != 1));
    }
  }
}

int main(void) 
{
  int N;
  scanf("%d", &N);
  REP(i, N - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    T[a].push_back(b);
    T[b].push_back(a);
  }

  sol = 1;
  memset(dp, -1, sizeof dp);
  solve(1);
  
  printf("%d\n", sol);

  return 0;
}