/* Written by Filip Hlasek 2012 */
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

char w[111111];
int W;

int main(int argc, char *argv[]){
  scanf("%s", w);   
  W = strlen(w);
  bool ok = false;
  REP(i, W){
    if(!ok && (i == W-1 || w[i] == '0')){ ok = true; continue; }
    printf("%c", w[i]);
  }
  printf("\n");
  return 0;
}