/*
LANG: C++
ID: he.andr1
PROG: C
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

const int MAXN = 400000, MAXQ = 400000;

int N, Q;
ll A[MAXN];
ll W[MAXN];

void io(istream &in, ostream &out) {
    in >> N >> Q;
    for(int i = 0; i < N; i++) {
        in >> A[i];
    }
    for(int i = 0; i < Q; i++) {
        int l, r; in >> l >> r;
        l--, r--;
        W[l] ++, W[r + 1]--;
    }
    for(int i = 1; i < N; i++) {
        W[i] += W[i - 1];
    }
    sort(A, A + N); sort(W, W + N);
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i] * W[i];
    }
    out << ans << '\n';
}

int main() {
	ifstream fin ("C.in");
	if(fin.good()) {
		ofstream fout ("C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}