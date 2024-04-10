/*
LANG: C++
ID: he.andr1
PROG: 343C
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

typedef vector<ll> vl;
typedef vl::iterator vli;

int N, M;
vector<ll> H;
vector<ll> P;

bool isGood(ll t) {
	vli np = P.begin();
	ITER(nh, H) {
		ll beg = *np;
		ll cur = *nh;
		if(beg > cur) beg = cur;
		while(np != P.end()) {
			ll end = *np;
			if(end < cur) end = cur;
			ll dist = (end - cur) + (cur - beg) + min(end - cur, cur - beg);
			if(dist <= t) {
				np++;
			} else {
				break;
			}
		}
		if(np == P.end()) return true;
	}
	return false;
}

ll bSearch() {
	ll min = -1, max = 1ll << 40;
	while(max - min > 1) {
		ll mid = (max + min) / 2;
		if(isGood(mid)) max = mid;
		else min = mid;
	}
	return max;
}

void io(istream &in, ostream &out) {
	in >> N >> M;
	H.resize(N);
	P.resize(M);
	for(int i = 0; i < N; i++) {
		in >> H[i];
	}
	for(int i = 0; i < M; i++) {
		in >> P[i];
	}
	cerr << "input read" << '\n';

	sort(H.begin(), H.end());
	sort(P.begin(), P.end());
	cerr << "sorted" << '\n';

	out << bSearch() << '\n';

}

int main() {
	ifstream fin ("343C.in");
	if(fin.good()) {
		ofstream fout ("343C.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}