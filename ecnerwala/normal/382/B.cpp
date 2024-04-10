#include<iostream>

using namespace std;

typedef long long ll;
const int MAXW = 2e3;
ll A, B, X, W, C;
bool vis[MAXW];
ll steps[MAXW];
ll decr[MAXW];
int main() {
	cin >> A >> B >> W >> X >> C;
	if(C <= A) {
		cout << 0 << '\n';
		return 0;
	}
	C -= A;
	ll s = 0;
	ll d = 0;
	while(C > 0) {
		//cerr << B << ' ' << s << ' ' << d << ' ' << C << '\n';
		if(vis[B]) {
			ll ls = s - steps[B];
			ll ld = d - decr[B];
			ll lc = ls - ld;
			ll numC = (C - 1) / lc;
			//cerr << ls << ' ' << ld << ' ' << lc << ' ' << numC << '\n';
			C -= numC * lc;
			s += numC * ls;
			d += numC * ld;
		}
		vis[B] = true;
		steps[B] = s;
		decr[B] = d;
		if(B < X) {
			d++;
			B += W - X;
		} else {
			C--;
			B -= X;
		}
		s++;
	}
	cout << s << '\n';
	return 0;
}