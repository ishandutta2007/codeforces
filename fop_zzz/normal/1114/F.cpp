#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define double long double

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

int pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
//62ge  0~61
const int N=400005;
ll tr[N*4],xs[N*4],rev[62],lazy[N*4],lazy2[N*4],a[N],mo=1e9+7;
char opt[10];
int n,m;
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;return sum;}
inline void Up(int x)
{
	tr[x]=tr[x<<1]*tr[x<<1|1]%mo;
	xs[x]=xs[x<<1]|xs[x<<1|1];
}
inline void Push(int x,int l,int r)
{
	int mid=l+r>>1;
	if(lazy[x]!=1)
	{
		tr[x<<1]=tr[x<<1]*ksm(lazy[x],mid-l+1)%mo;
		tr[x<<1|1]=tr[x<<1|1]*ksm(lazy[x],r-mid)%mo;
		lazy[x<<1]=lazy[x<<1]*lazy[x]%mo;lazy[x<<1|1]=lazy[x<<1|1]*lazy[x]%mo;
		lazy[x]=1;
	}
	if(lazy2[x])
	{
		xs[x<<1]|=lazy2[x];xs[x<<1|1]|=lazy2[x];
		lazy2[x<<1|1]|=lazy2[x];lazy2[x<<1]|=lazy2[x];
		lazy2[x]=0;
	}
}
inline void Upd_tr(int x,int l,int r,int ql,int qr,ll tv)
{
	if(ql<=l&&r<=qr)	{tr[x]=tr[x]*ksm(tv,r-l+1)%mo;lazy[x]=lazy[x]*tv%mo;return;}
	int mid=l+r>>1;
	Push(x,l,r);
	if(ql<=mid)	Upd_tr(x<<1,l,mid,ql,qr,tv);
	if(qr>mid) 	Upd_tr(x<<1|1,mid+1,r,ql,qr,tv);
	Up(x);
}
inline void Upd_xs(int x,int l,int r,int ql,int qr,ll tv)
{
	if(ql<=l&&r<=qr)	{xs[x]|=tv;lazy2[x]=lazy2[x]|tv;return;}
	int mid=l+r>>1;
	Push(x,l,r);
	if(ql<=mid)	Upd_xs(x<<1,l,mid,ql,qr,tv);
	if(qr>mid) 	Upd_xs(x<<1|1,mid+1,r,ql,qr,tv);
	Up(x);
}
inline ll Ask_tr(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x];
	int mid=l+r>>1;
	Push(x,l,r);
	ll tmp=1;
	if(ql<=mid)	tmp*=Ask_tr(x<<1,l,mid,ql,qr);
	if(qr>mid)	tmp=tmp*Ask_tr(x<<1|1,mid+1,r,ql,qr)%mo;
	Up(x);
	return tmp;
}
inline ll Ask_xs(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return xs[x];
	int mid=l+r>>1;
	Push(x,l,r);
	ll tmp=0;
	if(ql<=mid)	tmp|=Ask_xs(x<<1,l,mid,ql,qr);
	if(qr>mid)	tmp|=Ask_xs(x<<1|1,mid+1,r,ql,qr);
	Up(x);
	return tmp;
}
inline void Build(int x,int l,int r)
{
	lazy[x]=1;
	if(l==r)
	{
		tr[x]=a[l];
		For(i,0,61)	
		{
			if(tr[x]%pri[i]==0)	xs[x]|=(1LL<<i);
		}
		return;
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	tr[x]=tr[x<<1]*tr[x<<1|1]%mo;
	xs[x]=xs[x<<1]|xs[x<<1|1];
}

int main()
{
	n=read();m=read();
	For(i,0,61)	rev[i]=ksm(pri[i],mo-2);
	For(i,1,n)	a[i]=read();
	Build(1,1,n);
	For(iii,1,m)
	{
		scanf("%s",opt+1);
		if(opt[1]=='M')
		{
			int l=read(),r=read();ll v=read(),txs=0;
			For(i,0,61)	if(v%pri[i]==0)	txs|=(1LL<<i);
			Upd_tr(1,1,n,l,r,v);Upd_xs(1,1,n,l,r,txs);
		}
		else
		{
			int l=read(),r=read();
			ll tans=Ask_tr(1,1,n,l,r),txs=Ask_xs(1,1,n,l,r);
			For(i,0,61)	if(txs>>i&1)	tans=tans*(pri[i]-1)%mo*rev[i]%mo;///cout<<pri[i]<<' '<<a[2]%pri[i]<<' '<<txs<<endl;
			writeln(tans);
		}
	}
}