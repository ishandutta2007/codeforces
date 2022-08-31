#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	ll x=n/2020;
	if(n-x*2020<=x) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}