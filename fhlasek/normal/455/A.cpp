/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int cnt[MAXN];
long long dp[MAXN];

int main(int argc, char *argv[]) {
  int N, a;
  scanf("%d", &N);
  REP(i, N) { scanf("%d", &a); cnt[a]++; }
  REP(i, MAXN - 2) {
    dp[i + 1] = max(dp[i + 1], dp[i]);
    dp[i + 2] = max(dp[i + 2], dp[i] + (long long)cnt[i] * i);
  }
  cout <<  dp[MAXN - 1] << endl;
  return 0;
}