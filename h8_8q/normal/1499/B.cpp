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

const int N=105;
int t,n;
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int fl=0;
		for(int i=0;i<=n;++i)
		{
			int tmp=1,last=-1;
			for(int j=1;j<=i;++j)
				if(s[j]=='1')
				{
					if(j-last==1)
					{
						tmp=0;
						break;
					}
					last=j;
				}
			last=-1;
			for(int j=i+1;j<=n;++j)
				if(s[j]=='0')
				{
					if(j-last==1)
					{
						tmp=0;
						break;
					}
					last=j;
				}
			if(tmp)
			{
				fl=1;
				break;
			}
		}
		if(fl) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}