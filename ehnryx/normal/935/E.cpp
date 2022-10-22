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

const int BROKEN = 0x7f7f7f7f;

namespace Tree {
	int n;
	vector<int> left, right, parent, value, subsize;
	int dp[2][101][10001];

	void build(const string& s) {
		n = s.size();
		left.resize(n+1, -1);
		right.resize(n+1, -1);
		parent.resize(n+1, -1);
		value.resize(n+1, -1);
		subsize.resize(n+1, 1);
		memset(dp, BROKEN, sizeof dp);

		int cur = n;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				if (left[cur] == -1) {
					left[cur] = i;
				} else {
					right[cur] = i;
				}
				parent[i] = cur;
				cur = i;
			}
			else if (s[i] == ')') {
				subsize[parent[cur]] += subsize[cur];
				cur = parent[cur];
			}
			else if (isdigit(s[i])) {
				if (left[cur] == -1) {
					left[cur] = i;
				} else {
					right[cur] = i;
				}
				parent[i] = cur;
				value[i] = s[i] - '0';
			}
		}
	}

#define BAD (big ? -INF : INF)
	int solve(int cur, int opcount, char op, bool big) {
		if (opcount > subsize[cur] || opcount < 0)
			return BAD;
		if (left[cur] == -1)
			return (opcount == 0) ? value[cur] : BAD;
		if (right[cur] == -1)
			return solve(left[cur], opcount, op, big);
		if (dp[big][opcount][cur] != BROKEN)
			return dp[big][opcount][cur];

		int val;
		int res = BAD;
		// put +
		for (int i = 0; i <= opcount - (op == '+'); i++) {
			val = solve(left[cur], i, op, big) + solve(right[cur], opcount-i - (op == '+'), op, big);
			res = big ? max(res, val) : min(res, val);
		}
		// put -
		for (int i = 0; i <= opcount - (op == '-'); i++) {
			val = solve(left[cur], i, op, big) - solve(right[cur], opcount-i - (op == '-'), op, !big);
			res = big ? max(res, val) : min(res, val);
		}
		return dp[big][opcount][cur] = res;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	string s;
	int plus, minus;
	cin >> s;
	cin >> plus >> minus;

	Tree::build(s);
	if (plus > minus) {
		cout << Tree::solve(s.size(), minus, '-', true) << nl;
	} else {
		cout << Tree::solve(s.size(), plus, '+', true) << nl;
	}

	return 0;
}