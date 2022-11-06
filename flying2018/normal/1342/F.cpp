#include<iostream>
#include<cstdio>
#include<cstring>
#define N 16
#define M 1<<N
#define inf 100000000
using namespace std;
struct stt{
	int t,u,s;
	stt(int T=0,int U=0,int S=0):t(T),u(U),s(S){}
}pre[N][N][M];
int f[N][N][M],a[N],g[M],id[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int m=(1<<n)-1;
		for(int s=0;s<=m;s++) g[s]=0;
		for(int s=0;s<=m;s++)
			for(int i=0;i<n;i++)
			if(s&(1<<i)) g[s]+=a[i];
		for(int s=0;s<=m;s++)
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++) f[i][j][s]=inf;
		f[0][0][0]=0;
		for(int i=0;i<n;i++)
			for(int u=0;u<n;u++)
				for(int s=0;s<=m;s++)
				if(f[i][u][s]<inf)
					for(int t=s^m;t;t=(t-1)&(s^m))
					if(g[t]>f[i][u][s] && (t>>u))
					{
						int v=u+__builtin_ctz(t>>u)+1;
						if(f[i+1][v][s|t]>g[t])
						{
							f[i+1][v][s|t]=g[t];
							pre[i+1][v][s|t]=stt(i,u,s);
						}
					}
		stt u(-1,-1,-1),v;
		for(int i=n;i>=1 && u.t==-1;i--)
			for(int j=1;j<=n;j++)
				if(f[i][j][m]<inf){u=stt(i,j,m);break;}
		printf("%d\n",n-u.t);
		for(int i=0;i<n;i++) id[i]=i+1;
		for(;u.t;u=v)
		{
			v=pre[u.t][u.u][u.s];
			int t=u.s^v.s;
			for(int i=0;i<n;i++)
			if((t&(1<<i)) && i!=u.u-1)
			{
				printf("%d %d\n",id[i],id[u.u-1]);
				for(int j=i+1;j<n;j++) id[j]--;
			}
		}
	}
	return 0;
}