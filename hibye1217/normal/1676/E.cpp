#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
const ld eps = 1e-15;

vector<ld> arr, prf;

void Main(){
	ld t; cin >> t;
	for (ld tt = 1.0; tt <= t; tt += 1.0){
		ld n, q; cin >> n >> q;
		ld sum = 0.0;
		for (ld i = 1.0; i <= n; i += 1.0){
			ld x; cin >> x; arr.push_back(x);
			sum += x;
		}
		sort(all(arr), [](ld a, ld b){ return a > b; });
		prf.push_back(0.0);
		for (ld x : arr){
			prf.push_back(prf.back() + x);
		}
		for (ld qq = 1.0; qq <= q; qq += 1.0){
			ld x; cin >> x;
			//cout << "ANSWER " << ' ';
			if (x > sum){ cout << "-1" << endl; }
			else{
				vector<ld>::iterator it = lower_bound(all(prf), x);
				cout << it - prf.begin() << endl;
			}
		}
		arr.clear(); prf.clear();
	}
}

int main(){
	Main();
}