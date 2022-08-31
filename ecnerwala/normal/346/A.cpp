/*
LANG: C++
ID: he.andr1
PROG: 346A
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

template <class T> T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }

int N;
int A[200];

bool go() {
	int g = A[0];
	int m = A[0];
	for(int i = 1; i < N; i++) {
		g = gcd(g, A[i]);
		m = max(m, A[i]);
	}
	return (m / g - N) % 2;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) in >> A[i];
	out << (go() ? "Alice" : "Bob") << '\n';
}

int main() {
	ifstream fin ("346A.in");
	if(fin.good()) {
		ofstream fout ("346A.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}