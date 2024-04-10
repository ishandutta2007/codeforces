#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll x; cin >> n >> x;
		ll mn = 200'000, mx = 1;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			mn = min(mn, arr[i]); mx = max(mx, arr[i]);
		}
		ll ans = 0;
		for (int i = 1; i < n; i++){ ans += abs(arr[i]-arr[i+1]); }
		x = max(x, mx);
		ll r1 = min({ 2*(mn-1), arr[1]-1, arr[n]-1 });
		ll r2 = min({ 2*(x-mx), x-arr[1], x-arr[n] });
		cout << ans+r1+r2 << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}