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




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	unordered_map<int,unordered_set<int>> adj;

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			adj[s[i]].insert(t[i]);
			adj[t[i]].insert(s[i]);
		}
	}

	unordered_set<int> vis;
	vector<pii> ans;
	for (const pair<int,unordered_set<int>>& it : adj) {
		if (!vis.count(it.first)) {
			stack<int> next;
			next.push(it.first);
			vis.insert(it.first);

			while (!next.empty()) {
				int cur = next.top();
				next.pop();
				for (int x : adj[cur]) {
					if (!vis.count(x)) {
						next.push(x);
						vis.insert(x);
						ans.push_back(pii(cur,x));
					}
				}
			}
		}
	}

	cout << ans.size() << nl;
	for (const pii& it : ans) {
		cout << (char)it.first << " " << (char)it.second << nl;
	}

	return 0;
}