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
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int s, d;
		cin >> s >> d;
		while (s <= cnt) s += d;
		cnt = s;
	}	
	cout << cnt;
	return 0;
}