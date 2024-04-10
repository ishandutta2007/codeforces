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
int n,pri[N],m,vis[N],p1[N],a1[N],a2[N];

signed main()
{
	for(int i=2;i<=10000000;++i)
	{
		if(!vis[i]) pri[++m]=i;
		for(int j=1;j<=m&&i*pri[j]<=10000000;++j)
		{
			vis[i*pri[j]]=1;
			if(!p1[i*pri[j]]) p1[i*pri[j]]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
	n=read();
	for(int i=1;i<=n;++i)
	{
		int a=read();
		if(!p1[a])
			a1[i]=a2[i]=-1;
		else
		{
			a1[i]=p1[a];
			int tmp=a;
			while(tmp%p1[a]==0)
				tmp/=p1[a];
			if(tmp==1) a1[i]=a2[i]=-1;
			else a2[i]=tmp;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",a1[i]);
	printf("\n");
	for(int i=1;i<=n;++i)
		printf("%d ",a2[i]);
	return 0;
}