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
	cin >> n ;
	int l=n+1,r=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]!=0){
			l=min(l,i);
			r=max(r,i);
		}
	}
	if(r==0){
		cout << "0\n";
		return;
	}
	for(int i=l; i<=r ;i++){
		if(a[i]==0){
			cout << "2\n";
			return;
		}
	}
	cout << 1 << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}