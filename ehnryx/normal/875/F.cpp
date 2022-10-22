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

struct Princess {
	int a, b, c;
	Princess() {}
	Princess(int a, int b, int c): a(a), b(b), c(c) {}
	bool operator < (const Princess& other) const { return c < other.c; }
	bool operator > (const Princess& other) const { return c > other.c; }
};

namespace DSU {
	vector<int> root;
	vector<bool> dead;
	void init(int n) {
		root.resize(n, -1);
		dead.resize(n);
	}

	int find(int i) {
		if (root[i] == -1) return i;
		return root[i] = find(root[i]);
	}
	bool link(int i, int j) {
		int a = find(i);
		int b = find(j);
		if (a == b) {
			if (dead[a]) return false;
			dead[a] = true; 
			return true;
		}
		root[a] = b;
		if (dead[a] && dead[b]) return false;
		if (dead[a]) dead[b] = true;
		return true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n, m;
	cin >> n >> m;

	vector<Princess> gods;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		gods.push_back(Princess(a,b,c));
	}
	sort(gods.begin(), gods.end(), greater<Princess>());

	DSU::init(n+1);
	int ans = 0;
	for (const Princess& it : gods) {
		if (DSU::link(it.a, it.b))
			ans += it.c;
	}
	cout << ans << nl;

	return 0;
}