#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n;
vector<int>pf;
void solve(){
	cin >> n;
	if((n&-n)==n){
		cout << "-1\n";
		return;
	}
	ll x=2;
	while(n%x==0) x*=2;
	if(x<=2000000000 && x*(x+1)/2<=n){
		cout << x << '\n';
		return;
	}
	n/=x/2;
	cout << n << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}