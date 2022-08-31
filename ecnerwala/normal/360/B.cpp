/*
LANG: C++
ID: he.andr1
PROG: 360B
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

const int MAXN = 4000;

int N, K;

ll A[MAXN];

int dp[MAXN];

bool isGood(ll V) {
	for(int i = 0; i < N; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(abs(A[j] - A[i]) <= V * (i - j)) 
				setmax(dp[i], dp[j] + 1);
		}
		if(dp[i] >= (N - K)) return true;
	}
	return false;
}

ll bsearch() {
	ll min = -1;
	ll max = 1ll << 31;

	while(max - min > 1) {
		ll mid = (min + max) / 2;
		if(isGood(mid)) max = mid;
		else min = mid;
	}
	return max;
}

void io(istream &in, ostream &out) {
	in >> N >> K;
	for(int i = 0; i < N; i++) in >> A[i];

	out << bsearch() << '\n';
}

int main() {
	ifstream fin ("360B.in");
	if(fin.good()) {
		ofstream fout ("360B.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}