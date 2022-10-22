#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef int ld;
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

	pt mp[4];
	mp[0] = pt(0,1);
	mp[1] = pt(1,0);
	mp[2] = pt(0,-1);
	mp[3] = pt(-1,0);

	vector<int> perm;
	for (int i = 0; i < 4; i++) {
		perm.push_back(i);
	}

	int n, m;
	cin >> n >> m;
	string grid[n];
	pt start, end;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'S')
				start = pt(i,j);
		}
	}

	string s;
	cin >> s;

	int ans = 0;
	do {
		pt pos = start;
		bool shit = false;
		for (char c : s) {
			c -= '0';
			pos += mp[perm[c]];
			if (pos.real() < 0 || pos.imag() < 0) break;
			if (pos.real() >= n || pos.imag() >= m) break;
			if (grid[pos.real()][pos.imag()] == '#') break;
			if (grid[pos.real()][pos.imag()] == 'E') {
				shit = true;
				break;
			}
		}
		if (shit) {
			ans++;
		}
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << nl;

	return 0;
}