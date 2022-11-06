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

const int N=2e6+5;
int t,n,m,sm[N],a1[N],a2[N];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		scanf("%s",s+1);
		for(int i=1;i<=n*m;++i)
			sm[i]=sm[i-1]+s[i]-'0',a1[i]=a2[i]=0;
		a1[n*m+1]=a2[n*m+1]=0;
		for(int i=1;i<=n*m;++i)
			if(sm[i]-sm[max(0,i-m)]!=0)
				a1[i]++;
		for(int i=1;i<=m;++i)
		{
			int now=0;
			for(int j=i;j<=n*m;j+=m)
			{
				now+=s[j]-'0';
				if(!now) continue;
				a2[j]++;a2[j+m]--;
			}
		}
		for(int i=1;i<=n*m;++i)
		{
			a2[i]+=a2[i-1];
			if(i+m<=n*m) a1[i+m]+=a1[i];
			write(a1[i]+a2[i]);
			putchar(' ');
		}
		puts("");
	}
	return 0;
}