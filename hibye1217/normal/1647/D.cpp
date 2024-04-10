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
typedef pair<pi2, pi2> pi4;



void Main(){
	int t; cin >> t;
	while (t--){
		ll n, m; cin >> n >> m;
		int cnt = 0;
		bool ans = 0;
		ll val = n; while (val){ if (val%m == 0){ cnt += 1; val /= m; } else{ break; } }
		if (cnt <= 1){ cout << "No" << endl; goto done; }
		for (ll i = 2; i*i <= val; i++){ if (val%i == 0){ ans = 1; } }
		if (cnt == 2){
			if (ans){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		else{
			bool res = 0;
			bool chk = 0; int x = 0;
			for (ll i = 2; i*i <= m; i++){
				if (m%i == 0){
					res = 1;
					if (i*i != m){ chk = 1; } else{ x = i; }
				}
			}
			if (ans || chk){ cout << "Yes" << endl; }
			else if (!res){ cout << "No" << endl; }
			else if (x*val % m != 0){ cout << "Yes" << endl; }
			else if (cnt >= 4){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		done: ;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}