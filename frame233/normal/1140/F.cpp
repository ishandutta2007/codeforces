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
struct _Node{
	int *pos;
	int val;
};
std::vector<_Node> t;
ll res;
struct Union_set{
	int fa[N<<1],rnk[N<<1];
	int cx[N<<1],cy[N<<1];
	int find(int x){return x==fa[x]?x:find(fa[x]);}
	void init(int n)
	{
		for(int i=1;i<=n;++i)
		{
			fa[i]=i;
			fa[i+n]=i+n;
			cx[i]=1;
			cy[i+n]=1;
		}
	}
	int merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		res-=1ll*cx[x]*cy[x];
		res-=1ll*cx[y]*cy[y];
		if(rnk[x]<=rnk[y])
		{
			t.push_back({fa+x,fa[x]});
			t.push_back({cx+y,cx[y]});
			t.push_back({cy+y,cy[y]});
			fa[x]=y;
			cx[y]+=cx[x];
			cy[y]+=cy[x];
			res+=1ll*cx[y]*cy[y];
			if(rnk[x]==rnk[y])
			{
				t.push_back({rnk+y,rnk[y]});
				++rnk[y];
				return 4;
			}
		}
		else
		{
			t.push_back({fa+y,fa[y]});
			t.push_back({cx+x,cx[x]});
			t.push_back({cy+x,cy[x]});
			fa[y]=x;
			cx[x]+=cx[y];
			cy[x]+=cy[y];
			res+=1ll*cx[x]*cy[x];
		}
		return 3;
	}
	void reset()
	{
		*t.back().pos=t.back().val;
		t.pop_back();
	}
}S;
struct node{
	int x,y;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
};
ll ans[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<node> v;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int L,int R,int l,int r,int cur,const node &o)
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
		ll tmp=res;
		int cnt=0;
		for(auto it:f[cur].v)
		{
			cnt+=S.merge(it.x,it.y);
		}
		if(l==r)
		{
			ans[l]=res;
			res=tmp;
			while(cnt--) S.reset();
			return;
		}
		int mid=(l+r)>>1;
		Query(l,mid,f[cur].ls);
		Query(mid+1,r,f[cur].rs);
		res=tmp;
		while(cnt--) S.reset();
	}
}tr;
std::map<node,int> mp;
int main()
{
	int q;
	read(q);
	S.init(N-3);
	tr.build(1,q);
	int x,y;
	for(int i=1;i<=q;++i)
	{
		read(x,y);
		node tmp=(node){x,y+N-3};
		if(mp.find(tmp)!=mp.end())
		{
			tr.Update(mp[tmp],i-1,1,q,1,tmp);
			mp.erase(mp.find(tmp));
		}
		else
		{
			mp[tmp]=i;
		}
	}
	for(auto it:mp)
	{
		tr.Update(it.second,q,1,q,1,it.first);
	}
	tr.Query(1,q,1);
	for(int i=1;i<=q;++i) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}