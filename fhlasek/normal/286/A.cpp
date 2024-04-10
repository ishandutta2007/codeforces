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

int main(int argc, char *argv[]){
  int N; 
  scanf("%d", &N);
  if(N % 4 > 1) printf("-1\n");
  else {
    REP(i, N / 4) printf("%d %d ", 2*(i+1), N-2*i);
    if( N % 2) printf("%d ", (N + 1) / 2);
    REP(i, N / 4) printf("%d %d ", (N - 2) / 2 - 2 * i, (N + 3) / 2 + 2 * i);
    printf("\n");
  }
  return 0;
}