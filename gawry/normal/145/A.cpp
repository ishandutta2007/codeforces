#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 101000
char x[MAX],y[MAX];
int n,a[2],r;
main(){
  scanf(" %s %s",x,y);
  n=strlen(x);
  for(int i=0;i<n;i++)if(x[i]!=y[i])++a[x[i]>y[i]];
  printf("%d\n",a[0]+a[1]-min(a[0],a[1]));
}