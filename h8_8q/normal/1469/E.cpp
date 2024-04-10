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

const int N=1e7+5;
int t,n,m,k,vis[N],sum[N];
char s[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();k=read();
		scanf("%s",s+1);
		m=min(k,20ll);
		int now=0,num=0,fl=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0') num=0;
			else num++;
			sum[i]=num;
		}
		for(int i=1;i<=m;++i)
			now=((now<<1)|(s[i]-'0'));
		if(sum[0]>=k-m) vis[((1<<m)-1)^now]=1;
		for(int i=m+1;i<=n;++i)
		{
			now=(((now<<1)&((1<<m)-1))|(s[i]-'0'));
			if(sum[i-m]>=k-m) vis[((1<<m)-1)^now]=1;
		}
		for(int i=0;i<(1<<m);++i)
			if(!vis[i])
			{
				fl=1;
				printf("YES\n");
				for(int j=1;j<=k-m;++j)
					printf("0");
				for(int j=m-1;j>=0;--j)
					printf("%lld",((i>>j)&1));
				printf("\n");
				break;
			}
		if(!fl) printf("NO\n");
qwq:	now=0;
		for(int i=1;i<=m;++i)
			now=((now<<1)|(s[i]-'0'));
		vis[((1<<m)-1)^now]=0;
		for(int i=m+1;i<=n;++i)
		{
			now=(((now<<1)&((1<<m)-1))|(s[i]-'0'));
			vis[((1<<m)-1)^now]=0;
		}
	}
	return 0;
}