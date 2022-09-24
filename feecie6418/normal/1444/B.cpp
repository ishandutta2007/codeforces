
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[300005],jc[300005],ny[300005],ans=0;
int Power(int x,int y) {
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int C(int x,int y){
	if(x<y)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	sort(a+1,a+2*n+1);
	jc[0]=ny[0]=1;
	for(int i=1;i<=300000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[300000]=Power(jc[300000],mod-2);
	for(int i=299999;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		ans=(ans+(0ll+a[2*n+1-i]-a[i])%mod)%mod;
	}
	cout<<1ll*ans*C(2*n,n)%mod;
}