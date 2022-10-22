#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(chrono::high_resolution_clock::now().time_since_epoch().count()); }

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
	srand();

	int n, a, b;
	cin >> n >> a >> b;

	int good = -1;
	for (int i = 0; i*a <= n; i++) {
		if ((n-i*a) % b == 0) {
			good = i;
			break;
		}
	}
	if (good == -1) {
		cout << -1 << nl;
		return 0;
	}

	int acnt = good;
	int bcnt = (n-a*acnt)/b;
	int root = -1;
	int ans[n+2];
	for (int i = 1; i <= n+1; i++) {
		if ((i-1) % a == 0) {
			ans[i-1] = root;
			root = i;
			if (acnt == 0)
				break;
			acnt--;
		}
		if (i == n+1) break;
		ans[i] = i+1;
	}
	for (int i = 0; i <= n; i++) {
		if (i % b == 0) {
			ans[n-i+1] = root;
			root = n-i;
			if (bcnt == 0) 
				break;
			bcnt--;
		}
		if (i == n) break;
		ans[n-i] = n-i-1;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}