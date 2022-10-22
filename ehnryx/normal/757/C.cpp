#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

ll fdp[1000001];
ll fact(int n) {
	if (n == 0) return 1;
	if (fdp[n] == 0)
		return fdp[n] = (n * fact(n-1)) % MOD;
	else
		return fdp[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i <= 1000000; i++) {
		fact(i);
	}

	map<int, multiset<int>> group;

	int a, b;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			group[b].insert(i);
		}
	}

	map<multiset<int>, int> ans;
	for (const auto& it : group) {
		ans[it.second]++;
	}

	ll res = fact(m - group.size());
	for (const auto& it : ans) {
		res = (res * fact(it.second)) % MOD;
	}

	cout << res << nl;

	return 0;
}