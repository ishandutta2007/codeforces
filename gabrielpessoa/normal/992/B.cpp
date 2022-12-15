#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e5+5;

vector<int> divs;

int main() {
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	if(y % x) {
		cout << 0 << endl;
		return 0;
	}
	y /= x;
	for(int i = 2; i * i <= y; i++) {
		int qnt = 1;
		while(y % i == 0) {
			y /= i;
			qnt *= i;
		}
		if(qnt != 1) {
			divs.push_back(qnt);
		}
	}
	if(y > 1) {
		divs.push_back(y);
	}
	int n = divs.size();
	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		ll a = 1, b = 1;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) a *= divs[j];
			else b *= divs[j];
		}
		if(a * x >= l && a * x <= r && b * x >= l && b * x <= r) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}