/* Written by Filip Hlasek 2016 */
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

#define MAXN 222222
int A[MAXN], B[MAXN];
vector<int> a, b;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) scanf("%d", B + i);
  int pos1 = 0;
  REP(i, N) if (A[i] == 1) pos1 = i;
  REP(i, N) if (A[(pos1 + i) % N]) a.push_back(A[(pos1 + i) % N]);

  REP(i, N) if (B[i] == 1) pos1 = i;
  REP(i, N) if (B[(pos1 + i) % N]) b.push_back(B[(pos1 + i) % N]);
  printf("%s\n", a == b ? "YES" : "NO");

  return 0;
}