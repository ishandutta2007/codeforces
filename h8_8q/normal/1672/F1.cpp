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

const int N=3e5+5;
int t,n,a[N],b[N];

vector<int> ps[N],nm[N],now;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		now.clear();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			ps[a[i]].push_back(i);
		}
		for(int i=1;i<=n;++i)
			if(ps[i].size())
				nm[ps[i].size()].push_back(i);
		for(int i=1;i<=n;++i)
			if(nm[i].size())
				now.push_back(i);
		for(int i=1;i<=n;++i)
		{
			vector<int> tmp;
			for(int j=0;j<now.size();++j)
				if(i<=now[j])
				{
					for(int k=0;k<nm[now[j]].size();++k)
					{
						tmp.push_back(ps[nm[now[j]][k]].back());
						ps[nm[now[j]][k]].pop_back();
					}
				}
			if(tmp.empty()) continue;
			for(int j=1;j<tmp.size();++j)
				b[tmp[j]]=a[tmp[j-1]];
			b[tmp[0]]=a[tmp.back()];
		}
		for(int i=1;i<=n;++i)
			write(b[i]),putchar(' ');
		puts("");
		for(int i=1;i<=n;++i)
			ps[i].clear(),nm[i].clear();
	}
	return 0;
}