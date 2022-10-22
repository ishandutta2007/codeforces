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

ll arr[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		if (n == 3){
			if (arr[2] % 2 == 0){ cout << arr[2]/2 << endl; }
			else{ cout << -1 << endl; }
			continue;
		}
		bool flg = 0;
		for (int i = 2; i < n; i++){
			if (arr[i] >= 2){ flg = 1; }
		}
		if (!flg){ cout << -1 << endl; continue; }
		ll ans = 0;
		for (int i = 2; i < n; i++){
			ans += arr[i]/2;
			arr[i] -= arr[i]/2*2;
		}
		int lft = 0;
		for (int i = 2; i < n; i++){ lft += arr[i]; }
		if (lft == 0){ cout << ans << endl; }
		else{ cout << ans+lft << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}