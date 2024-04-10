#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+10;
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
int head[N],nex[N],to[N];
int cnt,dis[N],ans[N];
queue<int>q;
bitset<N>b;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int x)
{
	b[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(dis[t]<=dis[x])continue;
		if(!b[t])dfs(t);
		ans[x]=min(ans[x],ans[t]);
	}
}
void solve()
{
	int n=read(),m=read();
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		head[i]=b[i]=0;
	}
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v);
	}
	for(int i=2;i<=n;++i)dis[i]=1<<30;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nex[i])
		{
			int t=to[i];
			if(dis[x]+1<dis[t])
			{
				dis[t]=dis[x]+1;
				q.push(t);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		ans[i]=dis[i];
		for(int j=head[i];j;j=nex[j])
		{
			int t=to[j];
			ans[i]=min(ans[i],dis[t]);
		}
	}
	dfs(1);
	for(int i=1;i<=n;++i)write(ans[i],' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}