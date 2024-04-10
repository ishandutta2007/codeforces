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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
int n,m,fa[100111],fe[100111];
int head[100111],nxt[200111],to[200111],tot=1;
ll ia[200111],a[200111],ans[200111];
int eid=-1;
int dis[100111];
bool vis[100111],inst[100111];
void dfs(int x,int pre=-1)
{
//	cerr<<"dfs:"<<x<<endl;
	vis[x]=1;inst[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if((i>>1)==pre)continue;
		int u=to[i];
		if(!vis[u])
		{
			fa[u]=x;
			fe[u]=i>>1;
			a[x]--;
			a[u]--;
			ans[i>>1]++;
			dis[u]=dis[x]+1;
			dfs(u,i>>1);
			if(a[u]!=0)
			{
				assert(x!=u);
				ans[i>>1]+=a[u];
				a[x]-=a[u];
				a[u]-=a[u];
			}
		}
		else if(inst[u])
		{
			a[x]--;
			a[u]--;
			ans[i>>1]++;
			if(dis[u]%2==dis[x]%2)
			{
				eid=i>>1;
			}
		}
	}
	inst[x]=0;
}
void out()
{
	puts("YES");
	for(int i=1;i<=m;i++)putsi(ans[i]);
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=head[i];j;j=nxt[j])
		{
			sum+=ans[j>>1];
		}
		assert(sum==ia[i]);
	}
	exit(0);
}
void update(int x,ll v)
{
	bool f=1;
	while(x!=1)
	{
		if(f)ans[fe[x]]-=v;
		else ans[fe[x]]+=v;
		x=fa[x];
		f^=1;
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]),ia[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
	}
	dis[1]=1;
	dfs(1);
//	for(int i=1;i<=n;i++)cerr<<a[i]<<" ";cerr<<endl;
	if(a[1]==0)
	{
		out();
	}
	if(eid!=-1)
	{
//		cerr<<"eid="<<eid<<endl;
		int u=to[eid<<1],v=to[eid<<1|1];
		int t=dis[u];
		ll coef;
		if(t%2==1)coef=+a[1]/2;
		else coef=-a[1]/2;
		ans[eid]+=coef;
		update(u,coef);
		update(v,coef);
		out();
	}
	puts("NO");
	return 0;
}