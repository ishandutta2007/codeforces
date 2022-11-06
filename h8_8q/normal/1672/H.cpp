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

const int N=2e5+5;
int n,q,a[N],sm1[N],sm2[N],sm3[N],sm4[N];
char s[N];

inline int query1(int l,int r)
{
	return sm1[r]-sm1[l-1]+sm2[r]-sm2[l]+(a[l]==1)+(a[r]==1);
}

inline int query2(int l,int r)
{
	return sm3[r]-sm3[l-1]+sm4[r]-sm4[l]+(a[l]==0)+(a[r]==0);
}

signed main()
{
	n=read();q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		a[i]=s[i]-'0';
	for(int i=1;i<=n;++i)
	{
		sm1[i]=sm1[i-1]+(a[i]==0?1:-1);
		sm2[i]=sm2[i-1]+(i>=2&&a[i]==1&&a[i-1]==1);
		sm3[i]=sm3[i-1]+(a[i]==1?1:-1);
		sm4[i]=sm4[i-1]+(i>=2&&a[i]==0&&a[i-1]==0);
	}
	while(q--)
	{
		int l=read(),r=read(),ans=0;
		ans=max(ans,query1(l,r));
		ans=max(ans,query2(l,r));
		write(ans);puts("");
	}
	return 0;
}