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

#define MAXN 100005
const int T = 600;

int N, K;
double dp[2][T + 1];

int main(void)
{
  scanf("%d%d", &N, &K);

  for (int n = 1; n <= N; ++n) {
    int I = n % 2;
    for (int t = 1; t <= T; ++t) {
      dp[I][t] = (1.0 - 1.0 / K) * dp[I ^ 1][t];
      dp[I][t] += 1.0 / (K * (t + 1)) * (t * dp[I ^ 1][t] + t * (t + 1) / 2);
      dp[I][t] += 1.0 / (K * (t + 1)) * (dp[I ^ 1][t + 1] + t);
    }
  }

  printf("%.10lf\n", K * dp[N % 2][1]);

  return 0;
}