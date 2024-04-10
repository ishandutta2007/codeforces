#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
typedef long long ll;
int n;
void Solve(){
	cin>>n;
	int ans=1;
	for(int i=1;i<=2*n;++i){
		ans=1LL*ans*i%mod;
	}
	cout<<1LL*ans*inv2%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}