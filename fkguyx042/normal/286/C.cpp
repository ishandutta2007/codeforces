#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005
using namespace std;
int i,j,m,n,p,k,E[N],b[N],x,stack[N];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&b[i]);
	scanf("%d",&m);
	for (;m--;)
	{
		 scanf("%d",&x);
		 b[x]*=-1;
	}
	for (i=n;i;--i)
	  if (!stack[0]||b[i]<0||stack[stack[0]]!=b[i])
	  	  stack[++stack[0]]=abs(b[i]),E[i]=-1;
	  	  else stack[0]--,E[i]=1;
	if (stack[0]) printf("NO\n");
	else 
	{
		  printf("YES\n");
		  for (i=1;i<=n;++i) printf("%d ",abs(b[i])*E[i]);
	}
}