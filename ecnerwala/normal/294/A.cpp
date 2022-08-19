/*
LANG: C++
ID: he.andr1
PROG: A
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cassert>
#include<stack>
#include<list>
#include<cstdio>
#include<numeric>
#include<complex>
#include<string>
#include<map>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(v, i) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef pair<int, int> pii;
typedef complex<int> pt;
typedef long long ll;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }

template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }

template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 105;

int N, a[MAXN];

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 1; i <= N; i++) {
		in >> a[i];
	}
	int M;
	in >> M;
	for(int i = 0; i < M; i++) {
		int x, y;
		in >> x >> y;
		a[x - 1] += y - 1;
		a[x + 1] += a[x] - y;
		a[x] = 0;
	}
	for(int i = 1; i <= N; i++) {
		out << a[i] << '\n';
	}
}

int main() {
	ifstream fin ("A.in");
	if(fin.good()) {
		ofstream fout ("A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}