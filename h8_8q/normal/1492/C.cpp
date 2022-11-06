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
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
int n,m,ans,pre[N],suc[N];
char s[N],t[N];

signed main()
{
	n=read();m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1,j=1;i<=n;++i)
	{
		if(s[i]==t[j]) pre[j++]=i;
		if(j==m+1) break;
	}
	for(int i=n,j=m;i>=1;--i)
	{
		if(s[i]==t[j]) suc[j--]=i;
		if(j==0) break;
	}
	for(int i=1;i<=m-1;++i)
		ans=max(ans,suc[i+1]-pre[i]);
	printf("%lld\n",ans);
	return 0;
}