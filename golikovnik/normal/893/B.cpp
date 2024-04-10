#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector<int> a;
	for(int i = 1; ; ++i) {
		int cur = ((1 << i) - 1) * (1 << (i - 1));
		if (cur > 1e5) break;
		a.push_back(cur);
	}
	int n;
	cin >> n;
	for(auto it = a.rbegin(); it != a.rend(); ++it) {
		if (n % *it == 0) {
			cout << *it;
			break;
		}
	}
	return 0;
}