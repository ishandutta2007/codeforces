#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
void solve(){
	cin >> n >> m >> k;
	for(int i=1; i<=k ;i++){
		cin >> a[i];
	}
	{
		bool ok=true;
		ll sex=0;
		ll smart=0;
		for(int i=1; i<=k ;i++){
			if(a[i]>=2*n){
				sex+=a[i]/n;
				if(a[i]>=3*n) smart=true;
			}
			else;
		}
		if(sex%2!=m%2 && !smart);
		else if(sex>=m){
			cout << "Yes\n";
			return;
		}
	}
	swap(n,m);
	{
		bool ok=true;
		ll sex=0;
		ll smart=0;
		for(int i=1; i<=k ;i++){
			if(a[i]>=2*n){
				sex+=a[i]/n;
				if(a[i]>=3*n) smart=true;
			}
			else;
		}
		if(sex%2!=m%2 && !smart);
		else if(sex>=m){
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}