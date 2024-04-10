#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
pair<ll,int>a[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;a[i].se=i;
	}
	sort(a+1,a+n+1);
	cout << a[1].se << ' ' << a[n].se << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}