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
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

ll arr[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll x, y; cin >> n >> x >> y;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		bool odd = x%2 != 0;
		for (int i = 1; i <= n; i++){
			if (arr[i]%2 != 0){ odd ^= 1; }
		}
		bool yod = y%2 != 0;
		if (odd == yod){ cout << "Alice" << endl; }
		else{ cout << "Bob" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}