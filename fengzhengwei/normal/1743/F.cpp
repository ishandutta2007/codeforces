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

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=2e6+5,mod=998244353;
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

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];
struct mat
{
	const static int lim=2;
	ll a[lim][lim];
	mat operator*(const mat&w)const
	{
		mat c;
		memset(c.a,0,sizeof(c.a));
		for(int i=0;i<lim;i++)
		{
			for(int k=0;k<lim;k++)
			{
				ll T=a[i][k];
				for(int j=0;j<lim;j++)
					c.a[i][j]=(c.a[i][j]+T*w.a[k][j])%mod;
			}
		}
		return c;
	}
}tag[xx];
void build(int k,int l,int r)
{
	tag[k]={1,0,0,1};
	if(l==r)return tag[k]={1,0,0,0},void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void ad(int k,const mat&z){(tag[k]=tag[k]*z);}
void pd(int k){ad(k<<1,tag[k]),ad(k<<1|1,tag[k]),tag[k]={1,0,0,1};}
void cg(int k,int l,int r,int x,int y,const mat&z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return /*cerr<<l<<" "<<r<<" "<<sm[524289]<<"!\n",*/ad(k,z),
void();
	pd(k);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
}
ll ans;
void ask(int k,int l,int r)
{
	auto z=tag[k];
//if(l==r)
//cerr<<k<<" "<<l<<" "<<r<<" "<<z.a[0][0]<<" "<<z.a[0][1]<<" "<<z.a[1][0]<<" "<<z.a[1][1]<<" "<<tag[k].a[0][0]<<" "<<tag[k].a[0][1]<<" "<<tag[k].a[1][0]<<" "<<tag[k].a[1][1]<<"##\n";
	if(l==r)return (ans+=tag[k].a[0][1])%=mod,/*(tag[k].a[0][1]?cerr<<tag[k].a[0][1]<<" "<<l<<"    ",0:0),*/void();
	pd(k);
	int mid=l+r>>1;
	ask(k<<1,l,mid);
	ask(k<<1|1,mid+1,r);
}
char s[xx];
int main(){
	
	int T=1;
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	//	for(int i=1;i<=n;i++)
	//		cerr<<a[i]<<" "<<b[i]<<"%%%\n";
//		ll ans=0;
		//   
		build(1,0,3e5);
		// 
		//a 
		// 
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				cg(1,0,3e5,a[i],b[i],{0,1,0,1});
			}
			else 
			{
				cg(1,0,3e5,0,a[i]-1,{3,0,1,2});
				cg(1,0,3e5,a[i],b[i],{1,2,1,2});
				cg(1,0,3e5,b[i]+1,3e5,{3,0,1,2});
			}
		}
//		for(int i=n;i>=1;i--)
//		{
//			if(i!=n)
//			{
//				cg(1,0,3e5,0,a[i]-1);
//				cg(1,0,3e5,b[i]+1,3e5);
//			}
//			int num=max(0,i-2);
//		//	cerr<<a[i]<<" "<<b[i]<<"%%%\n";
//			// 
//			re=0;ask(1,0,3e5,a[i],b[i]),re%=mod;
////			cerr<<re<<"$\n";
//			(ans+=re*ksm(3,num))%=mod;
////			cerr<<num<<" "<<ksm(3,num)<<"#\n";
//		}
		ask(1,0,3e5);
		cout<<ans<<"\n";
		
		
//		if(cr){puts("Yes");continue;}
//		else {puts("No");continue;}
		
		
//		ct  
	}
	pc('1',1);
	return 0;
}