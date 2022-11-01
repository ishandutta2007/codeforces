#include<bits/stdc++.h>
#define l first
#define r second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,int>pli;
const int N=8E5+10,M=3.6E6+10;
ll read()
{
    ll a=0;
	char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[M],to[M],val[M],cnt,n;
ll dis[N];
priority_queue<pli,vector<pli>,greater<pli> >q;
void add(int u,int v,int w)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
}
void addd(int u,int v,int w)
{
	add(u,v,w);
	add(u,v+n,0);
	add(u,v+n*2,w<<1);
	add(u,v+n*3,w);
	add(u+n,v+n,w);
	add(u+n,v+n*3,w<<1);
	add(u+n*2,v+n*2,w);
	add(u+n*2,v+n*3,0);
	add(u+n*3,v+n*3,w);
}
int main()
{
	n=read();
	for(int m=read();m--;)
	{
		int u=read(),v=read(),w=read();
		addd(u,v,w);
		addd(v,u,w);
	}
	q.push(mp(0,1));
	memset(dis,127,sizeof dis);
	dis[1]=0;
	while(!q.empty())
	{
		int x=q.top().r;
		ll y=q.top().l;
		q.pop();
		if(dis[x]!=y)continue;
		for(int i=head[x];i;i=nex[i])
		{
			int t=to[i];
			if(y+val[i]<dis[t])
			{
				dis[t]=y+val[i];
				q.push(mp(dis[t],t));
			}
		}
	}
	for(int i=2;i<=n;++i)write(dis[i+n*3],' ');
}