#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,k,ans;
void Solve(){
	cin>>n>>k;
	ans=0;
	for(int i=0,pw=1;i<=30;++i,pw=1LL*pw*n%mod){
		if(k>>i&1){
			ans=(ans+pw)%mod;
		}	
	}
	cout<<ans<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}