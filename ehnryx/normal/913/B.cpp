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

vector<int> graph[1001];

bool shit = false;
bool dfs(int cur) {
	if (graph[cur].empty()) return true;
	int c = 0;
	for (int n : graph[cur]) {
		c += dfs(n);
	}
	if (c < 3) shit = true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int t;
	for (int i = 2; i <= n; i++) {
		cin >> t;
		graph[t].push_back(i);
	}

	dfs(1);
	if (shit) cout << "No" << nl;
	else cout << "Yes" << nl;

	return 0;
}