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

char line[2][111111];

int main(int argc, char *argv[]){
  scanf("%s",line[0]); 
  scanf("%s",line[1]); 
  int diff1=0,diff2=0;
  int N = strlen(line[0]);
  REP(i,N){
    diff1+=(line[0][i]>line[1][i]);
    diff2+=(line[0][i]<line[1][i]);
  }
  printf("%d\n",max(diff1,diff2));
  return 0;
}