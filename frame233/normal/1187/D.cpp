// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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

const int N=300005;
struct seg_tr{
	struct node{
		int ls,rs,minn;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
	}
	int build(const int &l,const int &r,int *arr)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].ls=f[cur].rs=0;
			f[cur].minn=arr[l];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur);
		return cur;
	}
	void Update(const int &l,const int &r,const int &pos,const int &cur)
	{
		if(l==r)
		{
			f[cur].minn=Inf;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(l,mid,pos,f[cur].ls);
		else Update(mid+1,r,pos,f[cur].rs);
		PushUp(cur);
	}
	int Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].minn;
		}
		int mid=(l+r)>>1;
		return min(L<=mid?Query(L,R,l,mid,f[cur].ls):Inf,R>mid?Query(L,R,mid+1,r,f[cur].rs):Inf);
	}
}tr;
int a[N];
std::vector<int> v[N];
void MAIN()
{
	int n,x;
	read(n);
	for(int i=1;i<=n;++i) v[i].clear();
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i) std::reverse(v[i].begin(),v[i].end());
	tr.node_cnt=0;
	tr.build(1,n,a);
	for(int i=1;i<=n;++i)
	{
		read(x);
		if(v[x].size())
		{
			if(tr.Query(1,*--v[x].end(),1,n,1)!=x)
			{
				printf("NO\n");
				for(int j=i+1;j<=n;++j) read(x);
				return;
			}
			tr.Update(1,n,*--v[x].end(),1);
			v[x].pop_back();
		}
		else
		{
			printf("NO\n");
			for(int j=i+1;j<=n;++j) read(x);
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int _;
	read(_);
	while(_--)
	{
		MAIN();
	}
	return 0;
}