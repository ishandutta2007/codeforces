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

const int N = 12+1;
unordered_set<int> dega[N], degb[N];

int overlap(const pii& a, const pii& b) {
	if (a.first == b.first || a.first == b.second) return a.first;
	if (a.second == b.first || a.second == b.second) return a.second;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	vector<pii> a, b;
	int x, y;

	for (int i=0; i<n; i++) {
		cin >> x >> y;
		a.push_back(pii(min(x,y),max(x,y)));
	}
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		b.push_back(pii(min(x,y),max(x,y)));
	}

	unordered_set<int> read_the_problem;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i] != b[j] && overlap(a[i], b[j])) {
				dega[i].insert(overlap(a[i], b[j]));
				degb[j].insert(overlap(a[i], b[j]));
				read_the_problem.insert(overlap(a[i], b[j]));
			}
		}
	}

	if (read_the_problem.size() == 1) {
		cout << *read_the_problem.begin() << nl;
		return 0;
	}

	bool good = true;
	for (int i=0; i<n; i++) {
		if (dega[i].size() > 1) good = false;
	}
	for (int j=0; j<m; j++) {
		if (degb[j].size() > 1) good = false;
	}

	if (good) cout << 0 << nl;
	else cout << -1 << nl;

	return 0;
}