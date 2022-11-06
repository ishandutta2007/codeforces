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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

int t,a,b,k;

signed main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();k=read();
		int tx=a,ty=b;
		int s1=0,s2=0;
		for(int i=2;i*i<=a;++i)
			while(a%i==0)
				s1++,a/=i;
		if(a!=1) s1++;
		for(int i=2;i*i<=b;++i)
			while(b%i==0)
				s2++,b/=i;
		if(b!=1) s2++;
		if(tx==1&&ty==1)
			printf("NO\n");
		else if(k==1)
		{
			if((tx%ty==0||ty%tx==0)&&tx!=ty)
				printf("YES\n");
			else printf("NO\n");
		}
		else if(s1+s2>=k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}