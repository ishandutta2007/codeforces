#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r;
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l>>r;
	for(ll i=l;i<=r;++i){
		ans+=n>>(__lg(n)-__builtin_ctzll(i))&1;
	}
	cout<<ans<<'\n';
	return 0;
}