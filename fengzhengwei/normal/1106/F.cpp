#include<bits/stdc++.h>
#define ll long long
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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=102,mod=998244353;
int n;
struct mat
{
	//fi 
	ll a[xx][xx];
	mat(){memset(a,0,sizeof(a));}
	void init(){*this=mat();for(int i=1;i<=n;i++)a[i][i]=1;}
	mat operator*(const mat&w)const
	{
		mat c;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				for(int j=1;j<=n;j++)
					c.a[i][j]+=a[i][k]*w.a[k][j]%(mod-1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)c.a[i][j]%=(mod-1);
		return c;
	}
	
}ans,zy;
int b[xx],f[xx];
map<int,int>mp;
int gind(int M)
{
	int sq=31623;
	//g^?=M 
	int now=1;
	mp[now]=0;
	for(int i=1;i<=sq;i++)
		now=1ll*now*3%mod,mp[1ll*now*M%mod]=i;
	int lin=1;
	for(int i=1;i<=sq;i++)
	{
		lin=1ll*lin*now%mod;
		if(mp.find(lin)!=mp.end())return i*sq-mp[lin];
	}
	assert(0);
	return 0;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	int X=y,Y=x-(a/b)*y;
	x=X,y=Y;
}
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
int main(){
	//1a/qd 
	n=read();
	ans.init();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)
		zy.a[i][1]=b[i];
	for(int i=1;i<n;i++)zy.a[i][i+1]=1;
	int N=read(),M=read();
	if(M==1)cout<<1<<"\n",exit(0);
	N-=n;
	while(N)
	{
		if(N&1)ans=ans*zy;
		zy=zy*zy,N>>=1;
	}
	// 
	// 
	int alf=ans.a[1][1],im=gind(M);
	int x,y,d;
	if(im%(d=gcd(alf,mod-1))!=0)puts("-1"),exit(0);
	exgcd(alf,mod-1,x,y);
//	cout<<x<<" "<<alf<<" "<<M<<" "<<im e<<" "<<ksm(3,im)<<" "<<d<<" "<<x<<" "<<y<<"ASD\n";
	x=1ll*x*im/d%((mod-1)/d),x%=(mod-1)/d,x+=(mod-1)/d,x%=(mod-1)/d;
	cout<<ksm(3,x)<<"\n";
	pc('1',1);
	return 0;
}