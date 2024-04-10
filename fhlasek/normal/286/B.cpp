/* Written by Filip Hlasek 2013 */
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

#define MAXN 1111111
int a[2*MAXN], N;

void f(int k) {
  if(N % k) a[N + k-2] = a[(N / k) * k + k-2];
  FORD(i, N / k - 1, 0) a[(i + 1) * k + k-2] = a[i * k + k-2];
}

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) a[i] = i + 1;
  FOR(k, 2, N) f(k);
  FOR(i, N-1, 2*N-2) printf("%d ", a[i]);
  printf("\n");
  return 0;
}