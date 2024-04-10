// luogu-judger-enable-o2
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
const double eps=1e-8;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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

const int N=800005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
int dfn[N],siz[N],id;
std::vector<std::pair<int,int> > v[N];
int ans[N];
struct BIT{
	int c[N],n;
	Finline BIT(){n=800000;}
	Finline void add(int x,const int &C){for(;x<=n;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}_tr;
void _dfs(int x)
{
	dfn[x]=++id,siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		_dfs(c[i].v);
		siz[x]+=siz[c[i].v];
	}
}
Finline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
struct ac_automation{
	struct Node{
		int ch[26],fail;
		std::vector<int> end;
	}f[N];
	int ch[N][26];
	int node_cnt;
	int _q[N],_l,_r;
	int Insert(char ch,int cur,const int &id)
	{
		int tmp=ch-97;
		if(!f[cur].ch[tmp]) f[cur].ch[tmp]=++node_cnt;
		cur=f[cur].ch[tmp];
		f[cur].end.push_back(id);
		return cur;
	}
	int Insert(char *s,const int &len,const int &id)
	{
		int cur=0,tmp;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-97;
			if(!f[cur].ch[tmp]) f[cur].ch[tmp]=++node_cnt;
			cur=f[cur].ch[tmp];
		}
		f[cur].end.push_back(id);
		return cur;
	}
	void build()
	{
		for(int i=0;i<=node_cnt;++i)
		{
			for(int j=0;j<26;++j)
			{
				ch[i][j]=f[i].ch[j];
			}
		}
		_l=1,_r=0;
		for(int i=0;i<26;++i)
		{
			if(f[0].ch[i])
			{
				_q[++_r]=f[0].ch[i];
			}
		}
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=0;i<26;++i)
			{
				if(f[x].ch[i])
				{
					f[f[x].ch[i]].fail=f[f[x].fail].ch[i];
					_q[++_r]=f[x].ch[i];
				}
				else
				{
					f[x].ch[i]=f[f[x].fail].ch[i];
				}
			}
		}
		for(int i=1;i<=node_cnt;++i) add(f[i].fail,i);
	}
	void dfs(int x)
	{
		_tr.add(dfn[x],1);
		for(auto it:f[x].end)
		{
			for(auto itt:v[it])
			{
				ans[itt.second]=_tr.sum(dfn[itt.first]+siz[itt.first]-1)-_tr.sum(dfn[itt.first]-1);
			}
		}
		for(int i=0;i<26;++i)
		{
			if(ch[x][i])
			{
				dfs(ch[x][i]);
			}
		}
		_tr.add(dfn[x],-1);
	}
}tr;
int nd[N];
char s[N];
int num[N];
int main()
{
	int n;
	read(n);
	int opt;
	char ch;
	int x;
	for(int i=1;i<=n;++i)
	{
		read(opt);
		if(opt==1)
		{
			ch=getchar();
			while(ch<97||ch>122) ch=getchar();
			nd[i]=tr.Insert(ch,0,i);
		}
		else
		{
			read(x);
			ch=getchar();
			while(ch<97||ch>122) ch=getchar();
			nd[i]=tr.Insert(ch,nd[x],i);
		}
	}
	int m;
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(num[i]);
		int len=read_str(s+1);
		nd[i+n]=tr.Insert(s,len,i+n);
	}
	tr.build();
	_dfs(0);
	for(int i=1;i<=m;++i)
	{
		v[num[i]].push_back(std::make_pair(nd[i+n],i));
	}
	tr.dfs(0);
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}