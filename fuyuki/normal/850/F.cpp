#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e5+1,mod=1e9+7;
int n,m,s,ans,a[N],g[N],f[N];
void check(int&x){x-=mod,x+=x>>31&mod;}
int Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",a+i),m=max(a[i],m),s+=a[i];
	FOR(i,0,m)check(g[i+1]=g[i]+Pow(s-i,mod-2));
	FOR(i,1,m)f[i]=1ll*g[i]*(s-i)%mod;
	FOR(i,1,n)check(ans+=f[a[i]]);
	return cout<<1ll*(s-1)*ans%mod,0;
}