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
ll dlt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll st = 0, ed = 2e9, ans = 0;
		while (st <= ed){
			ll mid = (st + ed) >> 1;
			for (int i = 1; i <= n; i++){ dlt[i] = 0; }
			bool flg = 1;
			//cout << st << ' ' << ed << ' ' << mid << endl;
			for (int i = n; i >= 1; i--){
				ll val = arr[i] + dlt[i];
				if (val < mid){ flg = 0; }
				if (i < 3){ continue; }
				ll lft = min(arr[i], val-mid);
				ll num = lft / 3;
				dlt[i-2] += num*2; dlt[i-1] += num;
			}
			if (flg){ ans = mid; st = mid+1; }
			else{ ed = mid-1; }
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