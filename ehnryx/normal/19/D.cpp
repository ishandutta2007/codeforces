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
	os << "{ ";
	for (const T& it : v) os << it << " ";
	os << "}"; return os;
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

struct SegTree {
	static const int n = 1<<18;
	int rmq[2*n];
	set<int> verts[2*n];

	SegTree() {}

	void insert(int x, int y) {
		verts[x].insert(y);
		x += n;
		rmq[x] = max(rmq[x], y);
		for ( ; x > 1; x >>= 1)
			rmq[x>>1] = max(rmq[x], rmq[x^1]);
	}

	void erase (int x, int y) {
		verts[x].erase(y);
		x += n;
		rmq[x] = verts[x].empty() ? 0 : *prev(verts[x].end());
		for ( ; x > 1; x >>= 1)
			rmq[x>>1] = max(rmq[x], rmq[x^1]);
	}

	pii query(int x, int y) {
		int left = query(x+1, y, 1, 0, n-1);
		if (left == -1) return pii(-1,-1);
		else return pii(left, *verts[left].upper_bound(y));
	}

	int query(int x, int bound, int i, int start, int end) {
		if (rmq[i] <= bound)
			return -1;
		if (start == end)
			return start;

		int mid = (start+end)/2;
		int left = -1;
		if (x <= mid)
			left = query(x, bound, i<<1, start, mid);
		if (left == -1)
			left = query(x, bound, i<<1|1, mid+1, end);
		return left;
	}
};

SegTree points;

struct Query {
	int c, x, y;
	Query() {}
	Query(int c, int x, int y):
		c(c), x(x), y(y) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	int x, y;

	set<int> seen;
	map<int,int> compress;
	vector<int> remap;
	vector<Query> queries;
	for (int i = 0; i < n; i++) {
		cin >> s >> x >> y;
		queries.push_back(Query(s[0],x,y));
		seen.insert(x);
	}

	int cur = 0;
	for (int it : seen) {
		compress[it] = cur;
		remap.push_back(it);
		cur++;
	}

	for (const Query& q : queries) {
		if (q.c == 'a') {
			points.insert(compress[q.x], q.y);
		} else if (q.c == 'r') {
			points.erase(compress[q.x], q.y);
		} else {
			pii ans = points.query(compress[q.x], q.y);
			if (ans.first == -1)
				cout << -1 << nl;
			else
				cout << remap[ans.first] << " " << ans.second << nl;
		}
	}

	return 0;
}