#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long LL;
const LL MOD=998244353;
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
LL fac[500005],ifac[500005];
LL C(LL n,LL m){return (n<m || m<0)?0:fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;}
int cnt;
struct fhqTreap{
	int root;
	struct node{
		int ch[2],siz,val,tag,key;
	}fhq[500005];
	#define lc fhq[now].ch[0]
	#define rc fhq[now].ch[1]
	int newnode(int val){
	return ++cnt,
	fhq[cnt].ch[0]=fhq[cnt].ch[1]=fhq[cnt].tag=0,
	fhq[cnt].siz=1,fhq[cnt].val=val,
	fhq[cnt].key=rand(),
	cnt;}
	void push_down(int now)
	{
		if(!now)	return ;
		if(fhq[now].tag)
		{
			if(lc)	fhq[lc].val+=fhq[now].tag,fhq[lc].tag+=fhq[now].tag;
			if(rc)	fhq[rc].val+=fhq[now].tag,fhq[rc].tag+=fhq[now].tag;
			fhq[now].tag=0;
		}
	}
	void push_up(int now){if(now)	fhq[now].siz=fhq[lc].siz+fhq[rc].siz+1;}
	void split(int now,int val,int &x,int &y)
	{
		if(!now)	x=y=0;
		else
		{
			push_down(now);
			if(val>=fhq[now].val)
			{
				x=now;
				split(rc,val,rc,y);
			}
			else
			{
				y=now;
				split(lc,val,x,lc);
			}
			push_up(now);
		}
	}
	int merge(int x,int y)
	{
		if(!x || !y)	return x+y;
		if(fhq[x].key>fhq[y].key)
		{
			push_down(x);
			fhq[x].ch[1]=merge(fhq[x].ch[1],y);
			push_up(x);
			return x;
		}
		else
		{
			push_down(y);
			fhq[y].ch[0]=merge(x,fhq[y].ch[0]);
			push_up(y);
			return y;
		}
	}
	bool check(int val,int now)
	{
		if(!now)	return false;
		if(fhq[now].val==val)	return true;
		push_down(now);
		if(val<fhq[now].val)	return check(val,lc);
		return check(val,rc);
	}
}tr;
int n,m,x[500005],y[500005];
void Solve()
{
	scanf("%d %d",&n,&m);
	tr.root=cnt=0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
		int tx,ty;
		bool st=tr.check(y[i],tr.root);
		tr.split(tr.root,y[i]-1,tx,ty);
		if(ty)	++tr.fhq[ty].val,++tr.fhq[ty].tag;
		if(st)	tr.root=tr.merge(tx,ty);
		else	tr.root=tr.merge(tr.merge(tx,tr.newnode(y[i]+1)),ty);
	}
	printf("%lld\n",C(2*n-cnt-1,n));
}
int main(){
	srand(time(NULL));
	fac[0]=1;
	for(LL i=1;i<=400000;++i)	fac[i]=fac[i-1]*i%MOD;
	ifac[400000]=QuickPow(fac[400000],MOD-2);
	for(LL i=399999;~i;--i)	ifac[i]=ifac[i+1]*(i+1)%MOD;
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}