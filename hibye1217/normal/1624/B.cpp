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



void Main(){
	int t; cin >> t;
	while (t--){
		ll a, b, c; cin >> a >> b >> c;
		bool flg = 0;
		ll tar = b - (c-b); if (tar > 0 && tar % a == 0){ flg = 1; }
		tar = (a+c) / 2; if ((a+c)%2 == 0 && tar%b == 0){ flg = 1; }
		tar = b + (b-a); if (tar > 0 && tar % c == 0){ flg = 1; }
		if (flg){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
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