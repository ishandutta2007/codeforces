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

struct Hash {
	size_t operator() (const pii& e) const {
		hash<int> h;
		return h(e.first) ^ h(e.second);
	}
};

struct DSU {
	vector<int> root;
	vector<int> size;
	DSU(int n) {
		root.resize(n, -1);
		size.resize(n, 1);
	}

	int find(int i) {
		if (root[i] == -1) return i;
		return root[i] = find(root[i]);
	}
	void link(int i, int j) {
		int a = find(i);
		int b = find(j);
		if (a != b) {
			root[a] = b;
			size[b] += size[a];
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> deg(n+1, n-1);
	DSU dsu(n+1);
	unordered_set<pii, Hash> edges;
	//set<pii> edges;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges.insert(pii(min(a,b), max(a,b)));
		deg[a]--;
		deg[b]--;
	}

	srand(clock() + time(0));
	int cap = sqrt(n);
	int lim = min(n, max(100,cap/5));
	for (int i = 1; i <= n; i++) {
		if (deg[i] <= cap) {
			for (int j = 1; j <= n; j++) {
				if (!edges.count(pii(min(i,j), max(i,j)))) {
					dsu.link(i,j);
				}
			}
		}
		else {
			for (int j = 0; j <= lim; j++) {
				a = 1 + rand()%n;
				if (!edges.count(pii(min(i,a), max(i,a)))) {
					dsu.link(i,a);
				}
			}
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (i == dsu.find(i)) {
			ans.push_back(dsu.size[i]);
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << nl;
	for (int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}