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

using namespace std;

int N,H;
char a[1002];

int cnt(int x){
  int i,y=0;
  FOR(i,H){ if(a[(x+i)%N]!='H') y++; }
  return y;
}

int main(int argc, char *argv[]){
  int i,m=1001;
  scanf("%d",&N);
  scanf("%s",a);
  H=0;
  FOR(i,N){ if(a[i]=='H') H++; }
  FOR(i,N) m=min(m,cnt(i));
  printf("%d\n",m);
  return 0;
}