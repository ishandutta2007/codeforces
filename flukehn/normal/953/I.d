module main;

import std.stdio;

int main(string[] argv)
{
	int n,k;
	scanf("%d", &n);
	int [] a = new int[1005];
	int [] b = new int[1005];
	int [] c = new int[1005];
	for(int i = 1; i<=n; i++)
		scanf("%d:%d", &a[i],&b[i]);
	for(int i=1;i<=n;i++)
	{
	
	c[i]=a[i]*60+b[i];//printf("%d ",c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int minn=100000000,pla=0,j;
		for(j=i;j<=n;j++)
		{
			if(c[j]<minn)
			{
				minn=c[j];
				pla=j;
			}
		}
		//printf("pla:%d",pla);
		int t=c[pla];
		c[pla]=c[i];
		c[i]=t;
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
	//printf("%d ",c[i]);
	if(c[i+1]-c[i]>ans) ans=c[i+1]-c[i];
	}
	if(n==1)
	{
		printf("23:59");
		return 0;
	}
	else
	{
	if(1440-c[n]+c[1]>ans) ans=1440-c[n]+c[1];
		ans--;
		printf("%02d:%02d",ans/60,ans%60);
	}
	return 0;
}