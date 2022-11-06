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

const int N=1e5+5,mod=1e9+7;
int n,q,sm[N],ans[100][100],jc[N],dp[N],dp2[N],Ans;
char s[N];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	jc[0]=1;
	for(int i=1;i<=n;++i)
		sm[s[i]-'A'+1]++,jc[i]=jc[i-1]*i%mod;
	dp[0]=1;
	for(int i=1;i<=58;++i)
	{
		if(!sm[i]) continue;
		for(int j=n;j>=sm[i];--j)
			dp[j]+=dp[j-sm[i]];
	}
	int inv=1;
	for(int i=1;i<=58;++i)
		if(sm[i]) inv=inv*q_pow(jc[sm[i]],mod-2)%mod;
	Ans=dp[n>>1]%mod*jc[n>>1]%mod*jc[n>>1]%mod*inv%mod;
	for(int i=1;i<=58;++i)
		for(int j=i+1;j<=58;++j)
			if(sm[i]&&sm[j])
			{
				for(int k=0;k<=n;++k)
					dp2[k]=dp[k];
				for(int k=sm[i];k<=n;++k)
					dp2[k]-=dp2[k-sm[i]];
				for(int k=sm[j];k<=n;++k)
					dp2[k]-=dp2[k-sm[j]];
				for(int k=n;k>=sm[i]+sm[j];--k)
					dp2[k]+=dp2[k-sm[i]-sm[j]];
				ans[i][j]=dp2[n>>1]%mod*jc[n>>1]%mod*jc[n>>1]%mod*inv%mod;
			}
	q=read();
	while(q--)
	{
		int x=read(),y=read();
		if(s[x]>s[y]) swap(x,y);
		if(s[x]==s[y]) printf("%lld\n",Ans);
		else printf("%lld\n",ans[s[x]-'A'+1][s[y]-'A'+1]);
	}
	return 0;
}