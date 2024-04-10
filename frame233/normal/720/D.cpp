// luogu-judger-enable-o2
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
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=1000005,mod=1000000007;
struct node{
	int x1,y1,x2,y2;
	Finline bool operator < (const node &o)const
	{
		return x1<o.x1;
	}
}a[N];
std::vector<std::pair<int,int> > c[N<<1],d[N<<1];
int t[N<<1];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
struct seg_tr{
	struct Node{
		int ls,rs;
		int sum;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].sum=f[f[x].ls].sum;
		add(f[x].sum,f[f[x].rs].sum);
	}
	Finline void cover(const int &cur)
	{
		f[cur].sum=0;
		f[cur].tag=1;
	}
	Finline void PushDown(const int &cur)
	{
		if(f[cur].tag)
		{
			cover(f[cur].ls);
			cover(f[cur].rs);
			f[cur].tag=0;
		}
	}
	int build(const int &l,const int &r)
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
	void Modify(const int &pos,const int &l,const int &r,const int &cur,const int &val)
	{
		if(l==r)
		{
			add(f[cur].sum,val);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(pos<=mid) Modify(pos,l,mid,f[cur].ls,val);
		else Modify(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			cover(cur);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].sum;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		return ((L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0))%mod;
	}
}tr;
std::multiset<int,std::greater<int> > s;
int tmp[N<<1];
int main()
{
	int n,m,k;
	read(n,m,k);
	int pos=0;
	for(int i=1;i<=k;++i)
	{
		read(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
		t[++pos]=a[i].x1;
		t[++pos]=a[i].x2+1;
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=k;++i)
	{
		a[i].x1=std::lower_bound(t+1,t+len+1,a[i].x1)-t;
		a[i].x2=std::lower_bound(t+1,t+len+1,a[i].x2+1)-t;
		c[a[i].x1].push_back(std::make_pair(a[i].y2,a[i].y1));
		d[a[i].x2].push_back(std::make_pair(a[i].y2,a[i].y1));
	}
//	for(int i=1;i<=len;++i)
//	{
//		std::sort(c[i].begin(),c[i].end());
//		std::reverse(c[i].begin(),c[i].end());
//	}
	s.insert(0);
	int root=tr.build(1,m);
	tr.Modify(1,1,m,root,1);
	for(int i=1;i<=len;++i)
	{
		if(t[i]==1)
		{
			for(auto it:c[i])
			{
				tr.Update(it.second,it.first,1,m,root);
				s.insert(it.first);
				s.insert(it.second);
			}
			continue;
		}
		if(t[i]>n)
		{
			break;
		}
		int cnt=0;
		for(auto it:c[i])
		{
			auto IT=s.lower_bound(it.first+1);
			++cnt;
			if(*IT>=it.first) tmp[cnt]=0;
			else tmp[cnt]=tr.Query((*IT)+1,it.first,1,m,root);
		}
		cnt=0;
		for(auto it:c[i])
		{
			if(it.first<m) tr.Modify(it.first+1,1,m,root,tmp[++cnt]);
			else ++cnt;
		}
		for(auto it:c[i])
		{
			tr.Update(it.second,it.first,1,m,root);
			s.insert(it.first);
			s.insert(it.second);
		}
		for(auto it:d[i])
		{
			s.erase(s.find(it.first));
			s.erase(s.find(it.second));
		}
	}
	auto it=s.lower_bound(m);
	printf("%d\n",tr.Query((*it)+1,m,1,m,root));
    return 0;
}