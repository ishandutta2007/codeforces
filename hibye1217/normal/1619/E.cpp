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

int arr[200020];
int cnt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= n; i++){ cnt[ arr[i] ] += 1; }
		bool flg = 0;
		cout << cnt[0] << ' ';
		ll res = 0;
		stack<ll> stk;
		for (int mex = 1; mex <= n; mex++){
			for (int c = 1; c <= cnt[mex-1]; c++){ stk.push(mex-1); }
			if (stk.empty()){ flg = 1; }
			else{ res += stk.top(); stk.pop(); }
			ll ned = (ll)(mex-1)*mex / 2;
			ll ans = ned-res;
			if (flg){ cout << -1 << ' '; }
			else{ cout << ans + cnt[mex] << ' '; }
		}
		cout << endl;
		for (int i = 0; i <= n; i++){ cnt[i] = arr[i] = 0; }
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