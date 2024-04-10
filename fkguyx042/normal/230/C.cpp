#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 105
#define M 10005
#define K 17

using namespace std;

int i,j,m,n,p,k,dis[N][M],w[M*3],l[M*3];

char c[N][M];

int main()
{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i) 
		{
				scanf("%s",c[i]);
				for (j=0;j<m;++j) if(c[i][j]=='1') break;
				if (j==m) 
				{
						puts("-1");
						return 0;
				}
		}
		for (i=0;i<n;++i)
		{
				for (j=0;j<m;++j) w[j]=w[j+m]=w[j+2*m]=c[i][j]-'0';
				int len=3*m;
				for (j=0;j<len;++j)
				{
						if (w[j]||!j) l[j]=j;
						else l[j]=l[j-1];
				}
				for (j=0;j<m;++j) dis[i][j]=j+m-l[j+m];
				for (j=len-1;j>=0;--j)
				{
						if (w[j]) l[j]=j; else l[j]=l[j+1];
				}
				for (j=0;j<m;++j) dis[i][j]=min(dis[i][j],l[j+m]-(j+m));
		}
		int ans=(int)1e9;
		for (i=0;i<m;++i)
		{
				int s=0;
				for (j=0;j<n;++j) s+=dis[j][i];
				ans=min(ans,s);
		}
		printf("%d\n",ans);
}