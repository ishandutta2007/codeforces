#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int,ll> mp;
void Solve(){
	cin>>n;
	mp.clear();
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		ans+=1LL*(n-i+1)*mp[x];
		mp[x]+=i;
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