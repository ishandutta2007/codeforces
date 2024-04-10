/*
LANG: C++
ID: he.andr1
PROG: 354E
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

const int M = 6;

typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;

multimap<int, pip> ways;

void precomp() {
	for(int i = 0; i <= 6; i++) {
		for(int j = 0; i + j <= 6; j++) {
			//cerr << i << " 4's, " << j << " 7's, sum " << (4 * i + 7 * j) << '\n';
			int s = 4 * i + 7 * j;
			pii p(i, j);
			ways.insert(make_pair(s % 10, pip(s / 10, p)));
		}
	}
	/*
	 *ITER(i, ways) {
	 *    cerr << i->B.A << i->A << ": " << i->B.B.A << ' ' << i->B.B.B << '\n';
	 *}
	 */
}

const pii BAD(-1, -1);

map<ll, pii> dp;

bool dfs(ll n) {
	if(n == 0) 
		return true;
	if(n < 0) 
		return false;
	if(dp.count(n)) {
		return dp[n] != BAD;
	}
	int d = n % 10;
	__typeof(ways.equal_range(d)) its = ways.equal_range(d);
	for(__typeof(its.A) it = its.A; it != its.B; it++) {
		pip i = it->B;
		if(dfs(n / 10 - i.A)) {
			dp[n] = i.B;
			return true;
		}
	}
	dp[n] = BAD;
	return false;
}

ll ans[M];

void go(ll n) {
	if(dfs(n)) {
		memset(ans, 0, sizeof(ans));
		for(ll p10 = 1; n; p10 *= 10, n /= 10) {
			pii p = dp[n];
			for(int i = 0; i < p.A; i++) {
				ans[i] += 4 * p10;
			}
			for(int i = 0; i < p.B; i++) {
				ans[i + p.A] += 7 * p10;
			}
			n -= 4 * p.A + 7 * p.B;
			assert(n % 10 == 0);
			assert(n >= 0);
		}
	} else ans[0] = -1;
}

void io(istream &in, ostream &out) {
	precomp();
	int T; in >> T;
	for(int i = 0; i < T; i++) {
		ll n; in >> n;
		go(n);
		if(ans[0] == -1) out << -1 << '\n';
		else {
			for(int i = 0; i < M; i++) out << ans[i] << ' '; out << '\n';
		}
	}
}

int main() {
	ifstream fin ("354E.in");
	if(fin.good()) {
		ofstream fout ("354E.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}