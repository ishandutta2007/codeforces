#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define M 14
using namespace std;
int pr[M],cnt,ph,mod;
void pre_work(int n=mod)
{
	ph=n;
	for(int i=2;1ll*i*i<=n;i++)
	if(n%i==0)
	{
		ph=1ll*ph*(i-1)/i%mod;
		pr[++cnt]=i;
		while(n%i==0) n/=i;
	}
	if(n>1) pr[++cnt]=n,ph=1ll*ph*(n-1)/n;
	sort(pr+1,pr+cnt+1);
	cnt=unique(pr+1,pr+cnt+1)-pr-1;
}
int ksm(int a,int b=ph-1)
{
	int r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
	}
	return r;
}
int ci[N<<2][M],val[N<<2],tag[N<<2],els[N<<2];
void set_tag(int u,int *v,int tg=1,int el=1)
{
	for(int i=1;i<=cnt;i++) ci[u][i]+=v[i];
	val[u]=1ll*val[u]*tg%mod;
	tag[u]=1ll*tag[u]*tg%mod;
	els[u]=1ll*els[u]*el%mod;
}
#define mst(x) memset(x,0,sizeof(x))
void push_down(int u)
{
	set_tag(u<<1,ci[u],tag[u],els[u]);
	set_tag(u<<1|1,ci[u],tag[u],els[u]);
	mst(ci[u]);
	tag[u]=els[u]=1;
}
int work(int v,int *c)
{
	for(int i=1;i<=cnt;i++) v=1ll*v*ksm(pr[i],c[i])%mod;
	return v;
}
void update(int u){val[u]=(val[u<<1]+val[u<<1|1])%mod;}
void up_int(int x,int &els,int *c)
{
	for(int i=1;i<=cnt;i++)
		for(;x%pr[i]==0;x/=pr[i]) c[i]++;
	els=x;
}
int a[N];
void build(int u,int l,int r)
{
	tag[u]=els[u]=1;mst(ci[u]);
	if(l==r){val[u]=a[l]%mod; up_int(a[l],els[u],ci[u]); return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	update(u);
}
void insert1(int u,int l,int r,int L,int R,int v,int *c,int el)
{
	if(L>r || l>R) return;
	if(L<=l && r<=R){set_tag(u,c,v,el);return ;}
	push_down(u);
	int mid=(l+r)>>1;
	insert1(u<<1,l,mid,L,R,v,c,el),insert1(u<<1|1,mid+1,r,L,R,v,c,el);
	update(u);
}
void insert2(int u,int l,int r,int p,int v,int *c,int el)
{
	if(l==r)
	{
		els[u]=1ll*els[u]*ksm(el)%mod;
		for(int i=1;i<=cnt;i++) ci[u][i]-=c[i];
		val[u]=work(els[u],ci[u]);
		return;
	}
	push_down(u);
	int mid=(l+r)>>1;
	if(p<=mid) insert2(u<<1,l,mid,p,v,c,el);
	else insert2(u<<1|1,mid+1,r,p,v,c,el);
	update(u);
}
int answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R) return val[u];
	int mid=(l+r)>>1,ans=0;
	push_down(u);
	if(L<=mid) ans+=answer(u<<1,l,mid,L,R);
	if(R>mid) ans=(ans+answer(u<<1|1,mid+1,r,L,R))%mod;
	return ans;
}
int c[M];
int main()
{
	int n,m;
	scanf("%d%d",&n,&mod);
	pre_work();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m --> 0)
	{
		int opt,l,r,x,v;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			mst(c);
			scanf("%d",&x);
			up_int(x,v,c);
			insert1(1,1,n,l,r,x,c,v);
		}
		else if(opt==2)
		{
			mst(c);
			up_int(r,v,c);
			insert2(1,1,n,l,r,c,v);
		}
		else printf("%d\n",answer(1,1,n,l,r));
	}
	return 0;
}