/*
LANG: C++
ID: he.andr1
PROG: 354A
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

const int MAXN = 200000;

int N;
ll W[MAXN];
ll l, r, ql, qr;

ll minWt() {
	ll ls = 0, rs = 0;
	for(int i = 0; i < N; i++) rs += W[i];

	ll ans = r * rs + (N - 1) * qr;
	for(int i = 0; i < N; i++) {
		ls += W[i], rs -= W[i];
		ll nl = i + 1, nr = N - nl;
		ll val = ls * l + rs * r;
		if(nl > nr) val += (nl - nr - 1) * ql;
		else if(nr > nl) val += (nr - nl - 1) * qr;
		if(val < ans) {
			ans = val;
		}
	}

	return ans;
}

void io(istream &in, ostream &out) {
	in >> N >> l >> r >> ql >> qr;
	for(int i = 0; i < N; i++) in >> W[i];
	out << minWt() << '\n';
}

int main() {
	ifstream fin ("354A.in");
	if(fin.good()) {
		ofstream fout ("354A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}