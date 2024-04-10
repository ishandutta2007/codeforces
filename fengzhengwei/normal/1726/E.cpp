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
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
char s[xx];
int id[xx],iv[xx];

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
ll cc[xx];
int main(){
//	freopen("a.in","w",stdout);
	pre();
	int T=read();
//	cout<<200<<"\n";
	for(int n=1;n<=100;n++)
	{
		ll ans=0;
		for(int a=0;a+a<=n;a++)
		{
			ans+=C(n,a+a)*C(a+a,a)%mod*jiec[a]%mod*ksm(ksm(2,a),mod-2)%mod;
			ans%=mod;
		}
		cc[n]=ans;
	//	cout<<ans<<" ";
	}
	for(int i=101;i<xx;i++)
		cc[i]=cc[i-1]+(i-1)*(cc[i-2]),cc[i]%=mod,cc[i]+=mod,cc[i]%=mod;
	//for(int n=101;n<=200;n++)cout<<cc[n]<<" ";
	cc[0]=1;
//	exit(0);
	while(T--)
	{
		int n=read();
		ll ans=0;
		for(int a=0;a*4<=n;a++)
		{
			// 
//			cerr<<a<<" "<<cc[n-4*a]*C(n,4*a)%mod*C(a+a,a)%mod*jiec[a]%mod<<"$$\n";
			ans+=cc[n-4*a]*C(n-4*a+2*a,2*a)%mod*C(a+a,a)%mod*jiec[a]%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
	
//	random_device R;
//	mt19937 G(R());
//	int n=read();
//	int re=0;
//	for(int i=1;i<=n;i++)id[i]=i;
////	shuffle(id+1,id+n+1,G);
////	swap(id[1],id[5]);
//	int T=jiec[n];
//	while(T--)
//	{
//		for(int i=1;i<=n;i++)iv[id[i]]=i;
//		int cr=1;
////		for(int i=1;i<=n;i++)if(id[i]!=i&&!(id[id[i]]==i)&&abs(id[i]-i)>5)cr=1;
//		for(int i=1;i<=n;i++)if(abs(id[i]-iv[i])>1)cr=0;
//		if(cr)
//		{
//			re++;
////			for(int i=1;i<=n;i++)cout<<id[i]<<" ";
////			puts("");
////			break;
//		}
//		next_permutation(id+1,id+n+1);
//	}
//	cout<<re<<"\n";
	pc('1',1);
	return 0;
}