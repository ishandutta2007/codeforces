#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
struct pr{int x,y;};
int n,m,k,d,a[xx],b[xx];
char s[xx];
struct nod
{
	int siz;
	ll sum;
}e[xx<<2];
ll adt[xx<<2];
void ad(int k,ll z)
{
//	if(e[k].siz&&z)cout<<"!!@!@\n"
//;
//	cerr<<k<<"%%\n";
	e[k].sum+=1ll*z*e[k].siz,adt[k]+=z;
}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
nod upd(const nod&a,const nod&b){return {a.siz+b.siz,a.sum+b.sum};}
nod ask(int k,int l,int r,int x,int y)
{
//	cerr<<k<<" "<<l<<" "<<r<<"$\n";
	x=max(x,1),y=min(y,(int)2e5);
	if(x>y)return {0,0};
	if(x<=l&&r<=y)return e[k];
	pd(k);int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
//	cerr<<k<<' '<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<" "<<e[k].siz<<"$$\n";
	x=max(x,1),y=min(y,(int)2e5);
//	cerr<<k<<' '<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<" "<<e[k].siz<<"$$\n";
	if(x<=l&&r<=y)
	{
//	cerr<<k<<' '<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<" "<<e[k].siz<<"$$\n";
		
	ad(k,z);
//	cerr<<k<<' '<<l<<" "<<r<<" "<<e[k].sum<<" "<<e[k].siz<<" "<<z<<"##\n";
	return void();
	}
	pd(k);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void one(int k,int l,int r,int x)
{
	if(l==r)return e[k].siz^=1,void();
	pd(k);int mid=l+r>>1;
	if(x<=mid)one(k<<1,l,mid,x);
	else one(k<<1|1,mid+1,r,x);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void printsz(int k,int l,int r)
{
//	cerr<<k<<" "<<l<<" "<<r<<"$\n";
	if(l==r&&l<=10)
	{
		cout<<e[k].siz<<" ";
		return;
	}
	if(l==r)return;
	pd(k);int mid=l+r>>1;
	printsz(k<<1,l,mid);
	printsz(k<<1|1,mid+1,r);
}

void printsm(int k,int l,int r)
{
	if(l==r&&l<=10)
	{
		cout<<e[k].sum<<" ";
		return;
	}
	if(l==r)return;
	pd(k);int mid=l+r>>1;
	printsm(k<<1,l,mid);
	printsm(k<<1|1,mid+1,r);
}
int is[xx];
ll ans;
int main(){
	n=read(),d=read();
	int L=2e5;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(!is[a[i]])
		{
			ans+=ask(1,1,L,1,a[i]).sum;
			one(1,1,L,a[i]);
			int sz=ask(1,1,L,a[i]+1,a[i]+d).siz;
			ans+=(1ll*sz*(sz-1))/2;
//			cerr<<sz<<"^^\n";
//			puts("Sm");
//			printsm(1,1,L);
//			puts("");
//			puts("");
			cg(1,1,L,a[i]+1,a[i]+d,-1);
			cg(1,1,L,a[i],a[i],sz);
			sz=ask(1,1,L,a[i]-d,a[i]-1).siz;
			ans+=(1ll*sz*(sz-1))/2;
			cg(1,1,L,a[i]-d,a[i]-1,1);
			cg(1,1,L,a[i],a[i],-sz);
		}
		else 
		{
//			cerr<<ans<<"$\n";
			int sz=ask(1,1,L,a[i]+1,a[i]+d).siz;
//			cerr<<sz<<"@\n";
			ans-=(1ll*sz*(sz-1))/2;
			cg(1,1,L,a[i]+1,a[i]+d,1);
			cg(1,1,L,a[i],a[i],-sz);
			sz=ask(1,1,L,a[i]-d,a[i]-1).siz;
//			cerr<<sz<<"&\n";
			ans-=(1ll*sz*(sz-1))/2;
//			cerr<<ans<<"$\n";
			cg(1,1,L,a[i]-d,a[i]-1,-1);
			cg(1,1,L,a[i],a[i],sz);
			one(1,1,L,a[i]);
//			cerr<<ask(1,1,L,1,a[i]).sum<<"$\n";
			ans-=ask(1,1,L,1,a[i]).sum;
		}
		is[a[i]]^=1;
		cout<<ans<<"\n";
//		cout<<e[1].sum<<"%%\n";
//			puts("Sz");
//			printsz(1,1,L);
//			puts("");
//			puts("");
//			puts("Sm");
//			printsm(1,1,L);
//			puts("");
//			puts("");
//			puts("");
	}
	/*
	int T=read();
	while(T--)
	{
		n=read();
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		cout<<ans<<"\n";
	}*/
	pc('1',1);
	return 0;
}