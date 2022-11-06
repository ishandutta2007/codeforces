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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2e5+5;
int t,n,a[N],b[N],ans[N];

vector<int> v[N],s[N];

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
		for(int i=1;i<=n;++i)
			v[a[i]].push_back(b[i]);
		for(int i=1;i<=n;++i)
			sort(v[i].begin(),v[i].end());
		for(int i=1;i<=n;++i)
		{
			s[i].push_back(0);
			for(int j=0;j<v[i].size();++j)
				s[i].push_back(v[i][j]+s[i][j]);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=v[i].size();++j)
				ans[j]+=s[i][v[i].size()]-s[i][v[i].size()%j];
		for(int i=1;i<=n;++i)
		{
			v[i].clear();
			s[i].clear();
			printf("%lld ",ans[i]);
			ans[i]=0;
		}
		printf("\n");
	}
	return 0;
}