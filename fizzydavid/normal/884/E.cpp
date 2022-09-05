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
int n,m,id[256];
int pre[1<<14],cur[1<<14];
bool pg[1<<14],g[1<<14];
int f[33333];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int hs[33333];
int main()
{
	for(int i=0;i<=9;i++)id['0'+i]=i;
	for(int i=0;i<6;i++)id['A'+i]=10+i;
	getii(n,m);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<33333;j++)f[j]=j;
		for(int j=0;j<m/4;j++)
		{
			char c;
			if(i==n)c='0';
			else c=getreal();
			int t=id[c];
			for(int k=0;k<4;k++)g[j<<2|(3-k)]=(t>>k)&1;
		}
//		cerr<<"i="<<i<<endl;
//		for(int j=0;j<m;j++)cerr<<pg[j];cerr<<endl;
//		for(int j=0;j<m;j++)cerr<<g[j];cerr<<endl;
		
		int b=16666;
		for(int j=0;j<m;j++)
		{
			if(g[j])
			{
				if(pg[j])cur[j]=pre[j];
				else cur[j]=++b;
			}
			else cur[j]=0;
		}
//		for(int j=0;j<m;j++)cerr<<pre[j]<<" ";cerr<<endl;
//		for(int j=0;j<m;j++)cerr<<cur[j]<<" ";cerr<<endl;
		for(int j=0;j+1<m;j++)
		{
			if(g[j]&&g[j+1])
			{
				f[gf(cur[j])]=gf(cur[j+1]);
			}
		}
		memset(hs,0,sizeof(hs));
		for(int j=0;j<m;j++)if(g[j])
		{
			cur[j]=gf(cur[j]);
			hs[cur[j]]=1;
		}
		for(int j=0;j<m;j++)if(pg[j])
		{
			if(!hs[gf(pre[j])])ans++,hs[gf(pre[j])]=1;
		}
		memset(hs,0,sizeof(hs));
		int tot=0;
		for(int j=0;j<m;j++)if(g[j])
		{
			if(!hs[cur[j]])hs[cur[j]]=++tot;
			cur[j]=hs[cur[j]];
		}
		swap(g,pg);
		swap(cur,pre);
	}
	cout<<ans<<endl;
	return 0;
}