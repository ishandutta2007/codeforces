#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,ans,a,b;
int main()
{ scanf("%d%d",&n,&m);
  for (a=0;a<=1000;a++) 
    for (b=0;b<=1000;b++)
    if (a*a+b==n&&b*b+a==m) ans++;
    printf("%d\n",ans);
}