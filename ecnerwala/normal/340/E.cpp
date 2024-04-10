/*
LANG: C++
ID: he.andr1
PROG: 341C
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


const ll MOD = 1000000007;
const int MAXN = 4000;

template <class T> T inv(T a, T m) {
	if(a == 1) return 1;
	T k = inv(m % a, a);
	//k * m = j * a + 1
	T ans = - (k * m) / a;
	ans += m;
	ans %= m;
	assert((a * ans) % m == 1);
	return ans;
}

int N;
int A[MAXN];
bool filled[MAXN], used[MAXN];

ll go() {
	int F = 0;
	for(int i = 0; i < N; i++) {
		if(A[i] >= 0) {
			filled[i] = used[A[i]] = true;
		} else {
			F++;
		}
	}
	int K = 0;
	for(int i = 0; i < N; i++) {
		if(!filled[i] && !used[i]) K++;
	}

	cerr << F << ' ' << K << '\n';
	//formula is sum i in range(0, k) (-1)^i (kCi) (F-i)!
	ll kCi = 1;
	ll fact = 1;
	for(int i = 1; i <= F - K; i++) {
		fact *= i;
		fact %= MOD;
	}

	ll sum = 0;

	for(int i = K; i >= 0; 
			i--, 
			fact *= (F - i), fact %= MOD, 

			kCi *= (i + 1), kCi %= MOD, 
			kCi *= inv(ll(K - i), MOD), kCi %= MOD) {

		sum += kCi * fact * ((i % 2) ? -1 : 1);
		sum %= MOD;
		sum += MOD;
		sum %= MOD;
	}

	return sum;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) {
		in >> A[i];
		if(A[i] > 0) A[i] --;
	}

	out << go() << '\n';
}

int main() {
	io(cin, cout);
	return 0;
}