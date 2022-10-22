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

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> stk;

	int cur = 1;
	int max_a = 0;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		max_a = max(max_a, a[i]);
		if (a[i] != cur) {
			if (!stk.empty() && stk.back() < a[i]) {
				cout << -1 << nl;
				return 0;
			}
			stk.push_back(a[i]);
		}
		else {
			cur++;
			while (!stk.empty() && stk.back() == cur) {
				stk.pop_back();
				cur++;
			}
		}
	}

	// empty stack
	while (!stk.empty()) {
		if (stk.back() == cur) {
			while (!stk.empty() && stk.back() == cur) {
				stk.pop_back();
				cur++;
			}
		}
		else {
			a.push_back(stk.back()-1);
			stk.push_back(stk.back()-1);
		}
	}

	// reverse rest
	for (int i = n; i >= cur; i--) {
		a.push_back(i);
	}

	cout << a << nl;

	return 0;
}