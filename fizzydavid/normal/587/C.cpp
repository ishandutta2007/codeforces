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
struct data
{
	vector<int> v;
	void maintain(){if(v.size()>10)v.resize(10);}
	void insert(int val){v.insert(lower_bound(v.begin(),v.end(),val),val);maintain();}
	data combine(const data &t)const
	{
		data ret;
		vector<int> tv;tv.resize(v.size()+t.v.size());
		merge(v.begin(),v.end(),t.v.begin(),t.v.end(),tv.begin());
		tv.swap(ret.v);
		ret.maintain();
		return ret;
	}
	void out(int k)
	{
		puti(min(int(v.size()),k));
		for(int i=0;i<v.size()&&i<k;i++)puti(v[i]);
		puts("");
	}
};
vector<int> con[100111];
int p[18][100111],lv[100111];
data tab[18][100111];
int n,m,q;
void dfs(int x)
{
//	cerr<<x<<":"<<p[0][x]<<endl;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==p[0][x])continue;
		p[0][u]=x;
		lv[u]=lv[x]+1;
		dfs(u);
	}
}
data query(int x,int y)
{
//	cerr<<"query:"<<x<<","<<y<<endl;
	data ret;
	if(lv[x]<lv[y])swap(x,y);
	for(int i=17;i>=0;i--)
	{
		if((lv[x]-lv[y])>=(1<<i))
		{
			ret=ret.combine(tab[i][x]);
			x=p[i][x];
		}
	}
	if(x==y)
	{
		ret=ret.combine(tab[0][x]);
		return ret;
	}
	for(int i=17;i>=0;i--)
	{
		if(p[i][x]!=p[i][y])
		{
			ret=ret.combine(tab[i][x]);
			ret=ret.combine(tab[i][y]);
			x=p[i][x];
			y=p[i][y];
		}
	}
	ret=ret.combine(tab[1][x]);
	ret=ret.combine(tab[0][y]);
	return ret;
}
int main()
{
	getiii(n,m,q);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	lv[1]=1;
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x;
		geti(x);
		tab[0][x].insert(i);
	}
	for(int i=1;i<18;i++)
	{
		for(int x=1;x<=n;x++)
		{
			p[i][x]=p[i-1][p[i-1][x]];
			if(p[i-1][x])tab[i][x]=tab[i-1][x].combine(tab[i-1][p[i-1][x]]);
			else tab[i][x]=tab[i-1][x];
		}
	}
	while(q--)
	{
		int u,v,k;
		getiii(u,v,k);
		data tmp=query(u,v);
		tmp.out(k);
	}
	return 0;
}