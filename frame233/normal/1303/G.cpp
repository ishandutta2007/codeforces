// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=150005;
ll ans;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int S,_maxx,root;
bool vis[N];
int siz[N];
void getrt(int x,int fa)
{
	siz[x]=1;
	int maxx=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getrt(c[i].v,x);
			siz[x]+=siz[c[i].v];
			chmax(maxx,siz[c[i].v]);
		}
	}
	chmax(maxx,S-siz[x]);
	if(maxx<_maxx)
	{
		_maxx=maxx;
		root=x;
	}
}
int a[N];
struct node{
	ll ans,sum;
	int cnt;
}a1[N],a2[N];
int pos1,pos2;
void getdis1(int x,int fa,node val)
{
	++val.cnt;
	val.sum+=a[x];
	val.ans+=val.sum;
	a1[++pos1]=val;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getdis1(c[i].v,x,val);
		}
	}
}
void getdis2(int x,int fa,node val)
{
	++val.cnt;
	val.ans+=1ll*a[x]*val.cnt;
	val.sum+=a[x];
	a2[++pos2]=val;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getdis2(c[i].v,x,val);
		}
	}
}
struct seg{
	struct Node{
		int ls,rs;
		node val;
	}f[N<<1];
	int node_cnt;
	int t[N<<5];
	int t_pos;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int l,int r,int cur,const node &val)
	{
		if(!cur) return;
		if(!f[cur].val.sum)
		{
			t[++t_pos]=cur;
			f[cur].val=val;
			return;
		}
		ll fl1=1ll*l*f[cur].val.sum+f[cur].val.ans;
		ll fr1=1ll*r*f[cur].val.sum+f[cur].val.ans;
		ll fl2=1ll*l*val.sum+val.ans;
		ll fr2=1ll*r*val.sum+val.ans;
		if(fl1>=fl2&&fr1>=fr2)
		{
			return;
		}
		if(fl1<=fl2&&fr1<=fr2)
		{
			t[++t_pos]=cur;
			f[cur].val=val;
			return;
		}
		int mid=(l+r)>>1;
		double pos=(double)(f[cur].val.ans-val.ans)/(val.sum-f[cur].val.sum);
		if(pos<=mid)
		{
			if(fl1>=fl2)
			{
				Update(l,mid,f[cur].ls,f[cur].val);
				t[++t_pos]=cur;
				f[cur].val=val;
			}
			else
			{
				Update(l,mid,f[cur].ls,val);
			}
		}
		else
		{
			if(fl1>=fl2)
			{
				Update(mid+1,r,f[cur].rs,val);
			}
			else
			{
				Update(mid+1,r,f[cur].rs,f[cur].val);
				t[++t_pos]=cur;
				f[cur].val=val;
			}
		}
	}
	ll Query(int l,int r,int cur,int x)
	{
		if(l==r)
		{
			return 1ll*x*f[cur].val.sum+f[cur].val.ans;
		}
		int mid=(l+r)>>1;
		if(x<=mid) return max(Query(l,mid,f[cur].ls,x),1ll*x*f[cur].val.sum+f[cur].val.ans);
		else return max(Query(mid+1,r,f[cur].rs,x),1ll*x*f[cur].val.sum+f[cur].val.ans);
	}
	Finline void reset()
	{
		while(t_pos)
		{
			f[t[t_pos]].val=(node){0,0,0};
			--t_pos;
		}
	}
}tr;
int n;
void solve(int x)
{
	std::vector<int> v;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			v.push_back(c[i].v);
			pos1=pos2=0;
			getdis1(c[i].v,x,(node){a[x],a[x],1});
			for(int j=1;j<=pos1;++j)
			{
				chmax(ans,tr.Query(1,n,1,a1[j].cnt)+a1[j].ans);
			}
			getdis2(c[i].v,x,(node){0,0,0});
			for(int j=1;j<=pos2;++j)
			{
				tr.Update(1,n,1,a2[j]);
			}
		}
	}
	chmax(ans,tr.Query(1,n,1,1)+a[x]);
	tr.reset();
	std::reverse(v.begin(),v.end());
	for(auto it:v)
	{
		pos1=pos2=0;
		getdis1(it,x,(node){a[x],a[x],1});
		for(int j=1;j<=pos1;++j)
		{
			chmax(ans,tr.Query(1,n,1,a1[j].cnt)+a1[j].ans);
		}
		getdis2(it,x,(node){0,0,0});
		for(int j=1;j<=pos2;++j)
		{
			tr.Update(1,n,1,a2[j]);
		}
	}
	tr.reset();
}
void getsize(int x,int fa)
{
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa&&!vis[c[i].v])
		{
			getsize(c[i].v,x);
			siz[x]+=siz[c[i].v];
		}
	}
}
void dfs(int x)
{
	vis[x]=true;
	solve(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!vis[c[i].v])
		{
			getsize(c[i].v,x);
			S=siz[c[i].v],_maxx=inf,root=0;
			getrt(c[i].v,x);
			dfs(root);
		}
	}
}
int main()
{
	read(n);
	tr.build(1,n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	root=0,S=n,_maxx=inf;
	getrt(1,0);
	dfs(root);
	printf("%lld\n",ans);
	return 0;
}