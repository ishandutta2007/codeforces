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

struct Block {
	char type;
	int x;
	Block(int t, int x = 0): type(t), x(x) {}
	operator int& () { return x; }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	vector<Block> val;

	for (int i = 0; i < n; i++) {
		if (i == 0 || s[i] != s[i-1]) {
			val.push_back(s[i]);
		}
		val.back()++;
	}

	int ans = 0;
	while (val.size() > 1) {
		ans++;
		for (int i = 0; i < val.size(); i++) {
			if (i == 0 || i == val.size()-1) {
				val[i] -= 1;
			} else {
				val[i] -= 2;
			}
		}

		vector<Block> temp;
		for (int i = 0; i < val.size(); i++) {
			if (val[i] > 0) {
				if (temp.empty() || val[i].type != temp.back().type) {
					temp.push_back(val[i]);
				} else {
					temp.back() += val[i];
				}
			}
		}
		val = temp;
	}

	cout << ans << nl;

	return 0;
}