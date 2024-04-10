/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 111111
int A[MAXN];
int N;

int H = 1;
int have_it[MAXN];

int dp[MAXN];

int squads(int k) {
  if (dp[k]) return dp[k];
  int ans = 0;
  int start = 0;
  while (start < N) {
    int different = 0;
    H++;
    ans++;
    // printf("k: %d start: %d\n", k, start);
    while (different <= k && start < N) {
      // printf("start: %d diff: %d\n", start, different);
      if (have_it[A[start]] != H) {
        different++;
        have_it[A[start]] = H;
      }
      if (different <= k) {
        start++;
      }
    }
  }
  return dp[k] = ans;
}

int ans[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  for (int k = 1; k <= 1320; ++k) {
    ans[k] = squads(k);
  }
  int min_k = N + 1;
  for (int s = 1; s <= 77; ++s) {
    int left = 1, right = min_k;
    while (left < right) {
      int middle = (left + right) / 2;
      if (squads(middle) <= s) right = middle;
      else left = middle + 1;
    }
    for (int j = left; j < min_k; ++j) ans[j] = s;
    min_k = left;
  }
  FOR(k, 1, N) {
    if (k > 1) printf(" ");
    printf("%d", ans[k]);
  }
  printf("\n");
  return 0;
}