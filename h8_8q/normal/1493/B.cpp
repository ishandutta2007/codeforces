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

int t,n,m,a,b;
int fs[20]={0,1,5,-1,-1,2,-1,-1,8,-1};

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		scanf("%lld:%lld",&a,&b);
		int flag=0;
		for(int i=a,st=1;!flag;i=(i+1)%n,st=0)
			for(int j=(st?b:0);!flag&&j<m;++j)
			{
				int p1=fs[i/10],p2=fs[i%10];
				int p3=fs[j/10],p4=fs[j%10];
				if(p1==-1||p2==-1||p3==-1||p4==-1) continue;
				if(p2*10+p1>=m||p4*10+p3>=n) continue;
				if(i<10) printf("0");
				printf("%lld",i);
				printf(":");
				if(j<10) printf("0");
				printf("%lld",j);
				printf("\n");
				flag=1;
			}
	}
	return 0;
}