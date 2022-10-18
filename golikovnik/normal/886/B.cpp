#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

const int MAXN = 2e5 + 10;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> cafe(MAXN, -1);
	for (int i = 0; i < n; ++i) {
		int ind;
		cin >> ind;
		cafe[ind] = n - i;
	}
	auto res = max_element(all(cafe));
	cout << res - cafe.begin();
	return 0;
}