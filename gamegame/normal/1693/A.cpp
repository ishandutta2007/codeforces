#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	ll s=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		s+=a[i];
	}
	if(s!=0){
		cout << "No\n";
		return;
	}
	int m=n;
	while(m>0 && a[m]==0) m--;
	for(int i=1; i<m ;i++){
		s+=a[i];
		if(s<=0){
			cout << "No\n"; return;
		}
	}
	cout << "Yes\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}