#include <iostream>
#include <vector>
#include <map>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map <ll, ll> ma;
	ll cnt = 1;
	for (ll i = 0; i < 61; i++) {
		ma[cnt] = i;
		cnt *= 2;
	}
	ll t;
	cin >> t;
	while (t--) {
		ll m, n;
		cin >> m >> n;
		vector <ll> a(n);
		ll x = 0;
		vector <ll> b(63);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			b[ma[a[i]]]++;
		}
		bool tf = false;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			sum += a[i];
			if (sum >= m) tf = true;
		}
		if (!tf) {
			cout << -1 << endl;
			continue;
		}
		ll ans = 0;
		ll i = 0;
		while (i < 61) {
			if ((1LL << i) & m) {
				if (b[i] > 0) 
					b[i]--;
				else {
					while (i < 60 && b[i] == 0) {
						i++;
						ans++;
					}
					b[i]--;
					continue;
				}
			}
			b[i + 1] += b[i] / 2;
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}

/*
10
83 2
64 1
119 7
8 4 8 16 8 32 1
69 8
1 32 2 32 4 2 32 64
42 7
16 1 2 1 2 1 4
3 9
32 4 16 1 2 8 2 2 16
40 9
1 8 1 32 1 1 2 64 32
45 2
16 16
1 2
1 1
187 4
2 64 4 32
74 7
64 16 16 32 64 4 1
*/