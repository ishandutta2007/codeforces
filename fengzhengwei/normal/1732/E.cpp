#include<bits/stdc++.h>
#define ll long long
#define int unsigned
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

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod4e9+7998 

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

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,q,a[xx],b[xx];
vector<int>v[(int)5e4+5];
void pre()
{
	for(int i=1;i<=5e4;i++)
		for(int j=i;j<=5e4;j+=i)v[j].push_back(i);
}
int dep[xx];
vector<int>t[(int)2e5+5];
int col[xx],sum[xx];
int calc(int x,int y)
{
	int d=gcd(x,y);
//	assert((x/d)*(y/d));
	return (x/d)*(y/d);
}
int bget(int k,int l,int r)
{
	if(dep[k]<=9&&col[k])
	{
		sum[k]=4e9;
		for(auto it:v[col[k]])
		{
			if(t[k][it]!=4e9)
			{
				sum[k]=min(sum[k],col[k]/it*(t[k][it]/it));
//				if(!sum[k])cerr<<col[k]<<" "<<t[k][it]<<"#\n",assert(0);
			}
		}
		return sum[k];
	}
	if(col[k])
	{
		sum[k]=4e9;
		for(int i=l,d;i<=r;i++)
		{
			d=gcd(col[k],b[i]);
			sum[k]=min(sum[k],col[k]/d*(b[i]/d));
		}
	}
	else 
	{
		int mid=l+r>>1;
		return min(bget(k<<1,l,mid),bget(k<<1|1,mid+1,r));
	}
//	assert(sum[k]);
	return sum[k];
}
void pd(int k,int l,int r)
{
	int mid=l+r>>1;
	if(col[k])col[k<<1]=col[k<<1|1]=col[k],bget(k<<1,l,mid),bget(k<<1|1,mid+1,r);
}
void upd(int k)
{
	sum[k]=min(sum[k<<1],sum[k<<1|1]);
	if(col[k<<1]!=col[k<<1|1])col[k]=0;
	else col[k]=col[k<<1];
}
void build(int k,int l,int r)
{
	if(dep[k]<=9)
	{
		t[k]=vector<int>(5e4+1,4e9);// 1  
		for(int i=l;i<=r;i++)
			for(auto it:v[b[i]])t[k][it]=min(t[k][it],b[i]);
//		return;
	}
	if(l==r)return col[k]=a[l],sum[k]=calc(a[l],b[l]),void();
	int mid=l+r>>1;
	dep[k<<1]=dep[k]+1,dep[k<<1|1]=dep[k]+1;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	upd(k);
}
void cov(int k,int l,int r,int x,int y,int z)
{
//	cerr<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<"$\n";
	if(x<=l&&r<=y)return col[k]=z,bget(k,l,r)/*,cerr<<k<<" "<<l<<" "<<r<<" qqq "<<sum[k]<<"#\n"*/,void();
	pd(k,l,r);int mid=l+r>>1;
	if(x<=mid)cov(k<<1,l,mid,x,y,z);
	if(mid<y)cov(k<<1|1,mid+1,r,x,y,z);
	upd(k);
//	cerr<<k<<" "<<l<<" "<<r<<" "<<sum[k]<<" "<<dep[k]<<" "<<sum[k<<1]<<" "<<sum[k<<1|1]<<"!\n";
}
int ans;
void ask(int k,int l,int r,int x,int y)
{
//	cerr<<k<<" "<<l<<" "<<r<<" "<<sum[k]<<"$\n";
	if(x<=l&&r<=y)
	{
//		if(!col[k])
//		if(!sum[k])cerr<<k<<" "<<l<<" "<<r<<" "<<col[k]<<" "<<bget(k,l,r)<<" "<<dep[k]<<"$\n";
		assert(sum[k]);
		return ans=min(ans,sum[k]),void();
	}
	pd(k,l,r);
	int mid=l+r>>1;
	if(x<=mid)ask(k<<1,l,mid,x,y);
	if(mid<y)ask(k<<1|1,mid+1,r,x,y);
}


random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}


signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	pre();
	// 9  
	n=read(),q=read();
//	n=5e4,q=5e4;
//	for(int i=1;i<=n;i++)a[i]=rd(10,50000);
//	for(int i=1;i<=n;i++)b[i]=rd(10,50000);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(1,1,n);
	
	while(q--)
	{
//		int op=rd(1,2),l=rd(1,n),r=rd(1,n);
//		if(l>r)swap(l,r);
		int op=read(),l=read(),r=read();
		if(op==1)
		{
//			int x=rd(10,50000);
			int x=read();
			cov(1,1,n,l,r,x);
		}
		else 
		{
			ans=4e9;
			ask(1,1,n,l,r);
			cout<<ans<<"\n";
		}
	}
//	while(1);
	pc('1',1);
	return 0;
}