/*
LANG: C++
ID: he.andr1
PROG: 340C
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

template <class T> T gcd(T a, T b) {
	return (a == 0) ? b : gcd(b % a, a);
}

int N;
ll A[200000];

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) in >> A[i];
	A[N ++] = 0;
	sort(A, A + N);
	ll s = 0;
	for(int i = 0; i < N; i++) s += A[i];

	ll n = 0;
	ll d = N - 1;

	for(int i = 0; i + 1 < N; i++) {
		//move from A[i] to A[i + 1]
		s += ((i + 1) - (N - i - 1)) * (A[i + 1] - A[i]);
		n += s;
	}
	
	ll g = gcd(n, d);
	n /= g;
	d /= g;
	
	cout << n << ' ' << d << '\n';
}

int main() {
	ifstream fin ("340C.in");
	if(fin.good()) {
		ofstream fout ("340C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}