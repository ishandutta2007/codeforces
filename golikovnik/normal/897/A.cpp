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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int q = 0; q < m; ++q) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		l--; r--;
		replace(s.begin() + l, s.begin() + r + 1, c1, c2);
	}	
	cout << s;
	return 0;
}