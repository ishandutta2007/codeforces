#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	int ma = 0;
	int cur = 0;
	set<int> have;
	for (int i = 0; i < 2 * n; ++i) {
		int x = read();
		if (have.find(x) == have.end()) {
			++cur;
			have.insert(x);
		} else {
			ma = max(ma, cur);
			--cur;
		}
	}
	cout << ma << endl;
	return 0;
}