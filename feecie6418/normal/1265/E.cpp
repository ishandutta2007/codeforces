#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,f[200005]={1};
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,f[i]=(1ll*f[i-1]*Power(x,mod-2)%mod*100%mod+1)%mod;
	cout<<f[n]-1;
	return 0;
}