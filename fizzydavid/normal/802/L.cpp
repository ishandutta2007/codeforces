//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
ll kissme(ll x,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int n,deg[100111];
ll sum[100111];
ll inv[100111];
ll dpk[100111],dpc[100111];
vector<pair<int,ll> >con[100111];
void dfs(int x,int pre)
{
	if(deg[x]==1)return;
	dpc[x]=sum[x];
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i].FF==pre)continue;
		dfs(con[x][i].FF,x);
		dpk[x]+=dpk[con[x][i].FF];
		dpc[x]+=dpc[con[x][i].FF];
	}
//	cout<<x<<":"<<deg[x]<<endl;
//	cout<<kissme(deg[x],mod-1)<<endl;
//	cout<<x<<" "<<dpk[x]<<" "<<dpc[x]<<endl;
	dpk[x]=dpk[x]%mod*kissme(deg[x],mod-2)%mod;
	dpc[x]=dpc[x]%mod*kissme(deg[x],mod-2)%mod;
	dpc[x]=kissme(mod+1-dpk[x],mod-2)*dpc[x]%mod;
	dpk[x]=kissme(deg[x],mod-2)*kissme(mod+1-dpk[x],mod-2)%mod;
//	cout<<x<<" "<<dpk[x]<<" "<<dpc[x]<<endl;
/*	dpk[x]=(1-dpk[x]+mod)*deg[x]%mod;
	dpc[x]=(-dpc[x]+mod)*deg[x]%mod;*/
//	cout<<x<<" "<<dpk[x]<<" "<<dpc[x]<<endl;
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y,v;
		getiii(x,y,v);
		sum[x]+=v;
		sum[y]+=v;
		deg[x]++;
		deg[y]++;
		con[x].PB(MP(y,v));
		con[y].PB(MP(x,v));
	}
	ll sumk=0,sumc=sum[0];
	for(int i=0;i<con[0].size();i++)
	{
		dfs(con[0][i].FF,0);
		sumk+=dpk[con[0][i].FF];
		sumc+=dpc[con[0][i].FF];
	}
	sumk%=mod;sumc%=mod;
//	cout<<sumk<<" "<<sumc<<endl;
	cout<<sumc*kissme(deg[0]-sumk+mod,mod-2)%mod<<endl;
	return 0;
}