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
int n,k;
void addobject(int dp[],int v,int w)
{
//	cout<<"addobject:"<<v<<" "<<w<<endl;
	for(int i=k;i>=v;i--)
	{
		dp[i]=max(dp[i],dp[i-v]+w);
	}
//	for(int i=0;i<=k;i++)cout<<dp[i]<<" ";cout<<endl;
}
int type[40011],qv[40011],vol[40011],w[40011];
int st[40011],ed[40011],id[40011];
vector<int>v[200111];
void add(int x,int y,int i,int l,int r,int p)
{
//	cout<<"add:"<<x<<","<<y<<" "<<i<<" "<<p<<" "<<l<<","<<r<<endl;
	if(x<=l&&r<=y)
	{
		v[p].PB(i);
		return;
	}
	int m=l+r>>1;
	if(x<=m)add(x,y,i,l,m,p<<1);
	if(m<y)add(x,y,i,m+1,r,p<<1|1);
}
int dp[22][1011];
void dfs(int l,int r,int p,int lv)
{
//	cout<<"dfs:"<<l<<","<<r<<" "<<p<<" "<<lv<<endl;
	bool ok=0;
	for(int i=l;i<=r;i++)
	{
		if(type[i]==3)ok=1;
	}
	if(!ok)return;
	for(int i=0;i<v[p].size();i++)
	{
		addobject(dp[lv],vol[v[p][i]],w[v[p][i]]);
	}
	if(l==r)
	{
		ll bs=1,ans=0;
		for(int i=1;i<=k;i++)
		{
			ans+=dp[lv][i]*bs%mod;
			bs=bs*10000019%mod;
		}
		putsi(ans%mod);
		return;
	}
	int m=l+r>>1;
	for(int i=0;i<=k;i++)dp[lv+1][i]=dp[lv][i];
	dfs(l,m,p<<1,lv+1);
	for(int i=0;i<=k;i++)dp[lv+1][i]=dp[lv][i];
	dfs(m+1,r,p<<1|1,lv+1);
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)
	{
		type[i]=1;
		getii(w[i],vol[i]);
		qv[i]=i;
		st[i]=i;
	}
	int q;geti(q);
	q+=n;
	for(int i=n+1;i<=q;i++)
	{
		geti(type[i]);
		if(type[i]==3)continue;
		geti(qv[i]);
		if(type[i]==1)
		{
			w[++n]=qv[i];
			qv[i]=n;
			geti(vol[n]);
			st[n]=i;
		}
		else if(type[i]==2)
		{
			ed[qv[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ed[i]==0)ed[i]=q;
		add(st[i],ed[i],i,1,q,1);
	}
	dfs(1,q,1,0);
	return 0;
}