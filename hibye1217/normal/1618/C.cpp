#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

// #define DEBUG

ll arr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll g1 = arr[1], g2 = arr[2];
		for (int i = 3; i <= n; i++){
			if (i & 1){ g1 = gcd(g1, arr[i]); }
			else{ g2 = gcd(g2, arr[i]); }
		}
		bool f1 = 1, f2 = 1;
		for (int i = 1; i <= n; i++){
			if (i & 1){ if (arr[i] % g2 == 0){ f2 = 0; } }
			else{ if (arr[i] % g1 == 0){ f1 = 0; } }
		}
		if (f1){ cout << g1; }
		else if (f2){ cout << g2; }
		else{ cout << 0; }
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