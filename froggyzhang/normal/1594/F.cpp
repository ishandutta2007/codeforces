#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll s,n,k;
void Solve(){
	cin>>s>>n>>k;
	if(s==k){
		cout<<"YES\n";
		return;
	}
	ll x=s%k+1;
	ll y=k-x;
	ll tx=s/k+1;
	ll ty=s/k;
	cout<<((tx+1)/2*x+(ty+1)/2*y>=n+1?"NO\n":"YES\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		Solve();	
	}
	return 0;
}