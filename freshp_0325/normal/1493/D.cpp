#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<pair<int,int> > G[200005];
const int MOD=1e9+7;
int root[200005];
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define Mm int mid=(l+r)>>1
bool ip[200005];
int cnt,prime[200005],sjc;
typedef long long LL;
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
LL ans=1;
struct node{
	int lc,rc,val;
}nd[14000005];
void shai(int up)
{
	for(int i=2;i<=up;++i)
	{
		if(!ip[i])	prime[++cnt]=i,root[i]=++sjc;
		for(int j=1;j<=cnt && prime[j]*i<=up;++j)
		{
			ip[prime[j]*i]=true;
			if(i%prime[j]==0)	break;
		}
	}
	for(int i=1;i<=cnt;++i)
	{
		for(int j=1;prime[i]*j<=up;++j)
		{
			int tmp=j,calc=0;
			while(tmp%prime[i]==0)	tmp/=prime[i],++calc;
			G[prime[i]*j].push_back(mp(prime[i],calc+1));
		}
	}
}
void push_up(int now){nd[now].val=min(nd[nd[now].lc].val,nd[nd[now].rc].val);}
void modify(int now,int l,int r,int x,int y)
{
	if(l==r)
	{
		nd[now].val+=y;
		return ;
	}
	Mm;
	if(x<=mid)
	{
		if(!nd[now].lc)	nd[now].lc=++sjc;
		modify(nd[now].lc,l,mid,x,y);
	}
	else
	{
		if(!nd[now].rc)	nd[now].rc=++sjc;
		modify(nd[now].rc,mid+1,r,x,y);
	}
	push_up(now);
}
int query(int now){return nd[now].val;}
int n,q;
void update(int x,int y)
{
	for(unsigned int i=0;i<G[y].size();++i)
	{
		int a=G[y][i].first,b=G[y][i].second;
		int val=nd[root[a]].val;
		modify(root[a],1,n,x,b);
		(ans*=QuickPow(a,nd[root[a]].val-val))%=MOD;
	}
}
//void modify()
int main(){
	shai(200003);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	while(q-->0)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		update(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}