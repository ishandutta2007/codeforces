#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

ll arr[5020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	ll ans = 1e18;
	for (int i = 1; i <= n; i++){
		ll res = 0; ll val = 0;
		for (int j = i-1; j >= 1; j--){
			ll cnt = val/arr[j] + 1;
			res += cnt; val = cnt*arr[j];
		}
		val = 0;
		for (int j = i+1; j <= n; j++){
			ll cnt = val/arr[j] + 1;
			res += cnt; val = cnt*arr[j];
		}
		ans = min(ans, res);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}