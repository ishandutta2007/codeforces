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


#define USE_MAGIC_IO
#ifdef USE_MAGIC_IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
#else
#define get() getchar()
#define read(x) scanf("%d",&x)
#endif


struct SegTree {
	static const int n = 1<<19;
	int nodes[2*n]; // ( perfect, off )

	SegTree() {
		memset(nodes, 0, sizeof nodes);
	}

	void build(int len, int arr[]) {
		for (int i = 0; i < len; i++)
			nodes[i+n] = arr[i];
		for (int i = n-1; i > 0; i--)
			nodes[i] = __gcd(nodes[i<<1], nodes[i<<1|1]);
	}

	void update(int x, int v) {
		x += n;
		nodes[x] = v;
		for ( ; x > 1; x >>= 1)
			nodes[x>>1] = __gcd(nodes[x], nodes[x^1]);
	}

	bool query(int l, int r, int v) {
		return query(l, r, v, 1, 1, n).first <= 1;
	}

	// change, div
	pii query(int l, int r, int v, int i, int start, int end) {
		if (start == end) {
			if (v == nodes[i])
				return pii(0,0);
			else if (nodes[i] % v == 0)
				return pii(0,1);
			else 
				return pii(1,0);
		}

		int mid = (start+end)/2;
		if (l == start && r == end) {
			if (v == nodes[i]) {
				return pii(0,0);
			} else if (nodes[i] % v == 0) {
				return pii(0,1);
			} else {
				goto split;
			}
		}

		if (r <= mid) {
			return query(l, r, v, i<<1, start, mid);
		} else if (l > mid) {
			return query(l, r, v, i<<1|1, mid+1, end);
		} else {
			split:
			pii res = query(l, mid, v, i<<1, start, mid);
			if (res.second == 1) {
				if (nodes[i<<1|1] % v != 0)
					res = query(mid+1, r, v, i<<1|1, mid+1, end);
			} else if (res.first == 0) {
				res = query(mid+1, r, v, i<<1|1, mid+1, end);
			} else if (res.first == 1) {
				res.first += query(mid+1, r, v, i<<1|1, mid+1, end).first;
			}
			return res;
		}
	}
};

SegTree segtree;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	read(n);
	//cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		read(arr[i]);
		//cin >> arr[i];
	}

	segtree.build(n, arr);

	int q;
	read(q);
	//cin >> q;

	int type, a, b, c;
	for (int i = 0; i < q; i++) {
		read(type);
		//cin >> type;

		if (type == 1) {
			read(a); read(b); read(c);
			//cin >> a >> b >> c;
			if (segtree.query(a, b, c))
				cout << "YES" << nl;
			else 
				cout << "NO" << nl;
		}

		else {
			read(a); read(c);
			//cin >> a >> c;
			segtree.update(a-1, c);
		}
	}

	return 0;
}