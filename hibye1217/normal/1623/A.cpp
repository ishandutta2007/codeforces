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
		int n, m, y, x, r, c; cin >> n >> m >> y >> x >> r >> c;
		int dr = 1, dc = 1;
		for (int ans = 0; ; ans++){
			if (y == r || x == c){ cout << ans << endl; break; }
			y += dr; x += dc;
			if (1 > y || y > n){ y -= dr; dr *= -1; y += dr; }
			if (1 > x || x > m){ x -= dc; dc *= -1; x += dc; }
		}
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