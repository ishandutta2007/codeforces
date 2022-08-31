/*
LANG: C++
ID: he.andr1
PROG: 341D
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<string>
#include<cstring>
#include<cassert>
#include<numeric>
#include<complex>
#include<cmath>
#include<ctime>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 2000;
int N, M;

ll query1D(ll tree[MAXN], int x) {
	ll sum = 0;
	for(int idx = x; idx > 0; idx &= (idx - 1)) {
		sum ^= tree[idx];
	}
	return sum;
}

ll query2D(ll tree[MAXN][MAXN], int x, int y) {
	ll sum = 0;
	for(int idx = x; idx > 0; idx &= (idx - 1)) {
		sum ^= query1D(tree[idx], y);
	}
	return sum;
}

void insert1D(ll tree[MAXN], int x, ll v) {
	for(int idx = x; idx <= N; idx |= (idx - 1), idx ++) {
		tree[idx] ^= v;
	}
}

void insert2D(ll tree[MAXN][MAXN], int x, int y, ll v) {
	for(int idx = x; idx <= N; idx |= (idx - 1), idx ++) {
		insert1D(tree[idx], y, v);
	}
}

//x%2, y%2, x, y
ll tree[2][2][MAXN][MAXN];

void init() {
	memset(tree, 0, sizeof(tree));
}

ll query(int x, int y) {
	ll sum = 0;
	sum ^= query2D(tree[1][1], x, y);
	//y odd, x even
	if(x % 2) {
		sum ^= query2D(tree[0][1], N + 1 - (x + 1), y);
	}
	if(y % 2) {
		sum ^= query2D(tree[1][0], x, N + 1 - (y + 1));
	}
	if((x % 2) && (y % 2)) {
		sum ^= query2D(tree[0][0], N + 1 - (x + 1), N + 1 - (y + 1));
	}
	return sum;
}

ll query(int x0, int y0, int x1, int y1) {
	x0 --, y0 --;
	ll sum = 0;
	sum ^= query(x1, y1);
	sum ^= query(x1, y0);
	sum ^= query(x0, y1);
	sum	^= query(x0, y0);
	return sum;
}
 
void insert(int x, int y, ll v) {

	for(int t1 = 0; t1 < 2; t1++) {
		for(int t2 = 0; t2 < 2; t2++) {
			if((x % 2) >= t1 && (y % 2) >= t2) {
				insert2D(tree[t1][t2], t1 ? x : (N + 1 - x), t2 ? y : (N + 1 - y), v);
			}
		}
	}
}

void insert(int x0, int y0, int x1, int y1, ll v) {
	x0--, y0--;
	insert(x1, y1, v);
	insert(x1, y0, v);
	insert(x0, y1, v);
	insert(x0, y0, v);
}

void io(istream &in, ostream &out) {
	in >> N;
	int M; in >> M;
	init();
	for(int i = 0; i < M; i++) {
		int t; in >> t;
		if(t == 1) {
			//query
			int x0, y0, x1, y1;
			in >> x0 >> y0 >> x1 >> y1;
			out << query(x0, y0, x1, y1) << '\n';
		} else if(t == 2) {
			//update
			int x0, y0, x1, y1;
			ll v;
			in >> x0 >> y0 >> x1 >> y1 >> v;
			insert(x0, y0, x1, y1, v);
		}
	}
}

int main() {
	ifstream fin ("341D.in");
	if(fin.good()) {
		ofstream fout ("341D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}