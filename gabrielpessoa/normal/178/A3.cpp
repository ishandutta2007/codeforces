#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5;

ll a[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	ll n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int t = 1;
		while(i + (t << 1) < n) {
			t <<= 1;
		}
		//cout << i << ' ' << t << ' ' << i + t << '\n';
		ans += a[i];
		a[i+t] += a[i];
		a[i] = 0;
		cout << ans << '\n';
	}
	return 0;
}