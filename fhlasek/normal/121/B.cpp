/* Writen by Filip Hlasek 2011 */
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
#define MAXN 111111

using namespace std;

int N,K;
char a[MAXN];

int main(int argc, char *argv[]){
  scanf("%d%d",&N,&K); 
  scanf("%s",a);
  int i=0,k;
  for(k=0;k<K&&i<N-1;k++){
    if(k>3*N&&K%2==k%2) break;
    while(i<N-1&&!(a[i]=='4'&&a[i+1]=='7')) i++;
    if(i<N-1){
      if(i%2){ a[i]='7'; i--; }
      else a[i+1]='4';
    }
  }
  printf("%s\n",a);
  return 0;
}