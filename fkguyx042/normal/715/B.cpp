#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<queue>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 1005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
priority_queue<pair<int,int> >Q;
int i,j,m,n,p,k,k1=1,L,st,t,x,y,w,fox[N],fa[N],dis[N],vis[N];
struct Node{int ed,before,cost,id;}s[M]; 
void dij()
{
		while (!Q.empty()) Q.pop();
		memset(dis,60,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int i;
		dis[st]=0;
		Q.push(mk(0,st));
		for (;!Q.empty();)
		{
				int x=Q.top().se; Q.pop();
				if (vis[x]) continue;
				vis[x]=1;
				for (i=fox[x];i;i=s[i].before)
				{
						int k=s[i].ed;
						if (dis[x]+s[i].cost<dis[k]) 
						dis[k]=dis[x]+s[i].cost,fa[k]=i,Q.push(mk(-dis[k],k));
				}
		}
}
void add(int x,int y,int w,int id)
{
	s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=w; s[k1].id=id;
	s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].cost=w; s[k1].id=id;
}
int main()
{ 
	scanf("%d%d%d%d%d",&n,&m,&L,&st,&t);
	for (;m--;)
	{
		scanf("%d%d%d",&x,&y,&w);
		if (w==0)
		add(x,y,L+1,1);
		else 
		add(x,y,w,0);
	}
	dij();
	if (dis[t]<L) { puts("NO"); return 0; }
	for (i=2;i<=k1;++i) if (s[i].id) s[i].cost=1;
	dij();
	if (dis[t]>L) { puts("NO"); return 0; }
	for (;dis[t]<L;)
	{
			for (i=t;;i=s[p^1].ed)
			{
					p=fa[i];
					if (s[p].id) break; 
			}
			s[p].cost+=L-dis[t];
			s[p^1].cost+=L-dis[t];
			dij();
	}
	puts("YES");
	for (i=0;i<n;++i) 
		for (j=fox[i];j;j=s[j].before)
			if (i<s[j].ed) printf("%d %d %d\n",i,s[j].ed,s[j].cost);
}