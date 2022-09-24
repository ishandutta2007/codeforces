#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
int n,m;
int main(){
	cin>>n>>m;
	cout<<1ll*(n+1-m)%mod*Power(n+1,mod-2)%mod*Power(2*(n+1),m)%mod;
	return 0;
}