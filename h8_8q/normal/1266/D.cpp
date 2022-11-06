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

const int N=3e5+5;
int n,m,du[N];

struct Edge
{
	int u,v,w;
}e[N];

vector<Edge> ans;

vector<int> a1,a2;

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		e[i]=(Edge){u,v,w};
		du[u]-=w;du[v]+=w;
	}
	for(int i=1;i<=n;++i)
		if(du[i]>0) a1.push_back(i);
		else if(du[i]<0) a2.push_back(i);
	for(int l=0,r=0;l<a1.size();++l)
		while(du[a1[l]]>0)
		{
			while(du[a2[r]]==0) ++r;
			int tmp=min(du[a1[l]],-du[a2[r]]);
			ans.push_back((Edge){a2[r],a1[l],tmp});
			du[a1[l]]-=tmp;du[a2[r]]+=tmp;
		}
	printf("%lld\n",ans.size());
	for(int i=0;i<ans.size();++i)
		printf("%lld %lld %lld\n",ans[i].u,ans[i].v,ans[i].w);
	return 0;
}