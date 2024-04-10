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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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
int t,n,a[N],b[N],c[N];

struct DSU
{
	int fa[N],siz[N];
	inline void init(int x)
	{
		for(int i=1;i<=x;++i)
			fa[i]=i,siz[i]=1;
	}
	int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y)
	{
		int f1=find(x),f2=find(y);
		if(f1==f2) return 0;
		fa[f1]=f2;siz[f2]+=siz[f1];
		return 1;
	}
}dsu;

vector<int> nb;

inline int query()
{
	if(nb.size()==1)
		return 0;
	int len=nb.size()-1;
	sort(nb.begin(),nb.end());
	int l=0,r=len;c[0]=nb[l++];
	for(int i=1;i<=len;i+=2)
		if((i/2)%2==0)
			c[i]=nb[r--],c[i+1]=nb[r--];
		else c[i]=nb[l++],c[i+1]=nb[l++];
	int res=abs(c[len]-c[len-1])+abs(c[1]-c[0]);
	for(int i=len;i>=2;--i)
		res+=abs(c[i]-c[i-2]);
	return res;
}

inline bool cmp(int x,int y)
{
	if(x%2==y%2)
		return x<y;
	return x%2<y%2;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			b[i]=read();
		dsu.init(n);
		for(int i=1;i<=n;++i)
			dsu.merge(a[i],b[i]);
		vector<int> hv;int ans=0,nm=0;
		for(int i=1;i<=n;++i)
			if(dsu.find(i)==i)
				nm+=(dsu.siz[i]%2==1);
		nm=n-nm;if(nm%2==1) nm--;
		for(int i=1;i<=nm/2;++i)
			ans+=n-i+1-i;
		write(ans*2);puts("");
	}
	return 0;
}