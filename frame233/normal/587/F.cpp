// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
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

const int N=100005;
const int S=350;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
ll sum[N];
int n;
int qwq[N];
struct node{
	int val,id,opt;
};
std::vector<int> v[N];
std::vector<node> _v[N];
struct block{
	int L[N/S+5],R[N/S+5];
	int bel[N];
	int a[N],tag[N/S+5];
	void build(int n)
	{
		int cur=0,tmp=S;
		for(int i=1;i<=n;++i)
		{
			++tmp;
			if(tmp>S)
			{
				R[cur]=i-1;
				tmp=1;
				++cur;
				L[cur]=i;
			}
			bel[i]=cur;
		}
		R[cur]=n;
	}
	void add(int l,int r)
	{
		if(bel[l]==bel[r])
		{
			for(int i=l;i<=r;++i)
			{
				++a[i];
			}
			return;
		}
		for(int i=bel[l]+1;i<bel[r];++i) ++tag[i];
		for(int i=l;i<=R[bel[l]];++i) ++a[i];
		for(int i=L[bel[r]];i<=r;++i) ++a[i];
	}
	Finline int Query(int x)
	{
		return a[x]+tag[bel[x]];
	}
}B;
int dfn[N],id,siz[N];
ll ans[N];
int d[N];
struct ACAM{
	int ch[N][26];
	int fail[N];
	int ans_fail[N];
	int node_cnt;
	int _q[N],_l,_r;
	int Fa[N];
	void insert(char *s,int len,int id)
	{
		int cur=0,tmp;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-97;
			if(!ch[cur][tmp])
			{
				ch[cur][tmp]=++node_cnt;
				Fa[node_cnt]=cur;
			}
			cur=ch[cur][tmp];
		}
		v[cur].push_back(id);
		qwq[id]=cur;
	}
	int A[N],pos;
	void build()
	{
		_l=1,_r=0;
		for(int i=0;i<26;++i)
		{
			if(ch[0][i])
			{
				_q[++_r]=ch[0][i];
			}
		}
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			A[++pos]=x;
			ans_fail[x]=v[fail[x]].empty()?ans_fail[fail[x]]:fail[x];
			for(int i=0;i<26;++i)
			{
				if(ch[x][i])
				{
					fail[ch[x][i]]=ch[fail[x]][i];
					_q[++_r]=ch[x][i];
				}
				else
				{
					ch[x][i]=ch[fail[x]][i];
				}
			}
		}
		for(int i=1;i<=node_cnt;++i)
		{
			add(fail[i],i);
		}
	}
	void match(int cur)
	{
		while(cur)
		{
			++d[cur];
			cur=Fa[cur];
		}
		for(int i=pos;i>=1;--i)
		{
			d[fail[A[i]]]+=d[A[i]];
		}
		for(int i=0;i<=node_cnt;++i)
		{
			for(auto it:v[i])
			{
				sum[it]+=d[i];
			}
			d[i]=0;
		}
		for(int i=1;i<=n;++i) sum[i]+=sum[i-1];
	}
	void query(int cur,int id,int opt)
	{
		while(cur)
		{
			ans[id]+=opt*B.Query(dfn[cur]);
			cur=Fa[cur];
		}
	}
}tr;
struct Node{
	int l,r,id;
};
std::vector<Node> Q[N];
int _id[N],id_cnt;
char t[N];
void dfs(int x)
{
	dfn[x]=++id;
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v);
		siz[x]+=siz[c[i].v];
	}
}
int to[N];
int main()
{
	int q;
	read(n,q);
	for(int i=1;i<=n;++i)
	{
		int len=read_str(t+1);
		tr.insert(t,len,i);
		if(len>S)
		{
			_id[i]=++id_cnt;
			to[id_cnt]=i;
		}
	}
	tr.build();
	dfs(0);
	int l,r,x;
	for(int i=1;i<=q;++i)
	{
		read(l,r,x);
		if(_id[x])
		{
			Q[_id[x]].push_back((Node){l,r,i});
		}
		else
		{
			_v[r].push_back((node){qwq[x],i,1});
			_v[l-1].push_back((node){qwq[x],i,-1});
		}
	}
	for(int i=1;i<=id_cnt;++i)
	{
		memset(sum,0,(n+3)<<3);
		tr.match(qwq[to[i]]);
		for(auto it:Q[i])
		{
			ans[it.id]=sum[it.r]-sum[it.l-1];
		}
	}
	B.build(id);
	for(int i=1;i<=n;++i)
	{
		B.add(dfn[qwq[i]],dfn[qwq[i]]+siz[qwq[i]]-1);
		for(auto it:_v[i])
		{
			tr.query(it.val,it.id,it.opt);
		}
	}
	for(int i=1;i<=q;++i)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}