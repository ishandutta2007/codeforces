#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n;
ll a[N];
map<ll,int> mp;
void Solve(){
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	if(2*sum%n){
		cout<<0<<'\n';
		return;
	}
	mp.clear();
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=mp[2*sum/n-a[i]];	
		++mp[a[i]];	
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