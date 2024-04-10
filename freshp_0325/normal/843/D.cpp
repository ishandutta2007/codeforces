#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL cnt;
LL to[100005],val[100005],nxt[100005];
LL siz[100005];
inline void addEdge(LL u,LL v,LL w){++cnt,to[cnt]=v,val[cnt]=w,nxt[cnt]=siz[u],siz[u]=cnt;}
LL n,m,q;
LL dis[100005];
typedef pair<LL,LL> P;
#define mp make_pair
void Dijkstra()
{
	priority_queue<P,vector<P>,greater<P>> Q;
	Q.push(mp(0,1));
	memset(dis,63,sizeof dis);
	dis[1]=0;
	while(!Q.empty())
	{
		P now=Q.top();
		Q.pop();
		LL u=now.second,vl=now.first;
		if(vl>dis[u])	continue;
		for(LL i=siz[u];i;i=nxt[i])
		{
			LL v=to[i],w=val[i];
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				Q.push(mp(dis[v],v));
			}
		}
	}
}
int main(){
//	freopen("hunt.in","r",stdin);
//	freopen("hunt.out","w",stdout);
	n=read(),m=read(),q=read();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read(),w=read();
		addEdge(u,v,w);
	}
	Dijkstra();
	while(q-->0)
	{
		LL op=read();
		if(op==1)
		{
			LL u=read();
			if(dis[u]>=dis[0])	puts("-1");
			else	write(dis[u]),puts("");
		}
		else
		{
			static vector<LL> Out[1000005];
			static LL tag[100005];
			LL k=read();
			for(LL i=1;i<=k;++i)	++val[read()];
			for(LL i=1;i<=n;++i)	tag[i]=k+1;
			Out[0].push_back(1),tag[1]=0;
			for(LL i=0;i<=k;++i)
			{
				while(!Out[i].empty())
				{
					LL u=Out[i].back();
					Out[i].pop_back();
					if(tag[u]^i)	continue;
					for(LL j=siz[u];j;j=nxt[j])
					{
						LL v=to[j],w=dis[u]-dis[v]+val[j];
						if(tag[u]+w<tag[v])
						{
							tag[v]=tag[u]+w;
							Out[tag[v]].push_back(v);
						}
					}
				}
			}
			for(LL i=1;i<=n;++i)	dis[i]+=tag[i],tag[i]=0;
		}
	}
	return 0;
}