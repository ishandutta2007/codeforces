#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 2e5+5;
ll a[ms];
int x[ms];
ll ans[ms];

int main() {
	int n; ll t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 2; i <= n; i++) {
		if(x[i] < x[i-1]) {
			cout << "No\n";
			return 0;
		}
	}
	a[n+1] = 2e18;
	for(int i = 1; i <= n; i++) {
		if(x[i] < i) {
			cout << "No\n";
			return 0;
		} else if(x[i] == i) {
			ans[i] = a[i+1] + t - 1ll;
			if(ans[i] <= ans[i-1]) {
				cout << "No\n";
				return 0;
			}
		} else {
			if(x[x[i]] != x[i]) {
				cout << "No\n";
				return 0;
			}
			ans[i] = a[i+1] + t;
		}
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}