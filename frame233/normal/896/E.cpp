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
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=500005;
const int block_size=700;
int a[N];
int L[N],R[N];
int build(int n)
{
	int cur=0,tmp=block_size;
	for(int i=1;i<=n;++i)
	{
		++tmp;
		if(tmp>block_size)
		{
			R[cur]=i-1;
			tmp=1;
			++cur;
			L[cur]=i;
		}
	}
	R[cur]=n;
	return cur;
}
int fa[N],siz[N],root[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
Finline void merge(int x,int y)
{
	if(!root[y])
	{
		root[y]=root[x];
		a[root[x]]=y;
		root[x]=0;
	}
	else
	{
		fa[root[x]]=root[y];
		siz[root[y]]+=siz[root[x]];
		siz[root[x]]=0;
		root[x]=0;
	}
}
int opt[N],_L[N],_R[N],_x[N];
int ans[N];
int n,m;
int l,r,maxx,tag;
void Update(int x)
{
	if(maxx<=x) return;
	if(maxx<=(x<<1))
	{
		for(int i=x+1+tag;i<=maxx+tag;++i)
		{
			if(root[i])
			{
				merge(i,i-x);
			}
		}
		maxx=x;
	}
	else
	{
		for(int i=1+tag;i<=x+tag;++i)
		{
			if(root[i])
			{
				merge(i,i+x);
			}
		}
		tag+=x;
		maxx-=x;
	}
}
int b[N];
void brute_Upd(int L,int R,int x)
{
	maxx=0;
	for(int i=l;i<=r;++i) b[i]=a[i];
	for(int i=l;i<=r;++i)
	{
		a[i]=b[find(i)];
		if(find(i)<l||find(i)>r) DEBUG;
		root[a[i]]=0;
		a[i]-=tag;
	}
	for(int i=L;i<=R;++i)
	{
		if(a[i]>x)
		{
			a[i]-=x;
		}
	}
	for(int i=l;i<=r;++i)
	{
		fa[i]=i;
		siz[i]=0;
		if(!root[a[i]]) root[a[i]]=i,siz[i]=1;
		else fa[i]=root[a[i]],++siz[root[a[i]]];
		chmax(maxx,a[i]);
	}
	tag=0;
}
int Query(int x)
{
	if(x+tag>=N) return 0;
	return siz[root[x+tag]];
}
int brute_Qry(int L,int R,int x)
{
	int ans=0;
	for(int i=L;i<=R;++i)
	{
		if(a[find(i)]-tag==x)
		{
			++ans;
		}
	}
	return ans;
}
void solve(int id)
{
	memset(siz,0,sizeof(siz));
	memset(root,0,sizeof(root));
	tag=0;
	l=L[id],r=R[id];
	maxx=0;
	for(int i=l;i<=r;++i)
	{	
		chmax(maxx,a[i]);
	}
	for(int i=0;i<=maxx;++i)
	{
		root[i]=0;
	}
	for(int i=l;i<=r;++i)
	{
		fa[i]=i;
		siz[i]=0;
		if(!root[a[i]]) root[a[i]]=i,siz[i]=1;
		else fa[i]=root[a[i]],++siz[root[a[i]]];
	}
	for(int i=1;i<=m;++i)
	{
		if(_R[i]<l||_L[i]>r) continue;
		if(opt[i]==1)
		{
			if(_L[i]<=l&&_R[i]>=r)
			{
				Update(_x[i]);
			}
			else
			{
				brute_Upd(max(l,_L[i]),min(r,_R[i]),_x[i]);
			}
		}
		else
		{
			if(_L[i]<=l&&_R[i]>=r)
			{
				ans[i]+=Query(_x[i]);
			}
			else
			{
				ans[i]+=brute_Qry(max(l,_L[i]),min(r,_R[i]),_x[i]);
			}
		}
	}
}
int main()
{
	read(n,m);
	int tot=build(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=m;++i)
	{
		read(opt[i],_L[i],_R[i],_x[i]);
	}
	for(int i=1;i<=tot;++i)
	{
		solve(i);
	}
	for(int i=1;i<=m;++i)
	{
		if(opt[i]==2)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}