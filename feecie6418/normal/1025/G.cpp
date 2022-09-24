#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int s[505],ans,n;
int main(){
	scanf("%d",&n),ans=Power(2,n-1)-1;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(~x)s[x]++;
	}
	for(int i=1;i<=n;i++)ans=(ans-Power(2,s[i])+1+mod)%mod;
	cout<<ans;
	return 0;
}