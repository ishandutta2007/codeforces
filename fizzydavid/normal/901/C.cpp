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
int n,m;
vector<int> con[300111];
int ban[300111];
bool vis[300111],inst[300111];
int fa[300111];
void dfs(int x)
{
	inst[x]=1;
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==fa[x])continue;
		if(!vis[u])fa[u]=x,dfs(u);
		else if(inst[u])
		{
			int t=x,mn=x,mx=x;
			while(true)
			{
				t=fa[t];
				mn=min(mn,t);
				mx=max(mx,t);
				if(t==u)break;
			}
//			cerr<<"ban:"<<mn<<" "<<mx<<endl;
			ban[mn]=min(ban[mn],mx);
		}
	}
	inst[x]=0;
}
int tor[300111];
struct BIT
{
	ll a[300111];
	BIT(){memset(a,0,sizeof(a));}
	void add(int x,ll v)
	{
		for(int i=x;i<=300005;i+=i&(-i))a[i]+=v;
	}
	ll query(ll x)
	{
		ll ret=0;
		for(int i=x;i>0;i-=i&(-i))ret+=a[i];
		return ret;
	}
}K,B;
vector<int> delv[300111];
vector<pair<int,int> >qr[300111];
ll ans[300111];
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)ban[i]=n+1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	for(int i=n;i>=1;i--)
	{
		tor[i]=ban[i]-1;
		if(i<n)tor[i]=min(tor[i],tor[i+1]);
		delv[tor[i]].PB(i);
	}
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		getii(l,r);
		qr[r].PB(MP(l,i));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<delv[i].size();j++)
		{
			int u=delv[i][j];
			K.add(u,-1);
			B.add(u,i-u+1+(u-1));
		}
		K.add(i,1);
		B.add(i,-(i-1));
		for(int j=0;j<qr[i].size();j++)
		{
			int l=qr[i][j].FF;
			int id=qr[i][j].SS;
			ll k=K.query(i)-K.query(l-1);
			ll b=B.query(i)-B.query(l-1);
			ans[id]=k*i+b;
		}
	}
	for(int i=1;i<=q;i++)putsi(ans[i]);
	return 0;
}