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

const int N=505;
int t,n,a[N];

inline bool ok(int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=4;++i)
			a[i]=read();
		int ans=0;
		for(int i=0;i<=1;++i)
			for(int j=0;j<=1;++j)
				for(int k=0;k<=1;++k)
					for(int p=0;p<=1;++p)
						if(ok(a[1]-i-j)&&ok(a[2]-j-k)&&ok(a[3]-k-p)&&ok(a[4]-p-i))
							ans=1;
		if(ans==1) printf("YES\n");
		else printf("NO\n");
    }
    return 0;
}

inline bool ok(int x)
{
	return x>=0&&(x<=n-2);
}