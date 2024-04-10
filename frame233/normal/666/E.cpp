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
 
const int N=1100005;
struct node{
	int maxx,pos;
	Finline bool operator < (const node &o)const
	{
		return maxx==o.maxx?pos>o.pos:maxx<o.maxx;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
	}f[N<<3];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=max(f[f[x].ls].val,f[f[x].rs].val);
	}
	void Update(int &cur,int l,int r,int pos)
	{
		if(!cur) cur=++node_cnt;
		if(l==r)
		{
			++f[cur].val.maxx;
			f[cur].val.pos=l;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,l,mid,pos);
		else Update(f[cur].rs,mid+1,r,pos);
		PushUp(cur);
	}
	node Query(int L,int R,int l,int r,int cur)
	{
		if(!cur) return (node){0,L};
		if(L<=l&&r<=R)
		{
			return f[cur].val;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			return max(Query(L,R,l,mid,f[cur].ls),Query(L,R,mid+1,r,f[cur].rs));
		}
		else if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		return Query(L,R,mid+1,r,f[cur].rs);
	}
	int merge(int a,int b,int l,int r)
	{
		if(!a||!b) return a|b;
		if(l==r)
		{
			f[a].val.maxx+=f[b].val.maxx;
			return a;
		}
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		PushUp(a);
		return a;
	}
}tr;
int root[N];
int m;
struct Qry{
	int l,r,id;
};
std::vector<Qry> v[N];
node ans[N];
int pos[N];
struct SAM{
	struct Node{
		int fa,len;
		int ch[26];
	}f[N];
	int node_cnt,last;
	Finline SAM():node_cnt(1),last(1){}
	void insert(int c,int id)
	{
		if(f[last].ch[c]&&f[f[last].ch[c]].len==f[last].len+1)
		{
			last=f[last].ch[c];
			if(id>0) tr.Update(root[last],1,m,id);
			return;
		}
		int cur=++node_cnt;
		if(id>0) tr.Update(root[cur],1,m,id);
		else pos[-id]=cur;
		f[cur].len=f[last].len+1;
		int p=last;
		while(p&&!f[p].ch[c])
		{
			f[p].ch[c]=cur;
			p=f[p].fa;
		}
		if(!p)
		{
			f[cur].fa=1;
		}
		else
		{
			int q=f[p].ch[c];
			if(f[q].len==f[p].len+1)
			{
				f[cur].fa=q;
			}
			else
			{
				bool flag=p==last;
				int clone=++node_cnt;
				memcpy(f[clone].ch,f[q].ch,104);
				f[clone].fa=f[q].fa;
				f[clone].len=f[p].len+1;
				f[cur].fa=f[q].fa=clone;
				while(p&&f[p].ch[c]==q)
				{
					f[p].ch[c]=clone;
					p=f[p].fa;
				}
				if(flag)
				{
					last=clone;
					return;
				}
			}
		}
		last=cur;
	}
	int tax[N],A[N];
	int F[N][21];
	void init()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i)
		{
			chmax(maxx,f[i].len);
		}
		memset(tax,0,4*(maxx+3));
		for(int i=1;i<=node_cnt;++i) ++tax[f[i].len];
		for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
		for(int i=1;i<=node_cnt;++i) A[tax[f[i].len]--]=i;
		for(int i=2;i<=node_cnt;++i)
		{
			F[A[i]][0]=f[A[i]].fa;
			for(int j=1;j<=20;++j)
			{
				F[A[i]][j]=F[F[A[i]][j-1]][j-1];
			}
		}
	}
	void Dp()
	{
		for(int i=node_cnt;i>1;--i)
		{
			for(auto it:v[A[i]])
			{
				ans[it.id]=tr.Query(it.l,it.r,1,m,root[A[i]]);
			}
			root[f[A[i]].fa]=tr.merge(root[f[A[i]].fa],root[A[i]],1,m);
		}
	}
	int getnd(int l,int r)
	{
		int len=r-l+1;
		int nd=pos[r];
		for(int i=20;i>=0;--i)
		{
			if(F[nd][i]&&f[F[nd][i]].len>=len)
			{
				nd=F[nd][i];
			}
		}
		return nd;
	}
}sam;
char s[N];
int main()
{
	int n=read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		sam.insert(s[i]-97,-i);
	}
	read(m);
	for(int i=1;i<=m;++i)
	{
		sam.last=1;
		n=read_str(s+1);
		for(int j=1;j<=n;++j) sam.insert(s[j]-97,i);
	}
	sam.init();
	int _;
	read(_);
	int l,r,pl,pr;
	for(int i=1;i<=_;++i)
	{
		read(l,r,pl,pr);
		v[sam.getnd(pl,pr)].push_back((Qry){l,r,i});
	}
	sam.Dp();
	for(int i=1;i<=_;++i)
	{
		printf("%d %d\n",ans[i].pos,ans[i].maxx);
	}
    return 0;
}
//