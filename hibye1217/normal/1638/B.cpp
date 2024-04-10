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
		ll ev = 0, od = 1;
		bool flg = 1;
		for (int i = 1; i <= n; i++){
			if (arr[i] % 2 == 1){
				if (od > arr[i]){ flg = 0; }
				else{ od = arr[i]; }
			}
			else{
				if (ev > arr[i]){ flg = 0; }
				else{ ev = arr[i]; }
			}
		}
		if (flg){ cout << "Yes" << endl; }
		else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}