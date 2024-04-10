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
int n,m,mxl;
vector<int> v[100111];
int a[100111];
set<int>st;
int tmpv[100111],tn;
bool f[100111],cap[100111];
int getcid(int x){return x-cap[x]*mod;}
bool check(int x)
{
	for(int i=0;i<v[x].size()&&i<v[x+1].size();i++)
	{
		int cx=getcid(v[x][i]);
		int cy=getcid(v[x+1][i]);
		if(cx!=cy)return cx<cy;
	}
	return v[x].size()<=v[x+1].size();
}
vector<int> con[100111];
void dfs(int x)
{
//	cerr<<"dfs:"<<x<<endl;
	cap[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(!cap[u])
		{
			dfs(u);
		}
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		int k;
		geti(k);mxl=max(mxl,k);
		while(k--)
		{
			int x;
			geti(x);
			v[i].PB(x);
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<v[i].size()&&j<v[i+1].size();j++)
		{
			int cx=getcid(v[i][j]);
			int cy=getcid(v[i+1][j]);
			if(cx==cy)continue;
			if(cx>cy)cap[v[i][j]]=1;
			con[v[i+1][j]].PB(v[i][j]);
			break;
		}
	}
	for(int i=1;i<=m;i++)if(cap[i])dfs(i);
	/*
	for(int i=1;i<=n;i++)st.insert(i);
	for(int i=0;i<mxl;i++)
	{
		foreach(it,st)f[*it]=1;
		tn=0;
		for(set<int>::iterator it=--st.end();;it--)
		{
			int cur=*it;
			if(f[cur]&&f[cur+1])
			{
				if(MP(a[cur],getcid(v[cur][i]))>MP(a[cur+1],getcid(v[cur+1][i])))
				{
					cap[v[cur][i]]=1;
				}
			}
			if(v[*it].size()==i+1)
			{
				tmpv[tn++]=*it;
			}
			if(it==st.begin())break;
		}
		foreach(it,st)
		{
			int cur=*it;
			if(f[cur]&&f[cur+1])
			{
				a[cur+1]=a[cur]+(MP(a[cur],getcid(v[cur][i]))<MP(a[cur+1],getcid(v[cur+1][i])));
			}
		}
		foreach(it,st)f[*it]=0;
		for(int j=0;j<tn;j++)st.erase(tmpv[j]);
	}*/
	for(int i=1;i<n;i++)
	{
		if(!check(i))
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	int cnt=0;
	for(int i=1;i<=m;i++)cnt+=cap[i];
	putsi(cnt);
	for(int i=1;i<=m;i++)if(cap[i])puti(i);
	return 0;
}