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

inline int ask(int i1, int i2, int i3){
	cout << "? " << i1 << ' ' << i2 << ' ' << i3 << endl << flush;
	int res; cin >> res;
	if (res == -1){ exit(0); }
	return res;
}
inline void ans(int i1, int i2){
	cout << "! " << i1 << ' ' << i2 << endl << flush;
}

pi2 f(int a, int b, int c, int d){
	int dd = ask(a, b, c);
	int cc = ask(a, b, d);
	int bb = ask(a, c, d);
	int aa = ask(b, c, d);
	int mx = max({ aa, bb, cc, dd });
	if (aa == mx && bb == mx){ return {c, d}; }
	if (aa == mx && cc == mx){ return {b, d}; }
	if (aa == mx && dd == mx){ return {b, c}; }
	if (bb == mx && cc == mx){ return {a, d}; }
	if (bb == mx && dd == mx){ return {a, c}; }
	if (cc == mx && dd == mx){ return {a, b}; }
}

int res[1020];
void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a = 1, b = 2;
		for (int i = 4; i <= n; i += 2){
			pi2 p = f(a, b, i-1, i);
			a = p.fr; b = p.sc;
		}
		if (n % 2 != 0){
			int c = 1, d = n;
			while (c == a || c == b || c == d){ c += 1; }
			pi2 p = f(a, b, c, d);
			a = p.fr; b = p.sc;
		}
		ans(a, b);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}