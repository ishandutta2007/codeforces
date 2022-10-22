#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace std {
	template<> struct hash<pii> {
		size_t operator () (const pii& v) const {
			return v.first ^ v.second<<11;
		}
	};
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<pii> edges;
	For (i,m) {
		int a, b;
		cin >> a >> b;
		edges.push_back(pii(a%n,b%n));
	}

	function<bool(int)> check = [&] (int d) {
		unordered_set<pii> rot;
		for (const pii& e : edges) {
			rot.insert(pii((e.first+d)%n, (e.second+d)%n));
			rot.insert(pii((e.second+d)%n, (e.first+d)%n));
		}
		for (const pii& e : edges) {
			if (!rot.count(e)) {
				return false;
			}
		}
		return true;
	};

	vector<int> div;
	FOR (i,2,n) {
		if (n%i == 0) {
			div.push_back(n/i);
		}
	}

	for (int d : div) {
		if (check(d)) {
			cout << "YES" << nl;
			return 0;
		}
	}
	cout << "NO" << nl;

	return 0;
}