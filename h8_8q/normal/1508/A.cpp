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

const int N=1e6+5;
int t,n;
char s[4][N],ans[N];

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	//printf("%lld\n",t);
	while(t--)
	{
		n=read();
		scanf("%s",s[1]+1);
		scanf("%s",s[2]+1);
		scanf("%s",s[3]+1);
		//printf("%lld\n",n);
		//puts(s[1]+1);puts(s[2]+1);puts(s[3]+1);
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n*2;++i)
		{
			if(s[1][i]=='1') s1++;
			if(s[2][i]=='1') s2++;
			if(s[3][i]=='1') s3++;
		}
		int num=0;
		if(s1<=n) num++;
		if(s2<=n) num++;
		if(s3<=n) num++;
		if(num>=2)
		{
			if(s3<=n)
			{
				if(s1>n)
				{
					for(int i=1;i<=2*n;++i)
						s[1][i]=s[3][i];
				}
				else
				{
					for(int i=1;i<=2*n;++i)
						s[2][i]=s[3][i];
				}
			}
			int i=1,j=1;
			for(;i<=n*2&&j<=n*2;)
			{
				if(s[1][i]==s[2][j])
					printf("%c",s[1][i]),++i,++j;
				else if(s[1][i]=='1')
					printf("1"),++i;
				else printf("1"),++j;
			}
			for(;i<=n*2;++i) printf("%c",s[1][i]);
			for(;j<=n*2;++j) printf("%c",s[2][j]);
			printf("\n");	
		}
		else
		{
			s1=n*2-s1;s2=n*2-s2;s3=n*2-s3;
			if(s3<=n)
			{
				if(s1>n)
				{
					for(int i=1;i<=2*n;++i)
						s[1][i]=s[3][i];
				}
				else
				{
					for(int i=1;i<=2*n;++i)
						s[2][i]=s[3][i];
				}
			}
			int i=1,j=1;
			for(;i<=n*2&&j<=n*2;)
			{
				if(s[1][i]==s[2][j])
					printf("%c",s[1][i]),++i,++j;
				else if(s[1][i]=='0')
					printf("0"),++i;
				else printf("0"),++j;
			}
			for(;i<=n*2;++i) printf("%c",s[1][i]);
			for(;j<=n*2;++j) printf("%c",s[2][j]);
			printf("\n");	
		}
	}
	return 0;
}