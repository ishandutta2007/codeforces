#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const int N=2e5+1,mod=998244353;
int n,m,k,ans;
int a[N],fac[N],inv[N],pw[N];
V input(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n)scanf("%d",a+i);
}
I Pow(ll t,rnt x){
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)
		s=s*t%mod;
	return s;
}
V init(){
	FOR(i,1,n)if(a[i]!=a[i%n+1])m++;
	fac[0]=inv[0]=pw[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,1,n)pw[i]=1ll*pw[i-1]*(k-2)%mod;
	inv[n]=Pow(fac[n],mod-2);
	ROF(i,n-1,1)inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
V work(){
	FOR(i,0,m/2)
		check(ans+=1ll*inv[m-2*i]*inv[i]%mod*inv[i]%mod*pw[m-2*i]%mod);
	ans=499122177ll*(mod+Pow(k,m)-1ll*fac[m]*ans%mod)%mod;
	cout<<1ll*ans*Pow(k,n-m)%mod;
}
int main(){
	input();
	init();
	work();
	return 0;
}