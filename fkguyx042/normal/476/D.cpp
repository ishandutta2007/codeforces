#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k;
int main()
{scanf("%d%d",&n,&k);
 n--;
 printf("%d\n",k*(6*n+5));
 for (i=0;i<=n;i++) printf("%d %d %d %d\n",k*(6*i+1),k*(6*i+2),k*(6*i+3),k*(6*i+5));
}