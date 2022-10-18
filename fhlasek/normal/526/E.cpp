/* Written by Filip Hlasek 2015 */
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

#define MAXN 1111111
int N, Q;
int A[MAXN];

int groups[MAXN];
long long rem[MAXN];
int solve(long long B) {
  long long cur = 0;
  int last = N;
  groups[N] = 0;
  FORD(i, N - 1, 0) {
    cur += A[i];
    while (cur > B) cur -= A[--last];
    if (last == N) {
      groups[i] = 0;
      rem[i] = cur;
    }
    else {
      groups[i] = groups[last] + 1;
      rem[i] = rem[last];
    }
  }
  long long sum = 0;
  int ans = N;
  REP(i, N) {
    if (sum + rem[i] <= B) ans = min(ans, groups[i] + (sum + rem[i] > 0));
    sum += A[i];
  }
  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", A + i);
  while (Q--) {
    long long B;
    cin >> B;
    cout << solve(B) << endl;
  }
  return 0;
}