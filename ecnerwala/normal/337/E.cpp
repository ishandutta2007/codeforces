/*
LANG: C++
ID: he.andr1
PROG: 337E
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

const int MAXN = 15;
const ll MAXA = 2000000000000;

const ll INF = MAXN * MAXA;

int N;
ll A[MAXN];

ll P[MAXN];

ll A2[MAXN];

int numPrimes(ll n) {
	int ans = 0;
	for(ll i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			n /= i;
			ans ++;
		}
	}
	if(n > 1) ans ++;
	return ans;
}

ll recurse(ll pos, ll val = 0) {
	if(pos < 0) {
		return val;
	}
	ll ans = recurse(pos - 1, val + P[pos]);
	for(int i = pos + 1; i < N; i++) {
		if(A2[i] % A[pos] == 0) {
			A2[i] /= A[pos];
			ll cnd = recurse(pos - 1, val);
			setmin(ans, cnd);
			A2[i] *= A[pos];
		}
	}
	return ans;
}

ll go() {
	sort(A, A + N);

	for(int i = 0; i < N; i++) {
		P[i] = numPrimes(A[i]);
	}

	//for(int i = 0; i < N; i++) cerr << A[i] << ' ' << P[i] << '\n'; cerr << '\n';
	
	// clear out primes
	int numCleared = 0;
	for(int i = 0; i < N; i++) {
		if(P[i] == 1) {
			
			//find whether we are forced to have it
			bool isFound = false;
			for(int j = i + 1; j < N; j++) {
				if(A[j] % A[i] == 0) isFound = true;
			}

			//cerr << A[i] << ' ' << isFound << '\n';

			//if it's not forced, it has to got to the root
			if(!isFound) numCleared++;

			//remove it
			for(int j = i + 1; j < N; j++) {
				A[j - 1] = A[j];
				P[j - 1] = P[j];
			}
			N--;
			A[N] = 0;

			i--;

		}
	}

	cerr << N << ' ' << numCleared << '\n';

	//edge case 
	
	if(N == 0) {
		assert(numCleared > 0);
		if(numCleared == 1) return 1;
		return numCleared + 1;
	}

	memcpy(A2, A, sizeof(A));
	ll bestVal = recurse(N - 1);
	cerr << bestVal << '\n';

	if(bestVal == P[N - 1]) {
		// this must be everything under the last node
		if(numCleared == 0) return P[N - 1] + N;
	}

	return bestVal + N + 1 + numCleared;
}

void io(istream &in, ostream &out) {
	in >> N;
	for(int i = 0; i < N; i++) in >> A[i];
	out << go() << '\n';
}

int main() {
	ifstream fin ("337E.in");
	if(fin.good()) {
		ofstream fout ("337E.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}