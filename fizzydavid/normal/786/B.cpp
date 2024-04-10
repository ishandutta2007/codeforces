#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
int S,n,m,l[800111],r[800111],id[800111],B;
int head[800111],nxt[8000111],to[8000111],w[8000111],tot=1;
void addedge(int x,int y,int c)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	w[tot]=c;
}
void add(int x,int y,int v,int c,bool f,int p=1)
{
	if(x<=l[p]&&r[p]<=y)
	{
		if(f)addedge(p,id[v],c);
		else addedge(B+id[v],B+p,c);
		return;
	}
	int m=l[p]+r[p]>>1;
	if(x<=m)add(x,y,v,c,f,p<<1);
	if(m<y)add(x,y,v,c,f,p<<1|1);
}
ll dis[800111];
set<pair<ll,int> >st;
void dijkstra()
{
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	st.insert(MP(0,S));
	while(st.size()>0)
	{
		int u=st.begin()->second;
		st.erase(st.begin());
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(dis[v]==-1||dis[u]+w[i]<dis[v])
			{
				if(dis[v]!=-1)
				{
					st.erase(MP(dis[v],v));
				}
				dis[v]=dis[u]+w[i];
				st.insert(MP(dis[v],v));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&S);
	int N=1;
	while(N<n)N<<=1;
	swap(n,N);
	l[1]=1;
	r[1]=n;
	B=2*n;
	for(int i=2;i<=2*n;i++)
	{
		if(l[i>>1]==r[i>>1])continue;
		int m=l[i>>1]+r[i>>1]>>1;
		if(i&1)l[i]=m+1,r[i]=r[i>>1];
		else l[i]=l[i>>1],r[i]=m;
		if(l[i]==r[i])id[l[i]]=i,addedge(i,i+B,0),addedge(i+B,i,0);
		addedge(i,i>>1,0);
		addedge(B+(i>>1),B+i,0);
	}
	S=id[S];
	for(int i=1;i<=m;i++)
	{
		int t,x,y,z,c;
		scanf("%d%d%d%d",&t,&z,&x,&y);
		if(t==1)addedge(id[z],id[x],y);
		else
		{
			scanf("%d",&c);
			if(t==2)add(x,y,z,c,0);
			else add(x,y,z,c,1);
		}
	}
	dijkstra();
	for(int i=1;i<=N;i++)printf("%I64d ",dis[id[i]]);
	return 0;
}