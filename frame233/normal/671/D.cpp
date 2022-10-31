// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=1e18;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=300005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
struct seg_tr{
	struct Node{
		int ls,rs;
		ll minn,tag;
		Finline Node():minn(INF),tag(0){}
	}f[N*15];
	int node_cnt;
	int st[N*15],top;
	Finline void PushUp(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn)+f[x].tag;
	}
	void Update(int &cur,int l,int r,int pos,ll val,ll tag)
	{
		if(!cur) cur=top?st[top--]:++node_cnt;
		chmin(f[cur].minn,val-tag);
		if(l==r) return;
		int mid=(l+r)>>1;
		tag+=f[cur].tag;
		if(pos<=mid) Update(f[cur].ls,l,mid,pos,val,tag);
		else Update(f[cur].rs,mid+1,r,pos,val,tag);
	}
	void modify(int L,int R,int l,int r,int &cur)
	{
		if(!cur) return;
		if(L<=l&&r<=R)
		{
			f[cur].minn=1e18;
			f[cur].tag=0;
			f[cur].ls=f[cur].rs=0;
			st[++top]=cur;
			cur=0;
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) modify(L,R,l,mid,f[cur].ls);
		if(R>mid) modify(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int merge(int a,int b,int l,int r,ll suf1,ll suf2,ll tag1,ll tag2)
	{
		if(!a&&!b) return 0;
		if(!a||!b)
		{
			if(a)
			{
				if(suf2>=INF)
				{
					f[a].minn=1e18;
					f[a].tag=0;
					f[a].ls=f[a].rs=0;
					st[++top]=a;
					return 0;
				}
				f[a].tag+=suf2;
				f[a].minn+=suf2;
				return a;
			}
			else
			{
				if(suf1>=INF)
				{
					f[b].minn=1e18;
					f[b].tag=0;
					f[b].ls=f[b].rs=0;
					st[++top]=b;
					return 0;
				}
				f[b].tag+=suf1;
				f[b].minn+=suf1;
				f[b].minn+=tag2-tag1;
				f[b].tag+=tag2-tag1;
				return b;
			}
		}
		if(l==r)
		{
			f[a].minn=min(min(f[a].minn+tag1+suf2,f[b].minn+tag2+suf1),f[a].minn+f[b].minn+tag1+tag2)-tag1;
			f[b].minn=1e18;
			f[b].tag=0;
			f[b].ls=f[b].rs=0;
			st[++top]=b;
			return a;
		}
		tag1+=f[a].tag;
		tag2+=f[b].tag;
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid,min(suf1,f[f[a].rs].minn+tag1),min(suf2,f[f[b].rs].minn+tag2),tag1,tag2);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r,suf1,suf2,tag1,tag2);
		PushUp(a);
		f[b].minn=1e18;
		f[b].tag=0;
		f[b].ls=f[b].rs=0;
		st[++top]=b;
		return a;
	}
}tr;
int n;
int root[N];
int dep[N];
std::vector<std::pair<int,int> > v[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	int cnt=0;
	bool first=true;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			++cnt;
			dfs(c[i].v,x);
			tr.modify(dep[c[i].v],n,1,n,root[c[i].v]);
			if(first) root[x]=root[c[i].v],first=false;
			else root[x]=tr.merge(root[x],root[c[i].v],1,n,1e18,1e18,0,0);
		}
	}
	if(first)
	{
		tr.Update(root[x],1,n,dep[x],0,0);
	}
	ll minn=tr.f[root[x]].minn;
	if(minn>=1e16)
	{
		printf("-1\n");
		exit(0);
	}
	for(auto it:v[x])
	{
		tr.Update(root[x],1,n,dep[it.first],it.second+minn,0);
	}
}
int main()
{
	int m;
	read(n,m);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		v[x].push_back(std::make_pair(y,z));
	}
	dfs(1,0);
	printf("%lld\n",tr.f[root[1]].minn);
	return 0;
}