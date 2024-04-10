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

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int prev = 0;
	vector<int> red, blue;

	int ans = 0;

	int a;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		if (c == 'R') {
			red.push_back(a);
		} else if (c == 'B') {
			blue.push_back(a);
		}

		else {
			if (prev == 0) {
				if (!red.empty()) {
					ans += a - red.front();
				}
				if (!blue.empty()) {
					ans += a - blue.front();
				}
			}
			else {
				int other = 0;
				if (!red.empty()) {
					int maxr = max(red.front() - prev, a - red.back());
					for (int i = 1; i < red.size(); i++) {
						maxr = max(maxr, red[i] - red[i-1]);
					}
					other += a - prev - maxr;
				}
				if (!blue.empty()) {
					int maxb = max(blue.front() - prev, a - blue.back());
					for (int i = 1; i < blue.size(); i++) {
						maxb = max(maxb, blue[i] - blue[i-1]);
					}
					other += a - prev - maxb;
				}
				ans += a - prev;
				ans += min(a - prev, other);
			}
			prev = a;
			red.clear();
			blue.clear();
		}
	}

	if (prev == 0) {
		if (!red.empty()) {
			ans += red.back() - red.front();
		}
		if (!blue.empty()) {
			ans += blue.back() - blue.front();
		}
	}
	else {
		if (!red.empty()) {
			ans += red.back() - prev;
		}
		if (!blue.empty()) {
			ans += blue.back() - prev;
		}
	}

	cout << ans << nl;

	return 0;
}