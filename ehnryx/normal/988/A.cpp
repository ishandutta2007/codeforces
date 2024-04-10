#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	unordered_map<int,int> s;
	int a;
	for (int i=1; i<=n; i++) {
		cin >> a;
		s[a] = i;
	}

	if (s.size() < k) {
		cout << "NO" << nl;
	} else {
		cout << "YES" << nl;
		int cnt = 0;
		for (pii it : s) {
			if (cnt == k) break;
			cout << it.second << " ";
			cnt++;
		}
		cout << nl;
	}

	return 0;
}