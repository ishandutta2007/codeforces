/* Writen by Filip Hlasek 2012 */
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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int d[7];

int main(int argc, char *argv[]){
  int N;
  scanf("%d",&N);
  REP(i,7) scanf("%d",d+i);
  while(N>0){
    REP(i,7){
      N -= d[i];
      if(N<=0){
        printf("%d\n",i+1);
        break;
      }
    }
  }
  return 0;
}