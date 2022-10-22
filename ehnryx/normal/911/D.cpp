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

const int MAXN = 1500;
struct BIT {
	int freq[MAXN+1];
	BIT() { memset(freq, 0, sizeof(freq)); }
	void insert(int x) {
		for ( ; x <= MAXN; x += x & -x) 
			freq[x]++;
	}
	int query(int x) {
		int res = 0;
		for ( ; x > 0; x -= x & -x) 
			res += freq[x];
		return res;
	}
	int query(int xl, int xr) {
		return query(xr) - query(xl-1);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int invs = 0;
	int temp;
	BIT seen;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		invs += seen.query(temp, n);
		seen.insert(temp);
	}

	bool cur = invs % 2;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int v = b-a+1;
		v = v*(v-1)/2;
		if (v % 2 == 1)
			cur ^= 1;
		cout << (cur ? "odd" : "even") << nl;
	}

	return 0;
}