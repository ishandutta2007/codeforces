/*
LANG: C++
ID: he.andr1
PROG: 338D
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

//return inverse k of a mod b, assuming (a, b) = 1
//let m * (b % a) == 1 (a)
//= na + 1
//m < a
//(a - m) * b + 1 == 0 (a)
//(a - m) * b + 1 == 1 (b)
//=> return ((a - m) * b + 1) / a 
template <class T> T inv(T a, T b) { return (a == 1) ? 1 : ((a - inv(b % a, a)) * b + 1) / a; }

const ll MAXN = 2ll * 1000 * 1000 * 1000 * 1000, MAXM = MAXN, MAXA = MAXN;
const int MAXK = 20000;

ll N, M;
int K;
ll A[MAXK];
ll L;

ll findLCM() {
	ll l = 1;
	for(int i = 0; i < K; i++) {
		ll a = A[i];
		ll g = gcd(l, a);
		a /= g;
		if(N / a < l) return N + 1;
		l *= a;
	}
	return l;
}

// returns k st k == a (ma), k == b (mb), given (ma, mb) = 1
ll crt(ll a, ll ma, ll b, ll mb) {
	if(ma > mb) {
		swap(ma, mb);
		swap(a, b);
	}
	ll k = b;
	while(k % ma != a) {
		k += mb;
	}
	return k;
}

int vp(ll p, ll n) {
	int ans = 0;
	while(n % p == 0) {
		ans ++;
		n /= p;
	}
	return ans;
}

void update(ll &mod, ll &res, ll p, int exp) {
	ll pn = 1;
	for(int i = 0; i < exp; i++) pn *= p;
	//cerr << p << '^' << exp << '=' << pn << '\n';
	ll rem = -1;
	for(int i = 0; i < K; i++) {
		if(A[i] % pn == 0) {
			rem = (pn - i) % pn;
			break;
		}
	}
	//assert(rem >= 0);
	//cerr << rem << '\n';
	for(int i = 0; i < K; i++) {
		//cerr << A[i] << ' ' << i + rem << '\n';
		if(vp(p, A[i]) != min(vp(p, i + rem + pn), exp)) {
			res = M + 1;
		   	return;
		}
	}
	res = crt(res, mod, rem, pn);
	mod *= pn;
}

ll findLoc() {
	ll num = L;
	ll mod = 1;
	ll res = 0;
	for(ll p = 2; p * p <= num; p++) {
		if(num % p != 0) continue;
		int exp = 0;
		while(num % p == 0) {
			num /= p, exp++;
		}
		update(mod, res, p, exp);
		if(res > M) return M + 1;
	}
	if(num > 1) update(mod, res, num, 1);
	if(res == 0) res = mod;
	return res;
}

bool go() {
	L = findLCM();
	cerr << L << '\n';
	if(L > N) return false;
	ll R = findLoc();
	cerr << R << '\n';
	return R + K - 1 <= M;
}

void io(istream &in, ostream &out) {
	in >> N >> M >> K;
	for(int i = 0; i < K; i++) in >> A[i];
	out << (go() ? "YES" : "NO") << '\n';
}

int main() {
	ifstream fin ("338D.in");
	if(fin.good()) {
		ofstream fout ("338D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}