#include<bits/stdc++.h>
using namespace std;
const int N=14;
int g[N][N][1<<N],p[N][N][1<<N],f[1<<N],px[1<<N],py[1<<N],ps[1<<N],n,m;
vector<int>e[N];
inline int bs(int x){return __builtin_popcount(x);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	for(int i=0;i<n;i++)
	{
		for(auto j:e[i])
		{
			g[i][j][0]=1;
			p[i][j][0]=i;
		}
	}
	for(int s=0;s<(1<<n);s++)
	{
		for(int i=0;i<n;i++)
		{
			if(s&(1<<i))
				continue;
			for(int j=0;j<n;j++)
			{
				if(s&(1<<j))
					continue;
				if(!g[i][j][s])
					continue;
				for(auto k:e[j])
				{
					if(p[i][j][s]==k)
						continue;
					int t=s+(1<<j);
					if(!g[i][k][t])
					{
						g[i][k][t]=1;
						p[i][k][t]=j;
					}
				}
			}
		}
	}
	for(int s=1;s<(1<<n);s++)
	{
		f[s]=1e9;
		if(bs(s)==1)
		{
			f[s]=0;
			continue;
		}
		for(int t=s;t;t=(t-1)&s)
		{
			int r=s^t;
			for(int x=0;x<n;x++)
			{
				if(!(t&(1<<x)))
					continue;
				for(int y=0;y<n;y++)
				{
					if(!(t&(1<<y)))
						continue;
					if(!g[x][y][r])
						continue;
					int c=bs(r)+1;
					if(f[s]>f[t]+c)
					{
						f[s]=f[t]+c;
						px[s]=x;
						py[s]=y;
						ps[s]=r;
					}
				}
			}
		}
	}
	printf("%d\n",f[(1<<n)-1]);
	int s=(1<<n)-1;
	while(bs(s)>1)
	{
		int t=ps[s],x=px[s],y=py[s];
		s-=t;
		while(t)
		{
			int z=p[x][y][t];
			printf("%d %d\n",y+1,z+1);
			t-=(1<<z);
			y=z;
		}
		printf("%d %d\n",x+1,y+1);
	}
	return 0;
}