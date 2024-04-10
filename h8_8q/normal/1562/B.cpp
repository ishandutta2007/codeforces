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

const int N=55;
int t,k,sum[15];
char s[N];

inline bool check(int x)
{
	if(x==1) return 0;
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 0;
	return 1;
}

signed main()
{
	t=read();
	while(t--)
	{
		k=read();
		scanf("%s",s+1);
		for(int i=1;i<=9;++i)
			sum[i]=0;
		for(int i=1;i<=k;++i)
			sum[s[i]-'0']++;
		int flag=0;
		for(int i=1;i<=9;++i)
			if(i!=2&&i!=3&&i!=5&&i!=7&&sum[i])
			{
				printf("1\n%lld\n",i);
				flag=1;break;
			}
		if(flag) continue;
		if(sum[2]>=2) printf("2\n22\n");
		else if(sum[3]>=2) printf("2\n33\n");
		else if(sum[5]>=2) printf("2\n55\n");
		else if(sum[7]>=2) printf("2\n77\n");
		else
		{
			for(int i=0;i<(1<<k);++i)
			{
				int tmp=0,sum=0;
				for(int j=1;j<=k;++j)
					if((i>>(j-1))&1)
						tmp=tmp*10+s[j]-'0',++sum;
				if(!check(tmp))
				{
					printf("%lld\n%lld\n",sum,tmp);
					break;
				}
			}
		}
	}
	return 0;
}