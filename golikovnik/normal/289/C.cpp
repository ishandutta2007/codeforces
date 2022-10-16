#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k > n || (k == 1 && n > 1)) {
		cout << -1;
		return 0;
	}	
	char ans[n];
	int it = 0;
	int cur = 0;
	for(; it < min(n, n - k + 2); ++it) {
		ans[it] = 'a' + cur;
		cur = 1 - cur;
	}
	cur = 2;
	for(; it < n; ++it) {
		ans[it] = 'a' + cur;
		++cur;
	}
	cout << string(ans, 0, n);
	return 0;
}