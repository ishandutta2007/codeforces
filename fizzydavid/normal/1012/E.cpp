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
int n,m,tot;
int a[maxn],b[maxn],it[maxn];
map<int,int> mpid;
vector<pair<int,int> > con[maxn];
vector<vector<int>> cyc,ans;
vector<int> cur;
void dfs(int x)
{
	for(int &i=it[x];i<con[x].size();)
	{
		int u=con[x][i].FF,id=con[x][i].SS;
		i++;
		dfs(u);
		cur.PB(id);
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		int &id=mpid[b[i]];
		if(id==0)id=++tot;
		b[i]=id;
	}
	for(int i=1;i<=n;i++)a[i]=mpid[a[i]];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])continue;
		con[a[i]].PB(MP(b[i],i));
	}
	for(int i=1;i<=tot;i++)it[i]=0;
	int sum=0;
	for(int i=1;i<=tot;i++)
	{
		if(con[i].size()>0&&it[i]<con[i].size())
		{
			cur.clear();
			dfs(i);
			cyc.PB(cur);
			sum+=cur.size();
		}
	}
	if(sum>m)
	{
		puts("-1");
		return 0;
	}
	int mx=-1;
	for(int i=1;i<cyc.size();i++)
	{
		if(sum+1+i<=m)
		{
			mx=i;
		}
	}
	if(mx!=-1)
	{
		vector<int> v;
		for(int i=0;i<=mx;i++)
		{
			for(int j=0;j<cyc[i].size();j++)
			{
				v.PB(cyc[i][j]);
			}
		}
		ans.PB(v);
		v.clear();
		for(int i=0;i<=mx;i++)v.PB(cyc[i][0]);
		reverse(v.begin(),v.end());
		ans.PB(v);
	}
	else
	{
		for(int i=0;i<=mx;i++)ans.PB(cyc[i]);
	}
	for(int i=mx+1;i<cyc.size();i++)ans.PB(cyc[i]);
	putsi(ans.size());
	for(int i=0;i<ans.size();i++)
	{
		putsi(ans[i].size());
		for(auto x:ans[i])puti(x);puts("");
	}
	return 0;
}