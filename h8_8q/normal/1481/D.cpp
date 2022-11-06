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
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
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

const int N=1005;
int t,n,m,mp[N][N];
char s[N][N];

signed main()
{
	t=read();
    while(t--)
    {
        n=read();m=read();
        for(int i=1;i<=n;++i)
        	scanf("%s",s[i]+1);
        if(n==2)
        {
        	if(s[1][2]==s[2][1])
        	{
        		printf("YES\n");
        		for(int i=1;i<=m+1;++i)
        			printf("%lld ",i%2+1);
			}
			else
			{
				if(m%2==0) printf("NO");
				else
				{
					printf("YES\n");
					for(int i=1;i<=m+1;++i)
        				printf("%lld ",i%2+1);
				}
			}
		}
		else
		{
			int flag=0;
			for(int i=1;i<=n&&!flag;++i)
				for(int j=i+1;j<=n&&!flag;++j)
					if(s[i][j]==s[j][i])
					{
						printf("YES\n");
						for(int k=1;k<=m+1;++k)
        					if(k%2==1) printf("%lld ",i);
        					else printf("%lld ",j);
        				flag=1;
					}
			if(!flag)
			{
				if(s[1][2]==s[2][3]&&s[2][3]==s[3][1])
				{
					printf("YES\n");
					for(int i=1;i<=m+1;++i)
						printf("%lld ",i%3+1);
				}
				else
				{
					int a,b,c;
					if(s[1][2]!=s[2][3]&&s[2][3]==s[3][1])
						a=1,b=2,c=3;
					else if(s[1][2]!=s[2][3]&&s[1][2]==s[3][1])
						a=2,b=3,c=1;
					else a=3,b=1,c=2;
					if(m%2==0)
					{
						if(m%4==0)
						{
							printf("YES\n");
							printf("%lld ",c);
							for(int i=1;i<=m;++i)
								if(i%4==1) printf("%lld ",b);
								else if(i%4==2) printf("%lld ",c);
								else if(i%4==3) printf("%lld ",a);
								else printf("%lld ",c);
						}
						else
						{
							printf("YES\n");
							printf("%lld %lld ",b,c);
							for(int i=1;i<=m-2;++i)
								if(i%4==1) printf("%lld ",b);
								else if(i%4==2) printf("%lld ",c);
								else if(i%4==3) printf("%lld ",a);
								else printf("%lld ",c);
							printf("%lld ",a);
						}
					}
					else
					{
						printf("YES\n");
						printf("%lld ",c);
						for(int i=1;i<=m;++i)
							if(i%2==1) printf("%lld ",b);
							else printf("%lld ",a);
					}
				}
			}
		}
		printf("\n");
    }
	return 0;
}