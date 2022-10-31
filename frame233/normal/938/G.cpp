// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

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

const int N=200005;
struct LBase{
	int d[30];
	void insert(int x)
	{
		for(int i=29;i>=0;--i)
		{
			if((x>>i)&1)
			{
				if(d[i])
				{
					x^=d[i];
				}
				else
				{
					d[i]=x;
					break;
				}
			}
		}
	}
	int Query(int x)
	{
		for(int i=29;i>=0;--i) chmin(x,x^d[i]);
		return x;
	}
}B;
int ans[N];
int E[N][3];
struct Union_set{
	int fa[N],rnk[N],w[N];
	struct Node{
		int *pos,val;
	}t[N<<6];
	int pos;
	Finline Union_set():pos(0)
	{
		for(int i=0;i<N;++i)
		{
			fa[i]=i;
		}
	}
	int find(int x){return x==fa[x]?x:find(fa[x]);}
	int getval(int x){return x==fa[x]?0:getval(fa[x])^w[x];}
	int merge(int x,int y,int val)
	{
		int a=getval(x),b=getval(y);
		x=find(x),y=find(y);
		if(x==y)
		{
			B.insert(a^b^val);
			return 0;
		}
		if(rnk[x]>=rnk[y])
		{
			t[++pos]={fa+y,y};
			t[++pos]={w+y,0};
			fa[y]=x;
			w[y]=val^a^b;
			if(rnk[x]==rnk[y])
			{
				t[++pos]={rnk+x,rnk[x]};
				++rnk[x];
				return 3;
			}
		}
		else
		{
			t[++pos]={fa+x,x};
			t[++pos]={w+x,0};
			fa[x]=y;
			w[x]=val^a^b;
		}
		return 2;
	}
	Finline void reset()
	{
		*t[pos].pos=t[pos].val;
		--pos;
	}
}S;
struct NODE{
	int x,y,val;
};
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<NODE> v;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int L,int R,int l,int r,int cur,const NODE &o)
	{
		if(L<=l&&r<=R)
		{
			f[cur].v.push_back(o);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,o);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,o);
	}
	void Query(int l,int r,int cur)
	{
		LBase qwq=B;
		int siz=0;
		for(auto it:f[cur].v)
		{
			siz+=S.merge(it.x,it.y,it.val);
		}
		if(l==r)
		{
			if(E[l][0])
			{
				ans[l]=B.Query(S.getval(E[l][1])^S.getval(E[l][2]));
			}
			B=qwq;
			while(siz)
			{
				S.reset();
				--siz;
			}
			return;
		}
		int mid=(l+r)>>1;
		Query(l,mid,f[cur].ls);
		Query(mid+1,r,f[cur].rs);
		B=qwq;
		while(siz)
		{
			S.reset();
			--siz;
		}
	}
}tr;
struct node{
	int x,y;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
};
std::map<node,node> mp;
int main()
{
	int n,m;
	read(n,m);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		mp[(node){x,y}]=(node){0,z};
	}
	int _;
	read(_);
	tr.build(0,_);
	int opt,d;
	for(int i=1;i<=_;++i)
	{
		read(opt);
		if(opt==1)
		{
			read(x,y,d);
			mp[(node){x,y}]=(node){i,d};
		}
		else if(opt==2)
		{
			read(x,y);
			tr.Update(mp[(node){x,y}].x,i-1,0,_,1,(NODE){x,y,mp[(node){x,y}].y});
			mp.erase(mp.find((node){x,y}));
		}
		else
		{
			E[i][0]=1;
			read(E[i][1],E[i][2]);
		}
	}
	for(auto it:mp)
	{
		tr.Update(it.second.x,_,0,_,1,(NODE){it.first.x,it.first.y,it.second.y});
	}
	tr.Query(0,_,1);
	for(int i=1;i<=_;++i)
	{
		if(E[i][0])
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}