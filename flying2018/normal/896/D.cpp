#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
int phi,mod;
int ksm(int a,int b=phi-1)
{
	int r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
	}
	return r;
}
int pr[N],cnt;
ll sm[N][30],fac[N],inv[N];
void pre_work(int n)
{
	int u=mod;
	phi=mod;
	for(int i=2;i*i<=u;i++)
	if(!(u%i)){phi=phi/i*(i-1),pr[++cnt]=i;while(u%i==0) u/=i;}
	if(u>1) phi=phi/u*(u-1),pr[++cnt]=u;
    fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		memcpy(sm[i],sm[i-1],sizeof(sm[i]));
        int p=i;
        for(int j=1;j<=cnt;j++)
        	for(;p%pr[j]==0;p/=pr[j]) sm[i][j]++;
		fac[i]=1ll*fac[i-1]*p%mod,inv[i]=(fac[i]?ksm(fac[i]):0);
    }
}
ll C(int n,int m)
{
	if(m<0 || n<m) return 0;
	if(m==0) return 1;
	ll res=1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
	for(int i=1;i<=cnt;i++)
		res=1ll*res*ksm(pr[i],sm[n][i]-sm[m][i]-sm[n-m][i])%mod;
	return res;
}

int main()
{
	int n,l,r;
	scanf("%d%d%d%d",&n,&mod,&l,&r);
	pre_work(N-10);
	r=min(n,r);
	int ans=0;
	for(int i=0;i<=n-l;i++)
	{
		ll res=(C(n-i,(n-i-l)>>1)-C(n-i,(n-i-r-1)>>1)+mod)%mod;
		ans=(ans+1ll*res*C(n,i))%mod; 
	}
	printf("%d\n",ans);
	return 0;
}