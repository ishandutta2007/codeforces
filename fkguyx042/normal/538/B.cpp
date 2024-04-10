#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int sum[105],ans[100005],i,n,f[1000005],last[1000005],j;
void dfs(int x)
{
	  if (x>n) return;
	  sum[++sum[0]]=x;
	  dfs(x*10);
	  dfs(x*10+1);
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	sort(sum+1,sum+sum[0]+1);
	memset(f,60,sizeof(f)); f[0]=0;
	for (i=1;i<=sum[0];++i)
	    for (j=0;j+sum[i]<=n;++j)
	        if (f[j]+1<f[j+sum[i]])
	        {
	        	 f[j+sum[i]]=f[j]+1;
	        	 last[j+sum[i]]=sum[i];
	        }
	printf("%d\n",f[n]);
	for (;n;n-=last[n]) printf("%d ",last[n]);
}