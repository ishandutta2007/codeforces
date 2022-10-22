#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

ll arr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll ans = 0;
		for (int b = 0; b < m; b++){
			ll bit = 1LL << b;
			int zc = 0, oc = 0;
			for (int i = 1; i <= n; i++){
				if (arr[i] & bit){ oc += 1; }
				else{ zc += 1; }
			}
			if (oc > zc){ ans ^= bit; }
		}
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}