#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,k,a[N],b[N],v[N][N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		k=0;
		for(int i=1;i<=m;i++)
		{
			k++;
			a[k]=1;
			b[k]=i;
		}
		for(int i=1;i<=n;i++)
		{
			k++;
			a[k]=i;
			b[k]=m;
		}
		for(int i=m;i>=1;i--)
		{
			k++;
			a[k]=n;
			b[k]=i;
		}
		for(int i=n;i>=1;i--)
		{
			k++;
			a[k]=i;
			b[k]=1;
		}
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				v[i][j]=0;
		for(int i=1;i<=k;i++)
		{
			int x=a[i],y=b[i],f=1;
			for(int dx=-1;dx<=1;dx++)
				for(int dy=-1;dy<=1;dy++)
					if(v[x+dx][y+dy])
						f=0;
			if(f)
				v[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d",v[i][j]);
			puts("");
		}
	}
	return 0;
}