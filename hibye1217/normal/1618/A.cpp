#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

// #define DEBUG



void Main(){
	int t; cin >> t;
	while (t--){
		ll a, b, c, d, e, f, g; cin >> a >> b >> c >> d >> e >> f >> g;
		if (a+b == c){ cout << a << ' ' << b << ' ' << d << endl; }
		else{ cout << a << ' ' << b << ' ' << c << endl; }
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