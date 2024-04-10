//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=200111;
int n;
vector<int> con[maxn];
ll slv[maxn][2],lv[maxn],sz[maxn][2];
ll ANS[2];
ll CNT[2];
void upd(ll A[],ll a[2],ll b[2],ll coef)
{
	A[0]+=(a[0]*b[0]+a[1]*b[1])*coef;
	A[1]+=(a[0]*b[1]+a[1]*b[0])*coef;
}
void dfs(int x,int pre=-1)
{
	sz[x][lv[x]&1]=1;
	slv[x][lv[x]&1]=lv[x];
	upd(ANS,slv[x],sz[x],-2);
	upd(ANS,sz[x],sz[x],-1*(-2*lv[x]));
	upd(CNT,sz[x],sz[x],-1);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		dfs(u,x);
		sz[x][0]+=sz[u][0];
		sz[x][1]+=sz[u][1];
		slv[x][0]+=slv[u][0];
		slv[x][1]+=slv[u][1];
	}
	upd(ANS,slv[x],sz[x],+2);
	upd(ANS,sz[x],sz[x],+1*(-2*lv[x]));
	upd(CNT,sz[x],sz[x],+1);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		upd(ANS,slv[u],sz[u],-2);
		upd(ANS,sz[u],sz[u],-1*(-2*(lv[x])));
		upd(CNT,sz[u],sz[u],-1);
	}
//	cerr<<x<<":"<<ANS[0]<<" "<<ANS[1]<<endl;
//	cerr<<x<<":"<<slv[x][0]<<" "<<slv[x][1]<<endl;
//	cerr<<x<<":"<<sz[x][0]<<" "<<sz[x][1]<<endl;
	
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
//	cerr<<ANS[0]<<" "<<ANS[1]<<endl;
//	cerr<<CNT[0]<<" "<<CNT[1]<<endl;
	ANS[0]/=2;
	ANS[1]/=2;
	CNT[0]/=2;
	CNT[1]/=2;
	
//	cerr<<ANS[0]<<" "<<ANS[1]<<endl;
//	cerr<<CNT[0]<<" "<<CNT[1]<<endl;
	cout<<ANS[0]/2+(ANS[1]+CNT[1])/2<<endl;
	return 0;
}