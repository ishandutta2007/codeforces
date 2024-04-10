#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, x;
	cin >> n >> x;
	ll cur = x, sad = 0;
	for (int i = 0; i < n; ++i) {
		char type; int val;
		cin >> type >> val;
		if (type == '+') {
			cur += val;
		} else {
			if (cur >= val) cur -= val;
			else ++sad;
		}
	}
	cout << cur << " " << sad;
	return 0;
}