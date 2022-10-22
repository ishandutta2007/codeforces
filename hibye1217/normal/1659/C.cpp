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

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll a, b; cin >> n >> a >> b;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll ans = 0; int ptr = 0;
		for (int i = 1; i <= n; i++){
			ll len = arr[i] - arr[ptr];
			ans += b*len;
			ll ra = a * len, rb = b*len*(n-i);
			//cout << ra << ' ' << rb << endl;
			if (ra < rb){ ptr = i; ans += ra; }
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}