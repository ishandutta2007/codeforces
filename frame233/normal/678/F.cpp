// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define IT std::set<vec>::iterator 

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

const int N=300005;
bool used[N];
ll ans[N];
struct vec{
	ll x,y;
	Finline bool operator < (const vec &o)const{return x==o.x?y<o.y:x<o.x;}
	Finline vec operator + (const vec &o)const{return {x+o.x,y+o.y};}
	Finline vec operator - (const vec &o)const{return {x-o.x,y-o.y};}
	Finline ll operator * (const vec &o)const{return x*o.y-y*o.x;}
}E[N];
struct node{
	int k,id;
	Finline bool operator < (const node &o)const
	{
		return k>o.k;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<vec> v;
		std::vector<node> V;
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
	void Update(int L,int R,int l,int r,int cur,const vec &o)
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
	void Update(int pos,int l,int r,int cur,const node &o)
	{
		f[cur].V.push_back(o);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,o);
		else Update(pos,mid+1,r,f[cur].rs,o);
	}
	vec _q[N];
	int _l,_r;
	void Query(int l,int r,int cur)
	{
		std::sort(f[cur].v.begin(),f[cur].v.end());
		std::sort(f[cur].V.begin(),f[cur].V.end());
		_l=1,_r=0;
		for(auto it:f[cur].v)
		{
			while(_r-_l>=1&&(_q[_r]-_q[_r-1])*(it-_q[_r])>=0) --_r;
			_q[++_r]=it;
		}
		for(auto it:f[cur].V)
		{
			while(_r-_l>=1&&(_q[_l+1].y-_q[_l].y)>=(_q[_l+1].x-_q[_l].x)*it.k) ++_l;
			if(_l!=_r+1)
			{
				chmax(ans[it.id],-_q[_l].x*it.k+_q[_l].y);
			}
		}
		if(l==r) return;
		int mid=(l+r)>>1;
		Query(l,mid,f[cur].ls);
		Query(mid+1,r,f[cur].rs);
	}
}tr;
bool type[N];
int main()
{
	int _;
	read(_);
	tr.build(1,_);
	int opt,x;
	for(int i=1;i<=_;++i)
	{
		read(opt);
		if(opt==1)
		{
			read(E[i].x,E[i].y);
			used[i]=1;
		}
		else if(opt==2)
		{
			read(x);
			used[x]=0;
			tr.Update(x,i,1,_,1,E[x]);
		}
		else
		{
			type[i]=true;
			ans[i]=-3000000000000000000LL;
			read(x);
			tr.Update(i,1,_,1,{-x,i});
		}
	}
	for(int i=1;i<=_;++i)
	{
		if(used[i])
		{
			tr.Update(i,_,1,_,1,E[i]);
		}
	}
	tr.Query(1,_,1);
	for(int i=1;i<=_;++i)
	{
		if(type[i])
		{
			if(ans[i]<=-3000000000000000000LL) printf("EMPTY SET\n");
			else printf("%lld\n",ans[i]);
		}
	}
	return 0;
}