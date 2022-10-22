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

static const int N = 1e6;

struct BIT {
	int freq[N+1];
	BIT() { memset(freq, 0, sizeof freq); }
	void insert(int x) {
		for ( ; x <= N; x += x & -x)
			freq[x]++;
	}
	int query(int x) {
		int res = 0;
		for ( ; x > 0; x -= x & -x) 
			res += freq[x];
		return res;
	}
	int query(int lx, int rx) {
		return query(rx) - query(lx-1);
	}
};

BIT bit[9];
void init() {
	int ans[N+1];
	for (int i = 1; i < 10; i++) {
		ans[i] = i;
		bit[ans[i]-1].insert(i);
	}
	for (int i = 10; i <= N; i++) {
		int prod = 1;
		for (int j = i; j > 0; j /= 10)
			if (j % 10 != 0)
				prod *= j % 10;
		ans[i] = ans[prod];
		bit[ans[i]-1].insert(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();
	init();

	int q;
	cin >> q;

	int a, b, k;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> k;
		cout << bit[k-1].query(a, b) << nl;
	}

	return 0;
}