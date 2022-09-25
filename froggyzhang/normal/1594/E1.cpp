#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int k;
int qpow(int a,ll b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k;
	cout<<6LL*qpow(4,(1LL<<k)-2)%mod<<'\n';
	return 0;
}