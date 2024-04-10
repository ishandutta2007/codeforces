#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 1001

using namespace std;

typedef struct house{ int start, end;}House;

bool mycompare(House a,House b){ return a.start<b.start;}

int main(int argc, char *argv[]){
  int N,T;
  int i,x,a;
  House h[MAXN];
  scanf("%d%d",&N,&T);
  T*=2;
  FOR(i,N){
    scanf("%d%d",&x,&a);
    h[i].start=2*x-a;
    h[i].end=2*x+a;
  }
  sort(h,h+N,mycompare);
  int sum=2;
  FOR(i,N-1){
    if(h[i].end+T<h[i+1].start) sum+=2;
    else if(h[i].end+T==h[i+1].start) sum++;
  }
  printf("%d\n",sum);
  return 0;
}