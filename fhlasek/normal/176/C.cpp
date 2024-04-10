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

int main(int argc, char *argv[]){
  int N,M,x1,y1,x2,y2,dx,dy; 
  scanf("%d%d%d%d%d%d",&N,&M,&x1,&y1,&x2,&y2);
  dx = abs(x1-x2);
  dy = abs(y1-y2);
  if(dx > 4 || dy > 4 || (dx == 4 && dy == 4) || (dx == 3 && dy == 4) || (dx == 4 && dy == 3)) printf("Second\n");
  else printf("First\n");
  return 0;
}