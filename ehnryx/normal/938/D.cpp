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

struct Edge {
	int id;
	ll dist;
	Edge() {}
	Edge(int i, ll d): id(i), dist(d) {}
	bool operator < (const Edge& other) const {
		return dist > other.dist;
	}
};

vector<vector<Edge>> adj;
vector<ll> ans;

void dijkstra(int s) {
	priority_queue<Edge> next;
	next.push(Edge(s, 0));
	while (!next.empty()) {
		Edge cur = next.top();
		next.pop();
		if (ans[cur.id] == INFLL) {
			ans[cur.id] = cur.dist;
			for (const Edge& e : adj[cur.id]) {
				if (ans[e.id] == INFLL)
					next.push(Edge(e.id, e.dist + cur.dist));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n, m;
	cin >> n >> m;
	adj.resize(n+1);
	ans.resize(n+1, INFLL);

	ll a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(Edge(b,2*c));
		adj[b].push_back(Edge(a,2*c));
	}
	for (int i = 1; i <= n; i++) {
		cin >> c;
		adj[0].push_back(Edge(i,c));
		adj[i].push_back(Edge(0,c));
	}

	dijkstra(0);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}