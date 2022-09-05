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
struct SGT
{
	int a[800111],b[800111];
	void init(){memset(a,63,sizeof(a));memset(b,63,sizeof(b));}
	#define ls p<<1
	#define rs p<<1|1
	void push_down(int p)
	{
		b[ls]=min(b[ls],b[p]);
		b[rs]=min(b[rs],b[p]);
		a[ls]=min(a[ls],b[p]);
		a[rs]=min(a[rs],b[p]);
	}
	void mini(int x,int y,int v,int l,int r,int p)
	{
		if(x<=l&&r<=y)
		{
			b[p]=min(b[p],v);
			a[p]=min(a[p],v);
			return;
		}
		push_down(p);
		int m=l+r>>1;
		if(x<=m)mini(x,y,v,l,m,ls);
		if(m<y)mini(x,y,v,m+1,r,rs);
		a[p]=min(a[ls],a[rs]);
	}
	int query(int x,int y,int l,int r,int p)
	{
		if(x<=l&&r<=y)return a[p];
		push_down(p);
		int m=l+r>>1;
		if(x<=m&&m<y)return min(query(x,y,l,m,ls),query(x,y,m+1,r,rs));
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
}sgt,sgto;
int n,m;
struct edge
{
	int x,y,w,id;
	edge(int X=0,int Y=0,int W=0,int Id=0)
	{
		x=X;y=Y;w=W;id=Id;
	}
	bool operator<(const edge &t)const
	{
		return w<t.w;
	}
};
edge ve[200111];
int f[200111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
vector<int>con[200111];
int p[201111],lv[200111],top[200111],son[200111],sz[200111],dfn[200111],dfntot;
void dfs(int x,int pre)
{
	p[x]=pre;
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		dfs(u,x);
		sz[x]+=sz[u];
	}
}
void dfs2(int x)
{
	dfn[x]=++dfntot;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==p[x])continue;
		if(sz[son[x]]<sz[u])
		{
			son[x]=u;
		}
	}
	if(son[x])
	{
		top[son[x]]=top[x];
		dfs2(son[x]);
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==p[x]||u==son[x])continue;
		top[u]=u;
		dfs2(u);
	}
}
void mini(int x,int y,int w)
{
//	cout<<"minit:"<<x<<","<<y<<" "<<w<<endl;
	while(true)
	{
		if(top[x]==top[y])
		{
			if(x==y)return;
			if(lv[x]>lv[y])swap(x,y);
			sgt.mini(dfn[x]+1,dfn[y],w,1,n,1);
			return;
		}
		else
		{
			if(lv[top[x]]>lv[top[y]])swap(x,y);
			sgt.mini(dfn[top[y]],dfn[y],w,1,n,1);
			y=p[top[y]];
		}
	}
}
int query(int x,int y)
{
//	cout<<"queryt:"<<x<<","<<y<<endl;
	int ret=sgt.a[0];
	while(true)
	{
		if(top[x]==top[y])
		{
			if(x==y)return ret;
			if(lv[x]>lv[y])swap(x,y);
			ret=min(ret,sgto.query(dfn[x]+1,dfn[y],1,n,1));
			return ret;
		}
		else
		{
			if(lv[top[x]]>lv[top[y]])swap(x,y);
			ret=min(ret,sgto.query(dfn[top[y]],dfn[y],1,n,1));
			y=p[top[y]];
		}
	}
}
bool te[200111];
int ans[200111];
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		getiii(x,y,w);
		ve[i]=edge(x,y,w,i);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(ve+1,ve+m+1);
	for(int i=1;i<=m;i++)
	{
		int x=ve[i].x,y=ve[i].y;
		if(gf(x)==gf(y))continue;
//		cout<<ve[i].id<<endl;
		f[gf(x)]=gf(y);
		con[x].PB(y);
		con[y].PB(x);
		te[i]=1;
//		cout<<x<<"-"<<y<<endl;
	}
	dfs(1,0);
	dfntot=0;
	top[1]=1;
	dfs2(1);
/*	cerr<<"dfs completed"<<endl;
	for(int i=1;i<=n;i++)cout<<top[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)cout<<dfn[i]<<" ";cout<<endl;*/
	
	sgt.init();sgto.init();
	for(int i=1;i<=m;i++)
	{
		int x=ve[i].x,y=ve[i].y,w=ve[i].w,id=ve[i].id;
		if(lv[x]>lv[y])swap(x,y);
		if(te[i])sgto.mini(dfn[y],dfn[y],-w,1,n,1);
		else mini(x,y,w-1);
	}
	for(int i=1;i<=m;i++)
	{
		int x=ve[i].x,y=ve[i].y,w=ve[i].w,id=ve[i].id;
		if(lv[x]<lv[y])swap(x,y);
		if(te[i])
		{
			ans[id]=sgt.query(dfn[x],dfn[x],1,n,1);
		}
		else
		{
			ans[id]=-query(x,y)-1;
		}
	}
	for(int i=1;i<=m;i++)puti(ans[i]==sgt.a[0]?-1:ans[i]);
	return 0;
}