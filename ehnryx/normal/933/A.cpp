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

	int n;
	cin >> n;

	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int pref[2][n+2], suff[2][n+2];
	memset(pref, 0, sizeof pref);
	memset(suff, 0, sizeof suff);

	int lis[n+2];

	for (int i = n; i >= 1; i--) {
		suff[a[i]][i] = suff[a[i]][i+1] + 1;
		suff[!a[i]][i] = suff[!a[i]][i+1];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		pref[a[i]][i] = pref[a[i]][i-1] + 1;
		pref[!a[i]][i] = pref[!a[i]][i-1];
		memset(lis, INF, sizeof lis);
		for (int j = i; j <= n; j++) {
			*upper_bound(lis, lis+n, !a[j]) = !a[j];
			ans = max(ans, pref[0][i-1] + suff[1][j+1] + (int)(lower_bound(lis, lis+n, INF) - lis));
		}
	}

	cout << ans << nl;

	return 0;
}