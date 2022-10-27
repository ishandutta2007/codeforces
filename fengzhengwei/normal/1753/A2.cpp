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

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];
char s[xx];
int f[xx][2];
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int re=0;
		for(int i=1;i<=n;i++)re+=abs(a[i]);
		if(re&1)
		{
			puts("-1");
			continue;
		}
		int te=0;
		for(int i=1;i<=n;i++)te+=a[i];
		for(int i=1;i<=n;i++)b[i]=1;
		vector<int>ans;
		if(te>0);
		else 
		{
			for(int i=1;i<=n;i++)a[i]*=-1;
		}
		te=0;
		for(int i=1;i<=n;i++)te+=a[i];
		f[0][1]=0,f[0][0]=1e9;
		// -1  a=1  
		for(int i=1;i<=n;i++)
		{
			f[i][0]=min(f[i-1][0],f[i-1][1]);
			f[i][1]=f[i-1][0]-a[i]*2;
		}
		if(min(f[n][1],f[n][0])+te<=0)
		{
			int x=n,y=1;
			if(f[n][1]>f[n][0])y=0;
			while(x!=0)
			{
				if(y==1)b[x]=-1,y=0,--x;
				else 
				{
					if(f[x-1][0]<f[x-1][1])--x,y=0;
					else --x,y=1;
				}
			}
			vector<int>v;
			int res=0;
			for(int i=1;i<=n;i++)res+=b[i]*a[i];
			for(int i=1;i<=n;i++)
			{
				if(res<0&&b[i]==-1)
				{
					res-=b[i]*a[i];
					b[i]=1;
					res+=b[i]*a[i];
				}
			}
			for(int i=1;i<=n;i++)if(b[i]==1)v.push_back(i);
			cout<<v.size()<<"\n";
			for(int i=0;i<(int)v.size()-1;i++)
				cout<<v[i]<<" "<<v[i+1]-1<<"\n";
			cout<<v.back()<<" "<<n<<"\n";
		}
		else 
			puts("-1");
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
	}
	pc('1',1);
	return 0;
}