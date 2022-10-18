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
  int a1,a2,a3,a4;
  scanf("%d%d%d%d",&a1,&a2,&a3,&a4); 
  if(abs(a3-a4)>1){ printf("-1\n"); return 0; }
  if(a3==a4){
    if(a1<a3 || a2<a3 || (a1==a3&&a2==a3)){ printf("-1\n"); return 0; }
    if(a1==a3){
      REP(i,2*a3+1) printf("%d",4*(i%2)+7*((i+1)%2));
      REP(i,a2-a3-1) printf("7");
    }
    else{
      REP(i,a1-a3-1) printf("4");
      REP(i,2*a3) printf("%d",7*(i%2)+4*((i+1)%2));
      REP(i,a2-a3) printf("7");
      printf("4");
    }
  }
  else if(a3<a4){
    if(a1<a4||a2<a4){ printf("-1\n"); return 0; }
    printf("7");
    REP(i,a1-a4) printf("4");
    REP(i,2*a4-2) printf("%d",7*(i%2)+4*((i+1)%2));
    REP(i,a2-a4) printf("7");
    printf("4");
  }
  else if(a3>a4){
    if(a1<a3||a2<a3){ printf("-1\n"); return 0; }
    REP(i,a1-a3) printf("4");
    REP(i,2*a3) printf("%d",7*(i%2)+4*((i+1)%2));
    REP(i,a2-a3) printf("7");
  }
  printf("\n");
  return 0;
}