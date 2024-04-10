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
struct SGT
{
	int mx[400111],n;
	void init(int N)
	{
		n=N;
		for(int i=0;i<=4*n;i++)mx[i]=0;
	}
	#define ls p<<1
	#define rs p<<1|1
	void modify(int x,int v,int l,int r,int p=1)
	{
//		cerr<<"modify:"<<x<<" "<<v<<" "<<l<<" "<<r<<" "<<p<<endl;
		if(x==l&&x==r)
		{
			mx[p]=v;
			return;
		}
		int m=l+r>>1;
		if(x<=m)modify(x,v,l,m,ls);
		else modify(x,v,m+1,r,rs);
		mx[p]=max(mx[ls],mx[rs]);
	}
	int query(int x,int y,int l,int r,int p=1)
	{
//		cerr<<"query:"<<x<<","<<y<<" "<<l<<","<<r<<endl;
		if(x>y)return 0;
		if(x<=l&&r<=y)
		{
			return mx[p];
		}
		int m=l+r>>1;
		if(x<=m&&m<y)return max(query(x,y,l,m,ls),query(x,y,m+1,r,rs));
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
}sgt;
int n,m,w[100111],ww[100111];
vector<int> con[100111];
bool ban[100111];
int a[100111],an,sz[100111];
int dfn[100111],dfnr[100111],dfntot;
void dfs(int x,int pre=-1)
{
	dfn[x]=++dfntot;
	a[an++]=x;
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		dfs(u,x);
		sz[x]+=sz[u];
	}
	dfnr[x]=dfntot;
}
void dfs2(int x,int pre=-1)
{
	a[an++]=x;
	dfn[x]=++dfntot;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		dfs2(u,x);
	}
	dfnr[x]=dfntot;
}
int dp[100111];
int dpr[100111];
int ans;
vector<int> v;
pair<int,int> pp[100111];
void calcdp(int dp[])
{
//	cerr<<"calcdp:"<<endl;
	sgt.init(dfntot);
	for(int i=0;i<an;)
	{
		int r=i;
		while(pp[r].FF==pp[i].FF)r++;
		for(int j=i;j<r;j++)
		{
			int u=pp[j].SS;
			dp[u]=sgt.query(dfn[u],dfnr[u],1,dfntot)+1;
		}
		for(int j=i;j<r;j++)
		{
			int u=pp[j].SS;
			sgt.modify(dfn[u],dp[u],1,dfntot);
		}
		i=r;
	}
}
void query_single(int x)
{
	int tn=v.size();
	sgt.init(tn);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u])continue;
		for(int j=dfn[u]-1;j<dfnr[u];j++)
		{
			int tmp=dpr[a[j]]+sgt.query(1,ww[a[j]]-1,1,tn);
			ans=max(ans,tmp);
		}
		for(int j=dfn[u]-1;j<dfnr[u];j++)
		{
			sgt.modify(ww[a[j]],dp[a[j]],1,tn);
		}
	}
}
void solve(int x)
{
//	cerr<<"solve:"<<x<<endl;
	an=0;
	dfs(x);
	int rt=x;
	for(int i=0;i<an;i++)
	{
		int u=a[i];
		if(sz[u]*2>=sz[x]&&sz[u]<sz[rt])
		{
			rt=u;
		}
	}
	
	dfntot=0;
	an=0;
	dfs2(rt);
	a[an]=0;
//	for(int i=0;i<an;i++)cerr<<dfn[a[i]]<<" ";cerr<<endl;
//	for(int i=0;i<an;i++)cerr<<a[i]<<" ";cerr<<endl;
//	cerr<<"rt="<<rt<<endl;
	
	for(int i=0;i<an;i++)pp[i]=MP(w[a[i]],a[i]);
	pp[an]=MP(-1,-1);
	
	sort(pp,pp+an);
	calcdp(dp);
	reverse(pp,pp+an);
	calcdp(dpr);
//	cerr<<"dp"<<endl;
//	for(int i=0;i<an;i++)cerr<<dp[a[i]]<<" ";cerr<<endl;
//	for(int i=0;i<an;i++)cerr<<dpr[a[i]]<<" ";cerr<<endl;
	
	//choose root
	int cur=0;
	for(int i=0;i<an;i++)
	{
		if(w[a[i]]<w[rt])
		{
			cur=max(cur,dp[a[i]]);
		}
	}
	ans=max(ans,cur+1);
	for(int i=0;i<an;i++)
	{
		if(w[a[i]]>w[rt])
		{
			ans=max(ans,cur+1+dpr[a[i]]);
		}
	}
	
	//not choose root
	v.clear();
	for(int i=0;i<an;i++)v.PB(w[a[i]]);
	sort(v.begin(),v.end());
	for(int i=0;i<an;i++)ww[a[i]]=lower_bound(v.begin(),v.end(),w[a[i]])-v.begin()+1;
//	for(int i=0;i<an;i++)cerr<<ww[a[i]]<<" ";cerr<<endl;
//	cerr<<"ok"<<endl;
	
	query_single(rt);
	reverse(con[rt].begin(),con[rt].end());
	query_single(rt);
	/*
	ban[rt]=1;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i];
		if(ban[u])continue;
		solve(u);
	}*/
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(w[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	solve(1);
	cout<<ans<<endl;
	return 0;
}