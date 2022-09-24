#include<bits/stdc++.h>
using namespace std;
int n,k,mod;
long long ans=0;
map<int,int> mp;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n>>mod>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		int w=(Power(x,4)-1ll*k*x%mod+mod)%mod;
		ans+=mp[w],mp[w]++;
	}
	cout<<ans;
}