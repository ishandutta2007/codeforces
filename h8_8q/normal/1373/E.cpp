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
	int res=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-'0';c=getchar();}
	return res*f;
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

const int N=155;
int t,n,k,now[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		int ans=1e18,sum,num;
		for(int i=0;i<=9;++i)
		{
			sum=0,num=0;
			for(int j=i;j<=i+k;++j) 
			{
				if(j>9) num++;
				sum+=j%10;
			}
			if(n<sum) continue;
			if((n-sum-num)%(k+1)!=0)
				continue;
			int tmp=(n-sum-num)/(k+1);
			clr(now,n+1);
			int m=0,fl=0;
			now[++m]=i;
			while(tmp)
			{
				if(tmp>=9) 
				{
					if(i+k<=9||fl)
						now[++m]=9,tmp-=9;
					else now[++m]=8,tmp-=8,fl=1;
				}
				else now[++m]=tmp,tmp=0;
			}
			int res=0;
			for(int j=m;j>=1;--j)
				res=res*10+now[j];
			ans=min(ans,res);
		}
		if(ans==1e18) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}