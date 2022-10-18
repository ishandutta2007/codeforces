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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 55
int N, c[MAXN];
int I, L;

int dp[1 << 12][MAXN];
int solve(int mask, int leaves) {
  if (dp[mask][leaves]) return dp[mask][leaves];
  if (mask == 1 && leaves == 0) return 1;
  int ans = -1;
  int first = 0;
  while (first < I && !(mask & (1 << first))) first++;
  if (!first) return -1;
  --first;
  // printf("mask: %d leaves: %d first: %d\n", mask, leaves, first);
  REP(mask2, 1 << (I - first - 1)) {
    int sum = 0, cnt = 0;
    REP(j, I - first - 1) if (mask2 & (1 << j)) {
      if (!(mask & (1 << (first + 1 + j)))) sum += c[first];
      sum += c[first + 1 + j];
      cnt++;
    }
    if (sum >= c[first]) continue;
    int leaves_needed = c[first] - sum - 1;
    if (leaves_needed - 1 > leaves) continue;
    if (cnt + leaves_needed < 2) continue;
    int nmask = (mask ^ (mask2 << (first + 1))) | (1 << first);
    int nleaves = leaves - leaves_needed;
    if (solve(nmask, nleaves) == 1) { ans = 1; break; }
  }
  // printf("mask: %d leaves: %d => ans: %d\n", mask, leaves, ans);

  return (dp[mask][leaves] = ans);
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", c + i);
  if (N == 1) { printf("YES\n"); return 0; }
  sort(c, c + N, greater<int>());
  I = 0; L = 0;
  REP(i, N) if (c[i] == 1) L++; else I++;
  if (L > I && solve(0, L) == 1) printf("YES\n");
  else printf("NO\n");
  return 0;
}