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
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,fa[N],G[N],ans;

struct Node{
	int x,y,w;
}B[N];

inline bool cmp(Node a,Node b)
{	
		return a.w>b.w;
}

int get(int x)
{
		return fa[x]==x?x:fa[x]=get(fa[x]);
}

int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;++i) scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].w);
		sort(B+1,B+m+1,cmp);
		for (i=1;i<=n;++i) fa[i]=i,G[i]=0;
		for (i=1;i<=m;++i)
		{
				int x=get(B[i].x),y=get(B[i].y);
				if (x==y) 
				{
					if (!G[x]) ans+=B[i].w,G[x]=1;	
				}
				else 
				{
						if (!G[x]||!G[y]) fa[x]=y,G[y]|=G[x],ans+=B[i].w;
				}
		}
		printf("%d\n",ans);
}