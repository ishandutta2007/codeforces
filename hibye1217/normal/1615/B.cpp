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
		ll l, r; cin >> l >> r;
		ll ans = r-l+1, cnt = r-l+1;
		ll lc=0, rc=0;
		for (int b = 0; b <= 20; b++){
			if (l==0 && r==0){ break; }
			int bit = 1<<b;
			ll res = 0;
			if (~l & 1){ res += (r-l+1 + 1) / 2; }
			else{ res += (r-l+1) / 2; }
			res *= bit;
			if (~l & 1){ res -= lc; }
			if (~r & 1){ res -= rc; }
			//cout << "? " << lc << ' ' << rc << ' ' << res << endl;
			if (l&1){ lc += bit; }
			if (~r&1){ rc += bit; }
			l /= 2; r /= 2;
			ans = min(ans, res);
		}
		cout << ans << endl;
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