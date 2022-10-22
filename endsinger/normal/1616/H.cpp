#include<bits/stdc++.h>
using namespace std;
const int N=150005,mod=998244353;
int n,p,pw[N],rt,lc[N<<5],rc[N<<5],t[N<<5],c,s;
void ins(int &k,int x,int d)
{
	if(!k) k=++c;
	t[k]++;
	if(d<0) return;
	if(x>>d&1) ins(rc[k],x,d-1);
	else ins(lc[k],x,d-1);
}
int sol(int k1,int k2,int d)
{
	if(!k1||!k2||d<0)
		return pw[t[k1]+t[k2]];
	if(p>>d&1)
	{
		int x=sol(lc[k1],rc[k2],d-1),y=sol(rc[k1],lc[k2],d-1);
		return 1ll*x*y%mod;
	}
	else
	{
		int x=sol(lc[k1],lc[k2],d-1),y=sol(rc[k1],rc[k2],d-1);
		x=(x+y-1)%mod;
		x=(x+1ll*(pw[t[lc[k1]]]-1)*(pw[t[rc[k1]]]-1)%mod)%mod;
		x=(x+1ll*(pw[t[lc[k2]]]-1)*(pw[t[rc[k2]]]-1)%mod)%mod;
		return x;
	}
}
void dfs(int k,int d)
{
	if(!k) return;
	if(!p&&d<0) s=(s+pw[t[k]]-1)%mod;
	if(d<0) return;
	if(p>>d&1)
	{
		s=(s+sol(lc[k],rc[k],d-1)-1)%mod;
		return;
	}
	dfs(lc[k],d-1);
	dfs(rc[k],d-1);
}
int main()
{
	scanf("%d%d",&n,&p);
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		ins(rt,x,29);
	}
	dfs(rt,29);
	printf("%d\n",s);
	return 0;
}