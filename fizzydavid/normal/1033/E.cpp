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
int n;
vector<int> delx(vector<int> v,int x)
{
	vector<int> rv;
	for(int i=0;i<v.size();i++)if(v[i]!=x)rv.PB(v[i]);
	return rv;
}
vector<int> addx(vector<int> v,int x)
{
	for(int i=0;i<v.size();i++)if(v[i]==x)return v;
	v.PB(x);
	return v;
}
int query(vector<int> v)
{
	if(v.size()<=1)return 0;
	printf("? %d\n",int(v.size()));
	for(int i=0;i<v.size();i++)printf("%d ",v[i]);
	puts("");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	if(ret==-1)exit(0);
	return ret;
}
int queryadjcnt(int x,vector<int> v)
{
	return query(addx(v,x))-query(v);
}
vector<int> queryadj(int x,vector<int> v)
{
	vector<int> ret;
	if(v.size()==0)return ret;
//	cerr<<"qadjcnt:"<<x<<endl;
//	for(auto x:v)cerr<<x<<" ";cerr<<endl;
	int cnt=queryadjcnt(x,v);
//	cerr<<"cnt="<<cnt<<endl;
	if(cnt==0)return ret;
	if(cnt==v.size())
	{
		ret=v;
		return ret;
	}
	vector<int> vl,vr;
	int m=int(v.size())>>1;
	for(int i=0;i<m;i++)vl.PB(v[i]);
	for(int i=m;i<v.size();i++)vr.PB(v[i]);
	vector<int> retl,retr;
	retl=queryadj(x,vl);
	retr=queryadj(x,vr);
	for(auto x:retl)ret.PB(x);
	for(auto x:retr)ret.PB(x);
	return ret;
}
const int maxn=666;
int col[maxn];
int fa[maxn],lv[maxn];
void dfs(int x)
{
	vector<int> v;
	for(int i=1;i<=n;i++)if(x!=i&&col[i]==0)v.PB(i);
	vector<int> adj=queryadj(x,v);
	for(int i=0;i<adj.size();i++)col[adj[i]]=col[x]^1;
	for(int i=0;i<adj.size();i++)
	{
		fa[adj[i]]=x;
		lv[adj[i]]=lv[x]+1;
		dfs(adj[i]);
	}
}
void putno(int x,int y)
{
	vector<int> vl,vr;
	if(lv[x]>lv[y])swap(x,y);
	while(lv[y]>lv[x])
	{
		vr.PB(y);
		y=fa[y];
	}
	while(x!=y)
	{
		vl.PB(x);
		vr.PB(y);
		x=fa[x];
		y=fa[y];
	}
	vl.PB(x);
	reverse(vr.begin(),vr.end());
	printf("N %d\n",int(vl.size()+vr.size()));
	for(int i=0;i<vl.size();i++)printf("%d ",vl[i]);
	for(int i=0;i<vr.size();i++)printf("%d ",vr[i]);
	fflush(stdout);
	exit(0);
}
pair<int,int> find_edge(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		vector<int> adj=queryadj(v[i],delx(v,v[i]));
		if(adj.size()>0)
		{
			return MP(v[i],adj[0]);
		}
	}
	assert(false);
}
int main()
{
	scanf("%d",&n);
	col[1]=2;
	dfs(1);
	vector<int> S,T;
	for(int i=1;i<=n;i++)
	{
		if(col[i]==2)S.PB(i);
		else if(col[i]==3)T.PB(i);
		else assert(false);
	}
	if(query(S)!=0)
	{
		pair<int,int> e=find_edge(S);
		putno(e.FF,e.SS);
	}
	if(query(T)!=0)
	{
		pair<int,int> e=find_edge(T);
		putno(e.FF,e.SS);
	}
	printf("Y %d\n",S.size());
	for(int i=0;i<S.size();i++)printf("%d ",S[i]);
	fflush(stdout);
	return 0;
}