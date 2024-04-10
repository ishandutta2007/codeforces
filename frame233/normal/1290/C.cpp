// Author -- Frame

#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
#include<queue>

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

const int N=600005;
int a[N];
std::vector<int> v[N];
int fa[N],val[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int ans;
void merge(int a,int b)
{
	int x=find(a),y=find(b);
	if(x==y) return;
	fa[x]=y;
	val[y]+=val[x];
}
int main()
{
	int n,k;
	read(n,k);
	int nd=k<<1|1;
	fa[nd]=nd;
	val[nd]=inf;
	for(int i=1;i<=k<<1;++i) fa[i]=i;
	for(int i=k+1;i<=k<<1;++i) val[i]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%1d",&a[i]);
	}
	int x;
	for(int i=1;i<=k;++i)
	{
		int len;
		read(len);
		while(len--)
		{
			read(x);
			v[x].push_back(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!a[i])
		{
			if((int)v[i].size()==1)
			{
				int a=find(v[i][0]);
				int b=find(v[i][0]+k);
				ans-=min(val[a],val[b]);
				merge(nd,v[i][0]);
				b=find(b);
				ans+=val[b];
			}
			else
 			{
 				int a=find(v[i][0]);
 				int b=find(v[i][1]+k);
 				int c=find(v[i][0]+k);
 				int d=find(v[i][1]);
 				if(a==b||a==d||d==a||d==c)
 				{
 					printf("%d\n",ans);
 					continue;
 				}
 				ans-=min(val[a],val[c]);
 				ans-=min(val[b],val[d]);
				merge(v[i][0],v[i][1]+k);
				merge(v[i][0]+k,v[i][1]);
				a=find(a);
				b=find(b);
				c=find(c);
				d=find(d);
				ans+=min(val[a],val[c]);
			}
		}
		else
		{
			if(!v[i].size())
			{
				printf("%d\n",ans);
				continue;
			}
			if((int)v[i].size()==1)
			{
				int a=find(v[i][0]);
				int b=find(v[i][0]+k);
				ans-=min(val[a],val[b]);
				merge(nd,v[i][0]+k);
				a=find(a);
				ans+=val[a];
			}
			else
			{
 				int a=find(v[i][0]);
 				int b=find(v[i][1]+k);
 				int c=find(v[i][0]+k);
 				int d=find(v[i][1]);
 				if(a==d||b==c||a==b||c==d)
 				{
 					printf("%d\n",ans);
 					continue;
 				}
 				ans-=min(val[a],val[c]);
 				ans-=min(val[b],val[d]);
				merge(v[i][0],v[i][1]);
				merge(v[i][0]+k,v[i][1]+k);
				a=find(a);
				b=find(b);
				c=find(c);
				d=find(d);
				ans+=min(val[a],val[c]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}