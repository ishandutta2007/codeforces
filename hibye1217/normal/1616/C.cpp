#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

ll arr[80];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		if (n == 1){ cout << 0 << endl; continue; }
		int ans = 1e9;
		for (int i1 = 1; i1 <= n; i1++){
			for (int i2 = i1+1; i2 <= n; i2++){
				ll vd = arr[i2] - arr[i1], id = i2 - i1;
				int res = 0;
				for (int i = 1; i <= n; i++){
					ll val = (i-i1) * vd, num = (arr[i] - arr[i1]) * id;
					if (val != num){ res += 1; }
				}
				ans = min(ans, res);
			}
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