/*
LANG: C++
ID: he.andr1
PROG: 338E
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

const int MAXN = 250000;
const int MAXL = 18, S = 1 << (MAXL + 1);
const int MAXM = MAXN;

int N, M;
int A[MAXN], B[MAXM];
int H;

int size[S];
int mval[S];
int lazy[S];

void init() {
	for(int i = S - 1; i > 0; i--) {
		if(i * 2 >= S) {
			size[i] = 1;
			mval[i] = -(M - (i - S / 2));
			lazy[i] = 0;
		} else {
			size[i] = size[2 * i] + size[2 * i + 1];
			mval[i] = min(mval[2 * i], mval[2 * i + 1]);
			lazy[i] = 0;
		}
	}
}

// increment first a by diff at position i
void update(int a, int diff, int i = 1) {

	//edge case
	if(a == 0) return;
	
	//end condition
	if(size[i] == 1) {
		lazy[i] += diff;
		mval[i] += lazy[i];
		lazy[i] = 0;
		return;
	}

	//propogate
	lazy[2 * i] += lazy[i], lazy[2 * i + 1] += lazy[i];
	lazy[i] = 0;

	//recurse
	int s = size[2 * i];
	if(a >= s) {
		update(a - s, diff, 2 * i + 1);
		lazy[2 * i] += diff;
	} else {
		update(a, diff,2 * i);
	}

	//update value
	mval[i] = min(mval[2 * i] + lazy[2 * i], mval[2 * i + 1] + lazy[2 * i + 1]);
}

int go() {
	int cnt = 0;
	sort(B, B + M);
	//for(int i = 0; i < M; i++) cerr << B[i] << ' ';cerr << '\n';
	init();
	for(int i = 0; i < N; i++) {
		//cerr << A[i] << ' ';
		A[i] = B + M - lower_bound(B, B + M, H - A[i]);
		//cerr << A[i] << '\n';
	}
	for(int i = 0; i < M; i++) {
		update(A[i], 1);
	}
	if(mval[1] >= 0) cnt++;
	for(int i = M; i < N; i++) {
		update(A[i - M], -1);
		update(A[i], 1);
		if(mval[1] >= 0) cnt++;
	}
	return cnt;
}


void io(istream &in, ostream &out) {
	in >> N >> M >> H;
	for(int i = 0; i < M; i++) in >> B[i];
	for(int i = 0; i < N; i++) in >> A[i];
	out << go() << '\n';
}

int main() {
	ifstream fin ("338E.in");
	if(fin.good()) {
		ofstream fout ("338E.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}