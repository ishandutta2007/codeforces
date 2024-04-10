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

struct Edge {
	int id;
	int cost;
	Edge() {}
	Edge(int i, int c): id(i), cost(c) {}
};

vector<Edge> graph[101];

int memo[101][101][26];
int dp(int i, int j, int lb) {
	if (memo[i][j][lb] != -1)
		return memo[i][j][lb];

	for (const Edge& e : graph[i]) {
		if (e.cost >= lb && !dp(j, e.id, e.cost)) {
			return memo[i][j][lb] = 1;
		}
	}
	return memo[i][j][lb] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(memo, -1, sizeof memo);

	int n, m;
	cin >> n >> m;

	int a, b;
	char c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(Edge(b,c-'a'));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp(i, j, 0)) cout << 'A';
			else cout << 'B';
		}
		cout << nl;
	}

	return 0;
}