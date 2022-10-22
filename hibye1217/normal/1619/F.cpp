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
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )

// #define DEBUG



void Main(){
	int t; cin >> t;
	while (t--){
		ll n, m, k; cin >> n >> m >> k;
		ll hi = (n+m-1) / m, lo = n / m;
		ll hc = n % m; ll lc = m - hc;
		int ptr = 1;
		while (k--){
			for (int i = 1; i <= hc; i++){
				cout << hi << ' ';
				for (int j = 1; j <= hi; j++){
					cout << ptr << ' ';
					ptr += 1; if (ptr > n){ ptr -= n; }
				}
				cout << endl;
			}
			int ed = ptr;
			for (int i = 1; i <= lc; i++){
				cout << lo << ' ';
				for (int j = 1; j <= lo; j++){
					cout << ptr << ' ';
					ptr += 1; if (ptr > n){ ptr -= n; }
				}
				cout << endl;
			}
			ptr = ed;
		}
		cout << endl;
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