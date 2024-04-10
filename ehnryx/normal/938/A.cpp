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


bool isvow(char c) {
	return !(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n; cin >> n;
	string s;
	cin >> s;
	string t;
	for (int i = 0; i < s.size(); i++) {
		if (t.empty() || !isvow(s[i]) || (isvow(s[i]) && !isvow(s[i-1])))
			t.push_back(s[i]);
	}
	cout << t << nl;

	return 0;
}