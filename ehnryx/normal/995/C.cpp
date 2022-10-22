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

pii operator + (const pii& a, const pii& b) {
	return pii(a.first+b.first, a.second+b.second);
}
pii operator - (const pii& a, const pii& b) {
	return pii(a.first-b.first, a.second-b.second);
}
double abs(const pii& v) {
	return sqrt((ll)v.first*v.first + (ll)v.second*v.second);
}

struct Move {
	pii v;
	int id;
	operator pii() { return v; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int ans[n];
	vector<Move> move;
	int x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		move.push_back({pii(x,y), i});
	}

	for (;;) {
		shuffle(move.begin(), move.end(), rng);

		pii pos(0,0);
		for (int i=0; i<n; i++) {
			if (abs(pos + move[i]) < abs(pos - move[i])) {
				ans[move[i].id] = 1;
				pos = pos + move[i];
			} else {
				ans[move[i].id] = -1;
				pos = pos - move[i];
			}
		}

		if (abs(pos) < 1.5e6) {
			for (int i=0; i<n; i++) {
				cout << ans[i] << " ";
			}
			cout << nl;
			return 0;
		}
	}

	return 0;
}