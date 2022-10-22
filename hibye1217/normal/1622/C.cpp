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

ll arr[200020];
ll prf[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll k; cin >> n >> k;
		ll sum = 0;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; sum += arr[i]; }
		if (sum <= k){ cout << 0 << endl; continue; }
		sort(arr+1, arr+n+1);
		ll ans = 1e18, num = 0;
		int cnt = 0, dlt = 0;
		for (int i = n; i >= 1; i--){ cnt += 1;
			int idx = i+1; if (idx > n){ idx = 1; }
			if (arr[idx] == arr[1]){ dlt += 1; }
			num += arr[idx];
			ll val = sum-num; ll tar = (k-val) / cnt + 2;
			while (tar*cnt > k-val){ tar -= 1; }
			tar = min(tar, arr[1]);
			ll res = abs(tar - arr[1]) + cnt;
			if (tar == arr[1]){ res -= dlt; }
			else{ res -= 1; }
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