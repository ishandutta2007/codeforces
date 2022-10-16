#include<bits/stdc++.h>
#define ll long long
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
const int xx=2005;
int n;
struct node
{
	int len,a;
	bool operator<(const node&w)const{return len>w.len;}
}e[xx];
int glen(int x)
{
	int tt=0;
	while(x)++tt,x/=10;
	return tt;
}
const int mod=998244353;
int f[xx][xx][11],g[xx][xx][11];
void add(int &a,int b){(a+=b)>=mod?a-=mod:0;}
ll jiec[xx],ni[xx];
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
ll C(int n,int m)
{
	if(n==m)return 1;
	if(n<m||n<0||m<0)return 0;
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//	cout<<sizeof(f)/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)e[i].a=read(),e[i].len=glen(e[i].a)&1;
		sort(e+1,e+n+1);
		e[n+1].len=0;
		for(int i=1;i<=n;i++)e[i].a%=11;
		int s=0;
		while(e[s+1].len==1)s++;
		int posi=s+1>>1;
		for(int i=0;i<=s;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<11;k++)f[i][j][k]=0;
		f[0][0][0]=1;
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<11;k++)
				{
					add(f[i+1][j][(k+11-e[i+1].a)%11],f[i][j][k]);
					add(f[i+1][j+1][(k+e[i+1].a)%11],f[i][j][k]);
				}
			}
		}
		int ans=0;
		int t=n-s;
		for(int i=0;i<=t;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<11;k++)g[i][j][k]=0;
		g[0][0][0]=1;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<11;k++)
				{
					add(g[i+1][j][(k+11-e[i+1+s].a)%11],g[i][j][k]);
					add(g[i+1][j+1][(k+e[i+1+s].a)%11],g[i][j][k]);
				}
			}
		}
		for(int j=0;j<=t;j++)
		{
			for(int k=0;k<11;k++)//g 
			{
				if(!g[t][j][k])continue;
//				cout<<g[t][j][k]<<" "<<j<<" "<<k<<" "<<posi<<" "<<f[s][posi][(11-k)%11]<<" "<<posi<<"\n";
				int A=s+2>>1,B=s+1-A;
				add(ans,
				1ll*g[t][j][k]*f[s][posi][(11-k)%11]%mod
				*jiec[posi]%mod*jiec[s-posi]%mod
				*C(j+A-1,A-1)%mod*jiec[j]%mod
				*C(t-j+B-1,B-1)%mod*jiec[t-j]%mod
				);
			}
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}