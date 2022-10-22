#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

// #define DEBUG

ll arr[200020];
ll ans[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll sum = 0, m = (ll)n*(n+1) / 2;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; sum += arr[i]; }
		if (sum % m != 0){ cout << "NO"; goto nxt; }
		sum /= m;
		for (int i = 1; i <= n; i++){
			int i1 = i, i2 = i-1; if (i2 <= 0){ i2 += n; }
			ll d = arr[i1] - arr[i2];
			d -= sum; d *= -1;
			//cout << "I " << i << ' ' << d << endl;
			if (d <= 0){ cout << "NO"; goto nxt; }
			if (d % n != 0){ cout << "NO"; goto nxt; }
			ans[i] = d/n;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
		nxt: cout << endl;
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