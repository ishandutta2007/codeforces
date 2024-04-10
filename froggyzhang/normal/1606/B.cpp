#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
void Solve(){
	cin>>n>>k;
	ll ans=0;
	ll now=1;
	while(now<k&&now<n){
		now<<=1;
		++ans;
	}
	if(now<n){
		ans+=(n-now+k-1)/k;	
	}
	cout<<ans<<'\n';
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