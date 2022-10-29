#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[4005];
int i,j,a[3],n;
int main()
{
	 scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	 memset(f,60,sizeof(f));
	 f[0]=0; for (i=1;i<=n;++i) f[i]=-f[i];
	 for (j=0;j<3;++j)
	 for (i=0;i<=n;++i)
	   if (i+a[j]<=n) f[i+a[j]]=max(f[i+a[j]],f[i]+1);
	 printf("%d\n",f[n]);
}