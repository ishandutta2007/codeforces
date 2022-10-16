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
//int f[105][105][2];
map<vector<int>,int>mp;
//1  Alice  
int solve(int i,int j,int A,int s)
{
	if(mp.count({i,j,A,s}))return mp[{i,j,A,s}];
	
//	cerr<<i<<" "<<j<<" "<<A<<" "<<s<<" "<<"$\n";
	if(!i&&!j)return (A&&(!s))||((!A)&&s);
	int ans=0;
	if(A)
	{
		if(i)ans|=(!solve(i-1,j,A^1,s+0));
		if(j)ans|=(!solve(i,j-1,A^1,s^1));
	}
	else 
	{
		if(i)ans|=(!solve(i-1,j,A^1,s+0));
		if(j)ans|=(!solve(i,j-1,A^1,s+0));
	}
//	cerr<<i<<" "<<j<<" "<<A<<" "<<s<<" "<<ans<<"$\n";
	return mp[{i,j,A,s}]=ans;
}
char s[xx];
int main(){
//	for(int i=0;i<=100;i++)
//	{
//		for(int j=0;j<=100;j++)
//		{
//			for(int k=0;k<=1;k++)
//			{
//				if(i==j&&i==0)f[i][j][k]=!(k&1);
//				else 
//				{
//					if(i)f[i][j][k]=!f[i-1][]
//				}
//			}
//		}
//	}
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=abs(read())%2;
			
		}
		auto it=solve(count(a+1,a+n+1,0),count(a+1,a+n+1,1),1,0);
		if(it)puts("Alice");
		else puts("Bob");
//		cout<<<<"\n";
	}
	pc('1',1);
	return 0;
}