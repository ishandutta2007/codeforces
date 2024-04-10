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

#define MAXN 111

int N;
int S[MAXN];
char names[MAXN][22];
int a[MAXN][3];
char l[20];

bool taxi(){
  return l[0] == l[1] && l[0] == l[3] && l[0] == l[4] && l[0] == l[6] && l[0] == l[7];
}

bool pizza(){
  return l[0] > l[1] && l[1] > l[3] && l[3] > l[4] && l[4] > l[6] && l[6] > l[7];
}


int main(int argc, char *argv[]){
  scanf("%d",&N);
  REP(i,N){
    scanf("%d",S+i);
    scanf("%s",names[i]);
    REP(j,S[i]){
      scanf("%s",l);
      if(taxi()) a[i][0]++;
      else{
        if(pizza()) a[i][1]++;
        else a[i][2]++;
      }
    }
  }
  int best = 0;
  bool printed = false;
  REP(i,N) best = max(best, a[i][0]);
  printf("If you want to call a taxi, you should call:");
  REP(i,N) if(best == a[i][0]){
    if(printed) printf(",");
    printf(" %s",names[i]);
    printed = true;
  }
  printf(".\n");

  best = 0;
  printed = false;
  REP(i,N) best = max(best, a[i][1]);
  printf("If you want to order a pizza, you should call:");
  REP(i,N) if(best == a[i][1]){
    if(printed) printf(",");
    printf(" %s",names[i]);
    printed = true;
  }
  printf(".\n");

  best = 0;
  printed = false;
  REP(i,N) best = max(best, a[i][2]);
  printf("If you want to go to a cafe with a wonderful girl, you should call:");
  REP(i,N) if(best == a[i][2]){
    if(printed) printf(",");
    printf(" %s",names[i]);
    printed = true;
  }
  printf(".\n");


  return 0;
}