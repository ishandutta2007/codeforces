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

vector<int> A, B;

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, N) { int a; scanf("%d", &a); A.push_back(a); }
  REP(i, M) { int b; scanf("%d", &b); B.push_back(b); }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  if (A[N - 1] > B[M - 1]) { swap(A, B); swap(N, M); }

  long long sum = 0;
  REP(i, N) sum += A[i];

  long long ans = sum;
  REP(i, M - 1) ans += min((long long)B[i], sum);

  cout << ans << endl;

  return 0;
}