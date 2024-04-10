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

pii operator + (const pii& a, const pii& b) {
	return pii(a.first + b.first, a.second + b.second);
}

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

struct Node {
	int id;
	int start, end;
	int moves;
	bool take;
	Node() {}
	Node(int i, int s, int e, int m, bool t): 
		id(i), start(s), end(e), moves(m), take(t) {}
};
ostream& operator << (ostream& os, const Node& n) {
	return os << n.id << ": " << pii(n.start,n.end) << " w/ moves " << n.moves << " take? " << n.take;
}

pii dp[102][2];
pii adj[102][102];

int traverse(int s, int t, int goal) {
	queue<Node> next;
	next.push(Node(s, 0, 0, 0, true));
	next.push(Node(s, 0, 0, 0, false));

	while (!next.empty()) {
		Node cur = next.front();
		next.pop();
		if (cur.id == t) {
			if (cur.start <= goal && goal <= cur.end)
				return cur.moves;
		}

		else if (cur.take) {
			next.push(Node(cur.id, cur.start + adj[cur.id][cur.id].first, cur.end + adj[cur.id][cur.id].second, cur.moves + 1, false));
			for (int i = cur.id + 1; i <= t; i++) {
				next.push(Node(i, cur.start + adj[cur.id][i].first, cur.end + adj[cur.id][i].second, cur.moves+1, false));
			}
		}

		else {
			for (int i = cur.id + 1; i <= t; i++) {
				next.push(Node(i, cur.start, cur.end, cur.moves+1, true));
			}
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	memset(adj, 0, sizeof adj);
	memset(dp, 0, sizeof dp);

	int n, k;
	cin >> n >> k;

	pii vals[k+2];
	for (int i = 1; i <= k; i++) {
		cin >> vals[i].first >> vals[i].second;
		adj[0][i] = vals[i];
		adj[i][k+1] = pii(2*n - vals[i].second, 2*n - vals[i].first);
		adj[i][i] = pii(0, vals[i].second - vals[i].first);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = i+1; j <= k; j++) {
			adj[i][j] = pii(vals[j].first - vals[i].second, vals[j].second - vals[i].first);
		}
	}

	int ans = traverse(0, k+1, n);
	if (ans == 0) {
		cout << "Hungry" << nl;
	} else {
		cout << "Full" << nl;
		cout << ans - 1 << nl;
	}

	return 0;
}