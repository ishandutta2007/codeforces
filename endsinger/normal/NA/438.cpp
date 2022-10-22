#include<bits/stdc++.h>
using namespace std;
const int N=256,M=5005;
int n,m,a[N],b[N],c[N],d[N][N],v[M],f[M],h,ans[N];
int x[M][N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=0;i<m;i++)
		if(c[i]>0)
			c[i]--;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=-1;
	for(int i=0;i<m;i++)
		d[a[i]][b[i]]=d[b[i]][a[i]]=i;
	h=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(d[i][j]!=-1&&d[i][k]!=-1&&d[j][k]!=-1)
				{
					for(int z=0;z<m;z++)
						x[h][z]=0;
					v[h]=0;
					if(c[d[i][j]]==-1)
						x[h][d[i][j]]=1;
					else
						v[h]=(v[h]+3-c[d[i][j]])%3;
					if(c[d[i][k]]==-1)
						x[h][d[i][k]]=1;
					else
						v[h]=(v[h]+3-c[d[i][k]])%3;
					if(c[d[j][k]]==-1)
						x[h][d[j][k]]=1;
					else
						v[h]=(v[h]+3-c[d[j][k]])%3;
					h++;
				}
			}
		}
	}
	for(int i=0;i<h;i++)
	{
		f[i]=-1;
		for(int j=0;j<i;j++)
		{
			if(x[i][f[j]])
			{
				int z=3-x[i][f[j]];
				for(int k=0;k<m;k++)
					x[i][k]=(x[i][k]+z*x[j][k])%3;
				v[i]=(v[i]+z*v[j])%3;
			}
		}
		for(int k=0;k<m;k++)
		{
			if(x[i][k])
			{
				f[i]=k;
				break;
			}
		}
		if(f[i]==-1)
		{
			if(v[i])
			{
				puts("-1");
				return;
			}
			continue;
		}
		if(x[i][f[i]]==2)
		{
			for(int k=0;k<m;k++)
				x[i][k]=x[i][k]*2%3;
			v[i]=v[i]*2%3;		
		}
		for(int j=0;j<i;j++)
		{
			if(x[j][f[i]])
			{
				int z=3-x[j][f[i]];
				for(int k=0;k<m;k++)
					x[j][k]=(x[j][k]+z*x[i][k])%3;
				v[j]=(v[j]+z*v[i])%3;
			}
		}
	}
	for(int i=0;i<h;i++)
		if(f[i]!=-1)
			c[f[i]]=v[i];
	for(int i=0;i<m;i++)
		if(c[i]==-1)
			c[i]=0;
	for(int i=0;i<m;i++)
		printf("%d ",c[i]+1);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}