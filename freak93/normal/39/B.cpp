#include<cstdio>

using namespace std;

int n,a[500],f[500],d[500],rez,i,j;

void afis(int x)
{
	if(x==0)
		return;
	afis(f[x]);
	printf("%d ",2000+x);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			d[i]=1;
			if(d[i]>d[rez])
				rez=i;
			continue;
		}
		d[i]=-10000;
		for(j=i-1;j;--j)
			if(a[j]==a[i]-1)
			{
				d[i]=d[j]+1;
				f[i]=j;
				break;
			}
		if(d[i]>d[rez])
			rez=i;
	}
	printf("%d\n",d[rez]);
	afis(rez);
}