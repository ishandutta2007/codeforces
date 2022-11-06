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

const int N=35005,K=105;
int n,k,a[N],pre[N],suc[N],last[N],dp[N][K],nl,nr,now;

inline int val(int l,int r);
void merge(int l,int r,int L,int R,int id);

signed main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	nl=1;nr=0;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;++i)
		last[i]=n+1;
	for(int i=n;i>=1;--i)
	{
		suc[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=k;++i)
		merge(i,n,0,n,i);
	printf("%lld\n",dp[n][k]);
	return 0;
}

inline int val(int l,int r)
{
	while(nl<l)
	{
		if(suc[nl]<=nr)
			now-=suc[nl]-nl;
		++nl;
	}
	while(nl>l){--nl;if(suc[nl]<=nr)now+=suc[nl]-nl;}
	while(nr<r){++nr;if(pre[nr]>=nl)now+=nr-pre[nr];}
	while(nr>r){if(pre[nr]>=nl)now-=nr-pre[nr];--nr;}
	return now;
}

void merge(int l,int r,int L,int R,int id)
{
	if(l>r||L>R) return;
	int mn=1e18,ps=-1;
	for(int i=L;i<mid&&i<=R;++i)
	{
		int tmp=dp[i][id-1]+val(i+1,mid);
		if(tmp<mn) mn=tmp,ps=i;
	}
	dp[mid][id]=mn;
	merge(l,mid-1,L,ps,id);
	merge(mid+1,r,ps,R,id);
}