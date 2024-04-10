//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,w,h;
int g[200111],a[200111],t[200111];
vector<int> v[200111];
vector<pair<int,int> > v1,v2,vp;
pair<int,int> ans[200111];
int main()
{
	getiii(n,w,h);
	for(int i=1;i<=n;i++)
	{
		getiii(g[i],a[i],t[i]);
		v[a[i]-t[i]+100000].PB(i);
	}
	for(int i=0;i<200005;i++)
	{
		v1.clear();
		v2.clear();
		for(int j=0;j<v[i].size();j++)
		{
			int x=v[i][j];
			if(g[x]==1)v1.PB(MP(a[x],x));
			else v2.PB(MP(a[x],x));
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		vp.clear();
		for(int j=0;j<v2.size();j++)
		{
			vp.PB(MP(w,v2[j].FF));
		}
		for(int j=int(v1.size())-1;j>=0;j--)
		{
			vp.PB(MP(v1[j].FF,h));
		}
		int it=0;
		for(int j=int(v1.size())-1;j>=0;j--)
		{
			ans[v1[j].SS]=vp[it++];
		}
		for(int j=0;j<v2.size();j++)
		{
			ans[v2[j].SS]=vp[it++];
		}
	}
	for(int i=1;i<=n;i++)putsii(ans[i].FF,ans[i].SS);
	return 0;
}