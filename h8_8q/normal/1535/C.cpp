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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int t,n,ps[N];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int last=n+1;
		for(int i=n;i>=1;--i)
		{
			if(s[i]!='?') last=i;
			ps[i]=last;
		}
		if(ps[1]==n+1)
		{
			printf("%lld\n",n*(n+1)/2);
			continue;
		}
		int l=1,r=ps[1],ans=0;
		for(;l<=n;++l)
		{
			r=max(r,min(n,ps[l]));
			while(r+1<=n&&(((s[r+1]-'0')^((r+1-l)&1))==((s[ps[l]]-'0')^((ps[l]-l)&1))||s[r+1]=='?'))
				++r;
			ans+=r-l+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}