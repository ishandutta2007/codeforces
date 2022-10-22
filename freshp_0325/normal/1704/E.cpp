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
const LL MOD=998244353;
inline LL Add(LL x,LL y){return x+y>=MOD?x+y-MOD:x+y;}
inline LL Sub(LL x,LL y){return x<y?x-y+MOD:x-y;}
inline LL Mul(LL x,LL y){return 1ll*x*y%MOD;}
inline LL add(LL &x,LL y){return x=Add(x,y);}
inline LL sub(LL &x,LL y){return x=Sub(x,y);}
inline LL mul(LL &x,LL y){return x=Mul(x,y);}
LL QuickPow(LL x,LL p=MOD-2)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
LL n,m;
LL a[1005],deg[1005],c;
vector<LL> G[1005];
LL d[1005];
void topSort()
{
	queue<LL> Q;
	for(LL i=1;i<=n;++i)	if(!deg[i])	Q.push(i);
	LL cnt=0;
	while(!Q.empty())
	{
		LL u=Q.front();
		Q.pop();
		if(G[u].empty())	c=u;
		d[++cnt]=u;
		for(auto v:G[u])
		{
			--deg[v];
			if(!deg[v])	Q.push(v);
		}
	}
}
bool vis[1005][1005];
LL ans[1005];
void Solve()
{
	n=read(),m=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	for(LL i=1;i<=n;++i)	for(LL j=1;j<=n;++j)	vis[i][j]=false;
	for(LL i=1;i<=n;++i)	G[i].clear();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read();
		G[u].push_back(v);
		++deg[v];
	}
	for(LL i=1;i<=n;++i)
	{
		ans[i]=a[i];
		for(LL j=1;j<=min(n,a[i]);++j)	vis[i][j]=true;
	}
	topSort();
	for(LL i=1;i<=n;++i)
	{
		LL u=d[i];
		for(auto v:G[u])
		{
			LL t=0;
			for(LL j=1;j<n;++j)
			{
				if(vis[u][j])
				{
					t=max(t,j+1);
					while(t<=n && vis[v][t])	++t;
					if(t<=n)	ans[v]=max(ans[v],t),vis[v][t]=true;
					else	++ans[v];
				}
			}
			if(ans[u]>=n-1)
			{
				ans[v]+=ans[u]-n+1;
				while(ans[v]>=3*MOD)	ans[v]-=MOD;
			}
		}
	}
	write(ans[c]%MOD),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}