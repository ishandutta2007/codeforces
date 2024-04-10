#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

template<class T>
ostream& operator << (ostream& os, const pair<T,T>& v) {
	return os << '(' << v.first << ',' << v.second << ')';
}

struct Field {
	vector<pii> points;

	void insert(int a, int b) {
		points.push_back(pii(a+b, b-a));
	}

	ll solve() {
		sort(points.begin(), points.end());
		int n = points.size();

		vector<int> upper(n+1);
		vector<int> lower(n+1);
		upper[n] = -INF;
		lower[n] = INF;
		for (int i = n-1; i >= 0; i--) {
			upper[i] = max(points[i].second, upper[i+1]);
			lower[i] = min(points[i].second, lower[i+1]);
		}

		int ub = -INF;
		int lb = INF;
		int prevx = -INF;

		ll res = 0;
		for (int i = 0; i < n; i++) {
			if (min(ub, upper[i]) > max(lb, lower[i])) {
				res += (ll) ((min(ub, upper[i]) - max(lb, lower[i]))/2) * ((points[i].first - prevx)/2);
			}
			ub = max(ub, points[i].second);
			lb = min(lb, points[i].second);
			prevx = points[i].first;
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	Field points[2];

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		points[((a+b)%2+2)%2].insert(a,b);
	}
	cout << points[0].solve() + points[1].solve() << nl;

	return 0;
}