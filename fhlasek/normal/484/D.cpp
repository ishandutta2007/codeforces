#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
int A[MAXN], N;
long long dp[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  int pos = 0;
  FOR(i, 1, N - 1) {
    if (A[i - 1] == A[i]) { dp[i + 1] = dp[i]; pos = i; continue; }
    if (!(A[pos] >= A[i - 1] && A[i - 1] > A[i]) && !(A[pos] <= A[i - 1] && A[i - 1] < A[i])) pos = i - 1;
    dp[i + 1] = max(dp[pos] + abs(A[pos] - A[i]), dp[pos + 1] + abs(A[pos + 1] - A[i]));
  }
  cout << dp[N] << endl;
  return 0;
}