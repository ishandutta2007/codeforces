#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
vector<LL> G[300005];
bool vis[300005];
LL n,m,cnt,siz,dk[300005];
LL QuickPow(LL x,LL p)
{
	if(p<0)	return 0;
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
void bfs(LL s)
{
	++cnt,++siz;
	queue<LL> Q;
	Q.push(s);
	dk[s]=2;
	vis[s]=true;
	while(!Q.empty())
	{
		LL now=Q.front();
		Q.pop();
		for(unsigned int i=0;i<G[now].size();++i)
		{
			LL to=G[now][i];
			if(vis[to])
			{
				if((dk[now]^dk[to])==0)
				{
					cnt=-1;
					return ;
				}
				continue;
			}
			if(dk[now]&1)	dk[to]=2,++cnt;
			else	dk[to]=1;
			++siz;
			vis[to]=true;
			Q.push(to);
		}
	}
}
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)
	{
		scanf("%lld %lld",&n,&m);
		for(LL i=1;i<=n;++i)	G[i].clear(),vis[i]=false,dk[i]=0;
		for(LL i=1;i<=m;++i)
		{
			LL u,v;
			scanf("%lld %lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		long long ans=1;
		for(LL i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				siz=cnt=0;
				bfs(i);
				if(cnt==-1)
				{
					puts("0");
					goto reset;
				}
				ans=(QuickPow(2,cnt)+QuickPow(2,siz-cnt))%MOD*ans%MOD;
			}
		}
		printf("%lld\n",ans);
		reset:;
	}
	return 0;
}