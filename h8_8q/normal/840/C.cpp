#include<bits/stdc++.h>

#define int long long

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

const int N=3e3+5,mod=1e9+7;
int n,m,a[N],dp[N][N],s1[N],s2[N],sum[N],jc[N],inv[N],ans;

inline void init();
inline int q_pow(int a,int b);
inline int C(int n,int m);

signed main()
{
	//freopen("permutation.in","r",stdin);
	//freopen("permutation.out","w",stdout);
	n=read();init();
	for(int i=1;i<=n;++i)
	{
		int tmp=read();a[i]=1;
		for(int j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				int fl=0;
				while(tmp%j==0)
					fl^=1,tmp/=j;
				if(fl) a[i]*=j;
			}
		a[i]*=tmp;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		if(a[i]!=a[i-1])
		{
			s1[++m]=a[i];
			s2[m]=1;
		}
		else s2[m]++;
	for(int i=1;i<=m;++i)
		sum[i]=(sum[i-1]+s2[i])%mod;
	dp[1][s2[1]-1]=1;
	for(int i=1;i<m;++i)
		for(int j=0;j<=n;++j)
		{
			if(!dp[i][j]) continue;
			for(int k=1;k<=sum[i]+1&&k<=s2[i+1];++k)
				for(int p=0;p<=j&&p<=k;++p)
				{
					dp[i+1][j-p+s2[i+1]-k]+=dp[i][j]*C(j,p)%mod*C(sum[i]+1-j,k-p)%mod*C(s2[i+1]-1,k-1)%mod;
					dp[i+1][j-p+s2[i+1]-k]%=mod;
				}
		}
	int ans=dp[m][0];
	for(int i=1;i<=m;++i)
		ans=ans*jc[s2[i]]%mod;
	printf("%lld\n",ans);
	return 0;
}

inline void init()
{
	jc[0]=1;
	for(int i=1;i<=3000;++i)
		jc[i]=jc[i-1]*i%mod;
	inv[3000]=q_pow(jc[3000],mod-2);
	for(int i=2999;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
}

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

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod;
}