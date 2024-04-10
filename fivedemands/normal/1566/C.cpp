#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n;
ll a[N],b[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		a[i]=c-'0';
	}
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		b[i]=c-'0';
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		if(a[i]!=b[i]) ans+=2;
		else if(a[i]==1){
			if(i==n) break;
			else if(a[i+1]==0 || b[i+1]==0){
				ans+=2;i++;
			}
			else;
		}
		else{
			if(i==n){
				ans++;break;
			}
			else if(a[i+1]==1 && b[i+1]==1){
				ans+=2;i++;
			}
			else{
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}