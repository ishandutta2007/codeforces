/*
LANG: C++
ID: he.andr1
PROG: B
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

//limits are open; assume that x.B - x.A <= limits.B - limits.A;
pii coerce(pii limits, pii x) {
	if(x.A < limits.A) {
		return pii(limits.A, limits.A + x.B - x.A);
	}
	if(x.B > limits.B) {
		return pii(limits.B - x.B + x.A, limits.B);
	}
	return x;
}

int gcd(int a, int b) { if(!a) return b; return gcd(b % a, a); }

void io() {
	int N, M, X, Y, A, B;
	cin >> N >> M >> X >> Y >> A >> B;
	int g = gcd(A, B);
	A /= g;
	B /= g;
	int k = min(N / A, M / B);
	A *= k;
	B *= k;
	pii x = coerce(pii(0, N), pii(X + A / 2 - A, X + A / 2));
	pii y = coerce(pii(0, M), pii(Y + B / 2 - B, Y + B / 2));
	cout << x.A << ' ' << y.A << ' ' << x.B << ' ' << y.B << '\n';
}

int main() {
	io();
	return 0;
}