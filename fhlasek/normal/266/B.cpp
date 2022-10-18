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

char look[55][55];

int main(int argc, char *argv[]){
  int N, T; 
  scanf("%d%d", &N, &T);
  scanf("%s", look[0]);
  REP(i, T){
    REP(j, N){
      if(j + 1 < N && look[i][j] == 'B' && look[i][j+1] == 'G') look[i+1][j] = 'G';
      else if(j    && look[i][j] == 'G' && look[i][j-1] == 'B') look[i+1][j] = 'B';
      else look[i+1][j] = look[i][j];
    }
  }
  look[T][N] = '\0';
  printf("%s\n", look[T]);

  return 0;
}