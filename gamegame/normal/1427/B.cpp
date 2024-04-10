#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,k;
ll a[N],b[N];
void solve(){
	cin >> n >> k;
	ll t=0;
	ll prv=-1e9;
	vector<ll>v;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		if(c=='W'){
			ans++;
			if(prv==i-1){
				ans++;prv=i;continue;
			}
			v.push_back(i-prv-1);
			prv=i;
		}
		else t++;
	}
	if(t==n){
		if(k==0){
			cout << "0\n";
			return;
		}
		else ans--;
	}
	k=min(k,t);
	v.push_back(1e9);
	sort(v.begin(),v.end());
	
	for(auto c:v){
		if(c<=k){
			ans+=2*c+1;
			k-=c;
		}
		else{
			ans+=2*k;break;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}