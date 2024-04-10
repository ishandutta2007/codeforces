/*
LANG: C++
ID: he.andr1
PROG: 360D
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
typedef pair<ll, ll> pll;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const ll MAXN = 20000;
const ll MAXM = 200000;
const ll MAXP = 2000000000;

template <class T> T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }

ll N, M, P;
ll A[MAXN], B;
ll E;

ll exp(ll a, ll b) {
	b %= P - 1;
	ll ans = 1;
	ll pow2 = a;
	for(; b > 0; b /= 2) {
		if(b % 2) ans *= pow2, ans %= P;
		pow2 *= pow2, pow2 %= P;
	}
	return ans;
}

ll K;
vector<ll> pr;
vector<ll> exps;

void pfactor(ll V) {
	for(int i = 2; i * i <= V; i++) {
		if(V % i == 0) {
			int cnt = 0;
			for(;V % i == 0; V /= i) cnt++;
			pr.push_back(i);
			exps.push_back(cnt);
		}
	}
	if(V > 1) pr.push_back(V), exps.push_back(1);
	K = pr.size();
}

set<vector<ll> > used;

ll phi(const vector<ll> &ord) {
	ll ans = 1;
	for(int i = 0; i < K; i++) {
		if(ord[i]) {
			ans *= pr[i] - 1;
			for(int j = 1; j < ord[i]; j++) ans *= pr[i];
		}
	}
	return ans;
}

void dfs(vector<ll> &ord) {
	if(used.count(ord)) return;
	used.insert(ord);

	for(int i = 0; i < K; i++) {
		if(ord[i]) {
			ord[i] --;
			dfs(ord);
			ord[i] ++;
		}
	}
}

ll go() {
	for(int i = 0; i < N; i++) {
		A[i] = exp(A[i], B);
	}
	E = (P - 1) / B;

	//cerr << B << ' ' << E << '\n';

	pfactor(E);

	//for(int i = 0; i < K; i++) cerr << pr[i] << '^' << exps[i] << '*'; cerr << '\n';

	for(int i = 0; i < N; i++) {
		vector<ll> ord = exps;
		for(int j = 0; j < K; j++) {
			ll pw = E / pr[j];
			for(; ord[j] > 0 && exp(A[i], pw) % P == 1; pw /= pr[j]) ord[j] --;
		}
		dfs(ord);
	}

	//cerr << used.size() << '\n';
	
	ll ans = 0;
	ITER(v, used) {
		ans += phi(*v);
	}
	return ans;
}

void io(istream &in, ostream &out) {
	in >> N >> M >> P;
	B = P - 1;
	for(int i = 0; i < N; i++) {
		in >> A[i];
	}
	for(int i = 0; i < M; i++) {
		ll b; in >> b;
		B = gcd(B, b);
	}

	out << go() << '\n';
}

int main() {
	ifstream fin ("360D.in");
	if(fin.good()) {
		ofstream fout ("360D.out");
		io(fin, fout);
		fin.close();
		fout.close();
	} else 
		io(cin, cout);
	return 0;
}