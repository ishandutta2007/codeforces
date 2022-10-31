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

const int N=150005;
int p,tot;
struct node{
	int val,cnt;
};
std::vector<node> tmp;
int a[N];
Finline std::vector<node> merge(std::vector<node> ans,const std::vector<node> &b)
{
	for(auto it:b)
	{
		bool flag=false;
		for(auto &itt:ans)
		{
			if(itt.val==it.val)
			{
				flag=true;
				itt.cnt+=it.cnt;
				break;
			}
		}
		if(!flag)
		{
			ans.push_back(it);
		}
	}
	while((int)ans.size()>tot)
	{
		int minn=inf;
		for(int i=0;i<=tot;++i)
		{
			chmin(minn,ans[i].cnt);
		}
		for(int i=0;i<=tot;++i)
		{
			ans[i].cnt-=minn;
		}
		tmp.clear();
		for(auto it:ans)
		{
			if(it.cnt)
			{
				tmp.push_back(it);
			}
		}
		ans=tmp;
	}
	return ans;
}
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<node> val;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=merge(f[f[x].ls].val,f[f[x].rs].val);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].val.push_back((node){a[l],1});
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void cover(int cur,int l,int r,int C)
	{
		f[cur].val.clear();
		f[cur].val.push_back((node){C,r-l+1});
		f[cur].tag=C;
	}
	Finline void PushDown(int cur,int l,int r)
	{
		if(f[cur].tag)
		{
			int mid=(l+r)>>1;
			cover(f[cur].ls,l,mid,f[cur].tag);
			cover(f[cur].rs,mid+1,r,f[cur].tag);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur,int C)
	{
		if(L<=l&&r<=R)
		{
			cover(cur,l,r,C);
			return;
		}
		PushDown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	std::vector<node> Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].val;
		}
		PushDown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			return merge(Query(L,R,l,mid,f[cur].ls),Query(L,R,mid+1,r,f[cur].rs));
		}
		if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,_,p;
	read(n,_,p);
	tot=100/p;
	for(int i=1;i<=n;++i) read(a[i]);
	tr.build(1,n);
	int opt,l,r,v;
	std::vector<node> qwq;
	while(_--)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r,v);
			tr.Update(l,r,1,n,1,v);
		}
		else
		{
			read(l,r);
			qwq=tr.Query(l,r,1,n,1);
			printf("%d ",(int)qwq.size());
			for(auto it:qwq) printf("%d ",it.val);
			printf("\n");
		}
	}
	return 0;
}