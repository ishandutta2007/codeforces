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

const int N=3e5+5;
int n,m,k,a[N],b[N],c[N],A,B,C,ans=-1e18;

signed main()
{
	n=read();m=read();k=read();
	
	for(int i=1;i<=n;++i) a[i]=read(),A+=a[i];
	for(int i=1;i<=m;++i) b[i]=read(),B+=b[i];
	for(int i=1;i<=k;++i) c[i]=read(),C+=c[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sort(c+1,c+1+k);
	ans=max(ans,A-B-C);
	ans=max(ans,A+max(B-C,C-B));
	ans=max(ans,A+B+C-b[1]*2-c[1]*2);
	ans=max(ans,B-A-C);
	ans=max(ans,B+max(A-C,C-A));
	ans=max(ans,A+B+C-a[1]*2-c[1]*2);
	ans=max(ans,C-A-B);
	ans=max(ans,C+max(A-B,B-A));
	ans=max(ans,A+B+C-a[1]*2-b[1]*2);
	printf("%lld\n",ans);
	return 0;
}