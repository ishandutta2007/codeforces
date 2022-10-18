/* Written by Filip Hlasek 2018 */
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
int A[2 * MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, 2 * N) scanf("%d", A + i);
  sort(A, A + 2 * N);
  long long ans = (long long)(A[N - 1] - A[0]) * (A[2 * N - 1] - A[N]);
  REP(i, N) {
    ans = min(ans, (long long)(A[2 * N - 1] - A[0]) * (A[N - 1 + i] - A[i]));
  }
  cout << ans << endl;
  return 0;
}