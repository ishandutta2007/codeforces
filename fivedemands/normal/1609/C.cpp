#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,e;
bool np[N];
ll a[N];
int f1[N],f2[N];
void solve(){
	cin >> n >> e;
	for(int i=0; i<e ;i++){
		f1[i]=i-e;
		f2[i]=i-e;
	}
	ll ans=0;
	for(int i=0; i<n ;i++){
		cin >> a[i];
		if(np[a[i]]) f1[i%e]=f2[i%e]=i;
		else if(a[i]!=1){
			f2[i%e]=f1[i%e];f1[i%e]=i;
			ans--;
		}
		ans+=(f1[i%e]-f2[i%e])/e;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int iu=1e6;
	for(int i=2; i<=iu ;i++){
		if(np[i]) continue;
		for(int j=2*i; j<=iu ;j+=i){
			np[j]=true;
		}
	}
	int t;cin >> t;
	while(t--) solve();
}