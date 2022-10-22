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
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	string grid[n];
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	int ans = 0;

	if (m >= k)
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			cnt += grid[i][j] == '*';
		}
		ans += !cnt;
		for (int j = k; j < m; j++) {
			cnt += (grid[i][j] == '*') - (grid[i][j-k] == '*');
			ans += !cnt;
		}
	}

	if (n >= k && k > 1)
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			cnt += grid[j][i] == '*';
		}
		ans += !cnt;
		for (int j = k; j < n; j++) {
			cnt += (grid[j][i] == '*') - (grid[j-k][i] == '*');
			ans += !cnt;
		}
	}
	cout << ans << nl;

	return 0;
}