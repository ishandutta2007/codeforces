#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int t;
int n,m;
ll pb[1000001];
ll cnt[1000001];
vector<int>mina;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		int k;cin >> k;
		for(int j=1; j<=k ;j++){
			int a;cin >> a;
			mina.push_back(a);
			pb[a]=(pb[a]+pw(k,mod-2)*pw(n,mod-2))%mod;
			cnt[a]++;
		}
	}
	ll ans=0;
	for(auto cur:mina){
		ans+=pb[cur]*cnt[cur]%mod*pw(n,mod-2);
		ans%=mod;
		pb[cur]=cnt[cur]=0;
	}
	mina.clear();
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	t=1;
	while(t--){
		solve();
	}
}