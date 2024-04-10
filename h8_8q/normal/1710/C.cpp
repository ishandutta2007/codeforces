#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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

const int N=2e5+5,mod=998244353;
int n,a[N],dp[N][8][8];
char s[N];

signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		a[i]=s[i]-'0';
	dp[0][7][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<8;++j)
			for(int p=0;p<8;++p)
				if(dp[i][j][p])
				{
					int lim;
					if(a[i+1]==0)
					{
						int lim=(j^7);
						for(int k=0;k<8;++k)
							if((lim&k)==k)
							{
								int ne=p;
								if(k==3||k==4) ne|=1;
								if(k==5||k==2) ne|=2;
								if(k==6||k==1) ne|=4;
								dp[i+1][j][ne]=(dp[i+1][j][ne]+dp[i][j][p])%mod;
							}	
					}
					else
					{
						for(int k=0;k<8;++k)
						{
							int ne=p;
							if(k==3||k==4) ne|=1;
							if(k==5||k==2) ne|=2;
							if(k==6||k==1) ne|=4;
							dp[i+1][j&k][ne]=(dp[i+1][j&k][ne]+dp[i][j][p])%mod;
						}
					}
				}
	int ans=0;
	for(int i=0;i<8;++i)
		ans=(ans+dp[n][i][7])%mod;
	write(ans);
	return 0;
}