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
int t,n,b[N],c[N],suc[N];
char a[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();suc[n+1]=0;
		scanf("%s",a+1);
		if(n%2==1)
		{
			printf("NO\n");
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='0') sum++;
		if(sum%2==1)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1,j=0,k=0;i<=n;++i)
		{
			if(a[i]=='0')
			{
				j++;
				if(j&1) b[i]=0,c[i]=1;
				else b[i]=1,c[i]=0;
			}
			else
			{
				k++;
				if(k<=(n-sum)/2) b[i]=c[i]=1;
				else b[i]=c[i]=0;
			}
		}
		int fl=1,n1=0,n2=0;
		for(int i=1;i<=n;++i)
		{
			n1+=b[i]?1:-1;
			n2+=b[i]?1:-1;
			if(n1<0||n2<0)
			{
				fl=0;
				break;
			}
		}
		if(fl)
		{
			printf("YES\n");
			for(int i=1;i<=n;++i)
				if(b[i]) printf("(");
				else printf(")");
			printf("\n");
			for(int i=1;i<=n;++i)
				if(c[i]) printf("(");
				else printf(")");
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}