/*
LANG: C++
ID: he.andr1
PROG: 337A
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

int N, M;
int F[100];

void io(istream &in, ostream &out) {
	in >> N >> M;
	for(int i = 0; i < M; i++) in >> F[i];
	sort(F, F+ M);
	int minVal = F[N - 1] - F[0];
	for(int i = 0; i + N - 1 < M; i++) setmin(minVal, F[i + N - 1]- F[i]);
	out << minVal << '\n';
}

int main() {
	ifstream fin ("337A.in");
	if(fin.good()) {
		ofstream fout ("337A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}