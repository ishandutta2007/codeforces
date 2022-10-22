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



void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		if (n%3 == 1){ while (n>3){ cout << "12"; n -= 3; } cout << "1"; }
		if (n%3 == 2){ while (n>3){ cout << "21"; n -= 3; } cout << "2"; }
		if (n%3 == 0){ while (n>3){ cout << "21"; n -= 3; } cout << "21"; }
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}