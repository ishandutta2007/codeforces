#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e5+5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	ll ans = 0;
	ll a0b0 = 0, a0b1 = 0, a1b0 = 0, a1b1 = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == '0' && b[i] == '0') {
			ans += a1b1 + a1b0;
			a0b0++;
		} else if(a[i] == '0' && b[i] == '1') {
			ans += a1b0;
			a0b1++;
		} else if(a[i] == '1' && b[i] == '0') {
			ans += a0b1 + a0b0;
			a1b0++;
		} else {
			ans += a0b0;
			a1b1++;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}