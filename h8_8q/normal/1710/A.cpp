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

int t,n,m,k,s1,s2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();k=read();
		s1=0;s2=0;int mx=0,f1=0,f2=0,f3=0,f4=0;
		for(int i=1;i<=k;++i)
		{
			int x=read();
			if(x/n>2) f1=1;
			if(x/n>=2)
			{
				if(m-s1>1)
					s1+=x/n;
				else f3=1;
			}
			if(x/m>2) f2=1;
			if(x/m>=2)
			{
				if(n-s2>1)
					s2+=x/m;
				else f4=1;
			}
			
			mx=max(mx,x);
		}
		if(s1>=m) f3=1;
		if(s2>=n) f4=1;
		if(mx>=n*m)
			puts("YES");
		else
		{
			if(((s1>=m||f1)&&f3)||((s2>=n||f2)&&f4)) puts("YES");
			else puts("NO");
		}
		
	}
	return 0;
}