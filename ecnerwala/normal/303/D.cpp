/*
LANG: C++
ID: he.andr1
PROG: D
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

const int MAXN = 5000050, MAXX = 1000000010;

int N, X;

bool isPrime(int n) {
	if(n <= 2) return n == 2;
	if(!(n % 2)) return false;
	for(int i = 3; i * i <= n; i += 2) {
		if(!(n % i)) return false;
	}
	return true;
}

vector<pii> factors;

void factor(int n) {
	for(int i = 2; i * i <= n; i += i % 2, i ++) {
		int a = 0;
		for(; !(n % i); a++) n /= i;
		if(a) factors.push_back(pii(i, a));
	}
	if(n > 1) factors.push_back(pii(n, 1));
}

ll powExp(ll a, ll b, ll m) {
	a %= m;
	ll out = 1;
	for(int i = 0; (1 << i) <= b; i++, a *= a, a %= m) {
		if((1 << i) & b) out *= a, out %= m;
	}
	return out;
}

int go() {
	if(!isPrime(N + 1)) return -1;
	if(X <= 2) return -1;
	if(N == 1) return X - 1;
	if(N == 2) return X - 1 - X % 3;
	factor(N);
	//ITER(factors, f) cerr << f->A << ' ' << f->B << '\n';
	for(int i = X - 1; i > 1; i --) {
		if(!(i % (N + 1))) continue;
		bool good = true;
		ITER(factors, f) {
			if(powExp(i, N / f->A, N + 1) == 1) {
				//cerr << i << ' ' << N / f->A << '\n';
				good = false;
				break;
			}
		}
		if(good) return i;
	}
	return -1;
}

int main() {
	cin >> N >> X;
	cout << go() << '\n';
	return 0;
}