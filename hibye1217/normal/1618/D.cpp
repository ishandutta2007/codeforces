#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

// #define DEBUG

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1, [](ll a, ll b){ return a > b; });
		ll ans = 0;
		for (int i = k+1; i <= 2*k; i++){
			if (arr[i-k] == arr[i]){ ans += 1; }
		}
		for (int i = 2*k+1; i <= n; i++){ ans += arr[i]; }
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