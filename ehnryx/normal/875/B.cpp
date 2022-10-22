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

struct DSU {
	vector<int> root;
	vector<int> weight;
	DSU(int n) {
		root.resize(n, -1);
		weight.resize(n, -1);
	}
	int find(int i) {
		if (root[i] == -1) return i;
		return root[i] = find(root[i]);
	}
	void link(int i, int j) {
		if (find(i) != find(j)) {
			weight[find(j)] += weight[find(i)];
			root[find(i)] = find(j);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n;
	cin >> n;
	DSU dsu(n);

	int a;
	vector<int> arr(n, 0);
	vector<int> ans;
	ans.push_back(1);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a; a--;
		arr[a] = 1;
		if (a+1 < n && arr[a+1] == 1)
			dsu.link(a, a+1);
		if (a-1 >= 0 && arr[a-1] == 1)
			dsu.link(a, a-1);
		cnt++;
		ans.push_back(1 + cnt + dsu.weight[dsu.find(n-1)] + !arr[n-1]);
	}

	for (int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}