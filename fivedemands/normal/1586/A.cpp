#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	int s=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];s+=a[i];
	}
	bool ok=false;
	for(int i=2; i*i<=s ;i++){
		if(s%i==0){
			ok=true;
			break;
		}
	}
	if(ok){
		cout << n << '\n';
		for(int i=1; i<=n ;i++) cout << i << ' ';
		cout << '\n';
	}
	else{
		cout << n-1 << '\n';
		bool fnd=false;
		for(int i=1; i<=n ;i++){
			if(!fnd && a[i]%2==1){
				fnd=true;
			}
			else cout << i << ' ';
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}