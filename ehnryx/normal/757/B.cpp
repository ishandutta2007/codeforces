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




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	int arr[100001];
	memset(arr, 0, sizeof arr);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 1; j <= sqrt(a); j++) {
			if (a % j == 0) {
				arr[j]++;
				if (j != a/j)
					arr[a/j]++;
			}
		}
	}

	int ans = 1;
	for (int i = 2; i <= 100000; i++) {
		ans = max(ans, arr[i]);
	}

	cout << ans << nl;

	return 0;
}