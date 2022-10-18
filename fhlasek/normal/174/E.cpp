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

#define MAXN 1111111
int a[2*MAXN],b[MAXN],A,B;
int pos[MAXN];

int main(int argc, char *argv[]){
  REP(i,MAXN) pos[i] = -1;
  scanf("%d%d",&A,&B);
  REP(i,A){
    scanf("%d",a+i);
    a[A+i] = a[i];
  }
  REP(i,B) scanf("%d",b+i);
  REP(i,B) pos[b[i]] = i;
  int start = 0, end = 0, best = 0;
  while(start < A && pos[a[start]] == -1) start++;
  if(start == A){ printf("0\n"); return 0; }
  end = start;
  bool over = false;
  while(start < A){
    //printf("start:%d end:%d over:%d - next:%d pos-start:%d\n",start,end,(int)over,pos[a[end+1]],pos[start]);
    while(pos[a[end+1]] != -1 && ((!over && (pos[a[end+1]] > pos[a[end]] || pos[a[end+1]] < pos[a[start]])) ||
                                            (pos[a[end+1]] > pos[a[end]] && pos[a[end+1]] < pos[a[start]]))){
      if(pos[a[end+1]] <= pos[a[end]]) over = true;
      end++;
    }
    //printf("...start:%d end:%d over:%d\n",start,end,(int)over);
    best = max(best, end - start + 1);
    start++;
    if(end < start){
      over = false;
      while(start < A && pos[a[start]] == -1) start++; 
      end = start;
    }
    else if(pos[a[start]] < pos[a[start-1]]) over = false;
  }
  printf("%d\n",best);
  return 0;
}