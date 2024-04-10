/*
LANG: C++
ID: he.andr1
PROG: 339D
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

const int MAXN = 18;
int N, M;

int vals[MAXN][1 << MAXN];

void comp(int r, int n) {
	if(r % 2) vals[r + 1][n] = vals[r][2 * n] ^ vals[r][2 * n + 1];
	else	  vals[r + 1][n] = vals[r][2 * n] | vals[r][2 * n + 1];
}

void fill() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < (1 << (N - 1 - i)); j++) {
			comp(i, j);
		}
	}
}

void update(int p, int b) {
	vals[0][p] = b;
	for(int i = 0; i < N; i++) {
		comp(i, p /= 2);
	}
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < (1 << N); i++) {
		in >> vals[0][i];
	}
	fill();
	for(int i = 0; i < M; i++) {
		int p, b; in >> p >> b;
		p--;
		update(p, b);
		out << vals[N][0] << '\n';
	}
}

int main() {
	ifstream fin ("339D.in");
	if(fin.good()) {
		ofstream fout ("339D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}