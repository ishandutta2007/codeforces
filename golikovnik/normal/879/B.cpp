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
	int n; ll k;
	cin >> n >> k;
	vector<int> pow(n);
	for (int i = 0; i < n; ++i) cin >> pow[i];
	int streak = 0;
	while(true) {
		if (streak >= k || streak == n-1) {
			cout << pow[0];
			break;
		}
		int first = pow[0], second = pow[1];
		if (first > second) {
			pow.erase(pow.begin() + 1);
			pow.push_back(second);
			++streak;
		} else {
			pow.erase(pow.begin());
			pow.push_back(first);
			streak = 1;
		}
	}
	return 0;
}