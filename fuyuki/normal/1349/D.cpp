#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=3e5+1,mod=998244353;
int n,s,ans,a[N],f[N];
void check(int&x){x-=mod,x+=x>>31&mod;}
int Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int main(){
	scanf("%d",&n),f[0]=n-1;
	FOR(i,1,n)scanf("%d",a+i),s+=a[i];
	int tmp=1ll*(n-1)*s%mod;
	FOR(i,1,s-1)f[i]=Pow(s-i,mod-2,(1ll*i*(n-1)%mod*f[i-1]+tmp)%mod);
	ROF(i,s-1,0)check(f[i]+=f[i+1]);
	ans=1ll*(mod+1-n)*f[0]%mod;
	FOR(i,1,n)check(ans+=f[a[i]]);
	return cout<<Pow(n,mod-2,ans),0;
}