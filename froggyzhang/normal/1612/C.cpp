#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
ll check(ll p){
	if(p<=n)return p*(p+1)/2;
	return n*(n-1)/2+(p-n+1)*(n+2*n-p)/2;
}
void Solve(){
	cin>>n>>x;
	ll l=1,r=2*n-1,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)<x){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans+1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}