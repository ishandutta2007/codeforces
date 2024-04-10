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
int n,m,k,q,a[xx],b[xx];

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
char s[xx];
struct nod
{
	int a,b;
}e[xx];
ll ans;

int Lim;

namespace t0
{
	int Mn[xx<<2],adt[xx<<2];
	void ad(int k,int z){Mn[k]+=z,adt[k]+=z;}
	void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
	
	void build(int k,int l,int r)
	{
		adt[k]=0;
		if(l==r)
		{
			if(e[l].b==0)Mn[k]=e[l].a;
			else Mn[k]=1e9+5e8;
			return ;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		Mn[k]=min(Mn[k<<1],Mn[k<<1|1]);
	}
	void cg(int k,int l,int r,int x,int y,int z)
	{
		if(x>y)return;
		if(x<=l&&r<=y)return ad(k,z);
		pd(k);int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,y,z);
		if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
		Mn[k]=min(Mn[k<<1],Mn[k<<1|1]);
	}
	void Set(int k,int l,int r,int x)
	{
		if(l==r)return Mn[k]=1e9+5e8,void();
		pd(k);int mid=l+r>>1;
		if(x<=mid)Set(k<<1,l,mid,x);
		else Set(k<<1|1,mid+1,r,x);
		Mn[k]=min(Mn[k<<1],Mn[k<<1|1]);
	}
	int Get(int k,int l,int r)
	{
		if(l==r)return l;
		pd(k);int mid=l+r>>1;
		if(Mn[k<<1]==Mn[k])return Get(k<<1,l,mid);
		return Get(k<<1|1,mid+1,r);
	}
	void up(int val,int l,int r,int op)
	{
		int ans=n+1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(e[mid].a>val)ans=mid,r=mid-1;
			else l=mid+1;
		}
		cg(1,1,n,ans,n,op);
	}
}
namespace t1
{
	int Mx[xx<<2],adt[xx<<2];
	void ad(int k,int z){Mx[k]+=z,adt[k]+=z;}
	void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
	
	void build(int k,int l,int r)
	{
		adt[k]=0;
		if(l==r)
		{
			if(e[l].b==1)Mx[k]=e[l].a;
			else Mx[k]=-1e9-5e8;
			return ;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		Mx[k]=max(Mx[k<<1],Mx[k<<1|1]);
	}
	void cg(int k,int l,int r,int x,int y,int z)
	{
		if(x>y)return;
		if(x<=l&&r<=y)return ad(k,z);
		pd(k);int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,y,z);
		if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
		Mx[k]=max(Mx[k<<1],Mx[k<<1|1]);
	}
	void Set(int k,int l,int r,int x)
	{
		if(l==r)return Mx[k]=-1e9-5e8,void();
		pd(k);int mid=l+r>>1;
		if(x<=mid)Set(k<<1,l,mid,x);
		else Set(k<<1|1,mid+1,r,x);
		Mx[k]=max(Mx[k<<1],Mx[k<<1|1]);
	}
	int Get(int k,int l,int r)
	{
		if(l==r)return l;
		pd(k);int mid=l+r>>1;
		if(Mx[k<<1]==Mx[k])return Get(k<<1,l,mid);
		return Get(k<<1|1,mid+1,r);
	}
	void up(int val,int l,int r,int op)
	{
		int ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(e[mid].a<val)ans=mid,l=mid+1;
			else r=mid-1;
		}
//		cerr<<ans<<"%%\n";
		cg(1,1,n,1,ans,op);
	}
}



//3n
int lb(int x){return x&-x;}
int sum[xx];
int slim;
void add(int x,int y)
{
	for(;x<=slim;x+=lb(x))sum[x]+=y;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=sum[x];
	return ans;
}

struct prs{int x,id;bool operator<(const prs&w)const{return x==w.x?id>w.id:x<w.x;};};


void check(int lim)
{
	Lim=lim;
	ll res=0;
	int rp=0;
	memset(sum,0,sizeof(sum[0])*(3*n+2));
	slim=3*n+1;
	for(int i=1;i<=n;i++)
		if(e[i].b==1&&e[i].a!=lim)rp=i;
	int ct=0;
	for(int i=1;i<=n;i++)if(e[i].a==lim&&e[i].b==1)++ct;
	res=1;
	for(int i=1;i<=n;i++)
	{
		if(e[i].b==0)
		{
			int j=i;
			while(e[j+1].a==e[i].a)j++;
			res*=jiec[j-i+1];
			res%=mod;
			i=j;
		}
	}
//	cerr<<ct<<"$$\n";
	if(ct)res*=C(n,ct),res%=mod,res*=jiec[ct],res%=mod;
	// 0   ,  check  
	for(int i=1;i<=n;i++)add(e[i].a,1);
	priority_queue<prs>q;
	t0::build(1,1,n);
	t1::build(1,1,n);
	int lp=0;
	for(int i=1;i<=n;i++)if(e[i].b==0){lp=i;break;}
	using t0::Mn;
	using t1::Mx;
	for(int i=1;i<=n;i++)t0::up(e[i].a,lp,n,1);
	for(int i=1;i<=n;i++)t1::up(e[i].a,1,rp,1);
	
//	cout<<Mn[1]<<" "<<Mx[1]<<"$%$\n";
	// /qd  
	int re=0;
	while(q.size()||Mn[1]==Lim||Mx[1]==Lim)
	{
		if(Mn[1]<Lim)break;
		if(Mx[1]>Lim)break;
		while(Mn[1]==Lim)
		{
			int id=t0::Get(1,1,n);
			t0::Set(1,1,n,id);
			q.push({e[id].a,id});
		}
		while(Mx[1]==Lim)
		{
			int id=t1::Get(1,1,n);
//			if(n==634)cout<<id<<"##\n";
			t1::Set(1,1,n,id);
			q.push({e[id].a,id});
		}
//		cerr<<q.size()<<" "<<Mn[1]<<" "<<Mx[1]<<"$$\n";
		// 0 1  1  /qd  
		if(q.size())
		{
			int x=q.top().id;
			q.pop();
//			cout<<x<<"!!\n";
//			cerr<<((e[x].b==0&&ask(e[x].a-1)+e[x].a!=Lim)||(e[x].b==1&&ask(slim)-ask(e[x].a)+e[x].a!=Lim))<<"$$\n";
			if((e[x].b==0&&ask(e[x].a-1)+e[x].a!=Lim)||(e[x].b==1&&ask(slim)-ask(e[x].a)+e[x].a!=Lim))
			{
//				cerr<<x<<" "<<ask(e[x].a)<<"##\n";
				break;
			}
			add(e[x].a,-1);
			add(lim,1);
			t0::up(e[x].a,lp,n,-1);
			t1::up(e[x].a,1,rp,-1);
			t1::up(lim,1,rp,1);
			++re;
			continue;
		}
		break;
	}
//	if(n==634)cout<<Mn[1]<<" "<<Mx[1]<<"###\n";
	
	if(Mn[1]<1e9||Mx[1]>-1e9)return;
	ans+=res;
}


int main(){
//	freopen(
	pre();
	n=read();
	for(int i=1;i<=n;i++)e[i].a=read();
	for(int i=1;i<=n;i++)e[i].b=read();
	sort(e+1,e+n+1,[&](nod a,nod b){return a.b==b.b?a.a<b.a:a.b>b.b;});
	int mx=-1e9;
	for(int i=1;i<=n;i++)
		if(e[i].b==1)mx=max(mx,e[i].a);
	if(mx==-1e9)mx=e[n].a;
	check(mx);
	if(e[1].b==1&&e[1].a+n-1!=mx)check(e[1].a+n-1);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}