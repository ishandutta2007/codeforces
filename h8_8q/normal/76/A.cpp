#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e5+5;
int n,m,a,b,fa[N],sum;

struct Edge
{
	int u,v,w1,w2;
	bool operator < (const Edge &x)const
	{
		return w1<x.w1;
	}
}e[N];

inline bool cmp(Edge a,Edge b)
{
	return a.w2<b.w2;
}

vector<Edge> hav,ne;

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2) fa[f1]=f2,--sum;
	return f1!=f2;
}

signed main()
{
	n=read();m=read();
	a=read();b=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		int w1=read(),w2=read();
		e[i]=(Edge){u,v,w1,w2};
	}
	sort(e+1,e+1+m);
	int ans=INF;
	for(int i=1;i<=m;++i)
	{
		hav.push_back(e[i]);sum=n;
		for(int j=1;j<=n;++j) fa[j]=j;
		sort(hav.begin(),hav.end(),cmp);
		int res=0;
		for(int j=0;j<hav.size();++j)
			if(merge(hav[j].u,hav[j].v))
				res=max(res,hav[j].w2),ne.push_back(hav[j]);
		if(sum==1) ans=min(ans,e[i].w1*a+res*b);
		hav=ne;ne.clear();
	}
	printf("%lld\n",ans==INF?-1:ans);
	return 0;
}