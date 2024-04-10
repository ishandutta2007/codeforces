#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
const LL mo=1000000007;
int n,k;
char s[N];
LL f[N],inv[N];
LL C(int n,int m) { return 1LL*f[n]*inv[m]%mo*inv[n-m]%mo;}
LL exp(LL a,LL b,LL c)
{
		if (b==1) return a%c;
		LL d=exp(a,b/2,c);
		d=d*d%c;
		if (b&1) d=d*a%c;
		return d;
}
int main()
{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		LL now=0;
		for (int i=1;i<=n-1;i++) now+=s[i]-'0';
		f[1]=1;inv[1]=1;
		f[0]=1;inv[0]=1;
		for (int i=2;i<=n;i++) f[i]=1LL*f[i-1]*i%mo;
		for (int i=2;i<=n;i++) inv[i]=exp(f[i],mo-2,mo);
		LL p=1;
		LL ans=0;
		for (int l=1;l<=n-k;l++)
		{

			ans=(ans+1LL*now*p%mo*C(n-l-1,k-1))%mo;
			p=1LL*p*10%mo;
			now-=s[n-l]-'0';
		}
		p=1;
		for (int i=n;i>=k+1;i--) 
		{
			ans=(ans+1LL*(s[i]-'0')*p%mo*C(i-1,k))%mo;
			p=1LL*p*10%mo;
		}
		ans=(ans+mo)%mo;
		printf("%lld\n",ans);
		return 0;
}