#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 505

#define ls (t<<1)
#define rs ((t<<1)|1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,x[N],y[N],t[N],vis[M][M],q;

const int inf=(int)1e9;

int check(int Ti)
{
		memset(vis,0,sizeof(vis));
		for (i=1;i<=q;++i)
			if (t[i]<=Ti) vis[x[i]][y[i]]=1;
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j)
				vis[i][j]+=vis[i-1][j]+vis[i][j-1]-vis[i-1][j-1];
		for (i=k;i<=n;++i)
			for (j=k;j<=m;++j)
				if (vis[i][j]-vis[i-k][j]-vis[i][j-k]+vis[i-k][j-k]==k*k) return 1;
		return 0;
}

int main()
{
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for (i=1;i<=q;++i) scanf("%d%d%d",&x[i],&y[i],&t[i]);
		if (!check(inf)) puts("-1");
		else 
		{
				int l=0,r=inf,mid=0;
				while ((l+r)>>1!=mid)
				{
						mid=(l+r)>>1;
						if (check(mid)) r=mid;
						else l=mid;
				}
				printf("%d\n",r);
		}
}