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
		int n; cin >> n;
		ll l = 2e9, r = -2e9, lv = 1e15, rv = 1e15;
		ll lrv = 1e15;
		for (int i = 1; i <= n; i++){
			ll st, ed, cst; cin >> st >> ed >> cst;
			if (l > st || l==st && cst < lv){
				if (l != st){ lrv = 1e15; }
				l = st; lv = cst;
			}
			if (r < ed || r==ed && cst < rv){
				if (r != ed){ lrv = 1e15; }
				r = ed; rv = cst;
			}
			if (l==st && r==ed){ lrv = min(lrv, cst); }
			cout << min(lrv, lv+rv) << endl;
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