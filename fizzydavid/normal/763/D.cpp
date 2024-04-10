//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
typedef unsigned long long ull;
ull bigrand(){return (1ull*rand())<<40|(1ull*rand())<<20|rand();}
map<ull,ull>hmp;
ull getid(ull x)
{
	if(hmp.find(x)==hmp.end())return hmp[x]=bigrand();
	else return hmp[x];
}
ull hs[100111],rhs[100111];
int n,head[100111],nxt[200111],to[200111],tot=1;
void dfs(int x,int pre=-1)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre)continue;
		dfs(to[i],x);
		hs[x]+=hs[to[i]];
	}
	hs[x]=getid(hs[x]);
}
void rdfs(int x,int pre=-1)
{
	ull sum=0;
	if(x!=1)sum+=rhs[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre)continue;
		sum+=hs[to[i]];
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==pre)continue;
		rhs[to[i]]=getid(sum-hs[to[i]]);
		rdfs(to[i],x);
	}
}
map<ull,int> mp;
int cur,ans,ansid=1;
void add(ull x){cur+=((mp[x]++)==0);}
void del(ull x){cur-=((--mp[x])==0);}
void solve(int x,int pre=-1)
{
	if(cur>ans)ans=cur,ansid=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(pre==to[i])continue;
		del(hs[to[i]]);
		add(rhs[to[i]]);
		solve(to[i],x);
		add(hs[to[i]]);
		del(rhs[to[i]]);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	srand(time(NULL));
	hmp[0]=bigrand();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
	}
	dfs(1);
	rdfs(1);
	for(int i=2;i<=n;i++)add(hs[i]);
	solve(1);
//	cout<<ans<<" ";
	cout<<ansid<<endl;
	return 0;
}