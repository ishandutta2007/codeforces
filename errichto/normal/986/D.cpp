#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

/* Prec. error max_ans/1e15 (2.5e18) for (long) doubles, so int rounding works
for doubles with answers 0.5e15, e.g. for sizes 2^20 and RANDOM ints in [0,45k],
assuming DBL_MANT_DIG=53 and LDBL_MANT_DIG=64. Consider normalizing and brute.*/
#define REP(i,n) for(int i = 0; i < int(n); ++i)
typedef double ld; // 'long double' is 2.2 times slower
struct C { ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) {
		real += he.real; imag += he.imag;
	}
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].real, om[k].imag * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
			}
	}
	if(rev) REP(i, n) a[i].real /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = false, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { // [0,B] into [-B/2, B/2]
		assert(a.size() == b.size()); // equal size!!!
		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } 
	while(n&(n-1)) ++n;
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i] - big;
		REP(i, b.size()) in[i].imag = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	//REP(i,ans.size())err=max(err,abs(done[i].real-ans[i]));
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 1<<15; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; // below use (in[i]-big) if normalized
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul *= M) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true); // remember: llround(prod[i].real)%MOD*mul !!!
			REP(i, ans.size()) ans[i]+= llround(prod[i].real)*mul;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}

const int LEN = 4;
const int B = 10000;

vector<ll> read() {
	static char sl[1505*1005];
	scanf("%s", sl);
	int n = strlen(sl);
	vector<int> tmp(n);
	for(int i = n - 1; i >= 0; --i) tmp[i] = sl[n-1-i] - '0';
	vector<ll> w;
	for(int i = 0; i < n; i += LEN) {
		ll x = 0, mno = 1;
		for(int j = i; j < i + LEN && j < n; ++j) {
			x += mno * tmp[j];
			mno *= 10;
		}
		w.push_back(x);
	}
	return w;
}

vector<ll> mul(vector<ll> a, vector<ll> b) {
	vector<ll> c = multiply(a, b);
	for(int i = 0; i < (int) c.size(); ++i) if(c[i] >= B) {
		if(i == (int) c.size() - 1) c.push_back(0);
		c[i+1] += c[i] / B;
		c[i] %= B;
	}
	return c;
}

#define multiply sadfsad

bool smaller_eq(const vector<ll> & a, const vector<ll> & b) {
	if(a.size() != b.size()) return a.size() < b.size();
	for(int i = (int) a.size() - 1; i >= 0; --i)
		if(a[i] != b[i]) return a[i] < b[i];
	return true; // equal ok
}
bool greater_eq(const vector<ll> & a, const vector<ll> & b) {
	if(a.size() != b.size()) return a.size() > b.size();
	for(int i = (int) a.size() - 1; i >= 0; --i)
		if(a[i] != b[i]) return a[i] > b[i];
	return true; // equal ok
}

int main() {
	vector<ll> w = read();
	vector<vector<ll>> they;
	they.push_back({3});
	//~ int at_most = 10;
	while(they.back().size() + 1 < w.size()) {
		vector<ll> nowy = mul(they.back(), they.back());
		debug() << imie(nowy);
		they.push_back(nowy);
		//~ printf("%d\n", (int) nowy.size());
	}
	vector<ll> cur{1};
	int answer = 0;
	for(int i = (int) they.size() - 1; i >= 0; --i) {
		vector<ll> maybe = mul(cur, they[i]);
		if(maybe.size() + 1 < w.size()) {
		//~ if(smaller_eq(maybe, w)) {
			cur = maybe;
			answer += 1 << i;
		}
	}
	ll low = 1, high = (1LL << 60) / B;
	while(low < high) {
		ll mid = (low + high) / 2;
		vector<ll> maybe = cur;
		for(int i = 0; i < (int) maybe.size(); ++i) maybe[i] *= mid;
		for(int i = 0; i < (int) maybe.size(); ++i) if(maybe[i] >= B) {
			if(i == (int) maybe.size() - 1) maybe.push_back(0);
			maybe[i+1] += maybe[i] / B;
			maybe[i] %= B;
		}
		if(greater_eq(maybe, w)) high = mid;
		else low = mid + 1;
		//~ vector<ll> maybe = mul(cur, my_converse(mid));
		//~ while(mid) {
	}
	while(low >= 10123) {
		low = (low + 2) / 3;
		++answer;
	}
	answer *= 3;
	ll n = low;
	
	//~ printf("answer = %d\n", answer);
	//~ printf("n = %lld\n", n);
	const int inf = 1e9 + 5;
	vector<int> dp(n + 10000, inf);
	dp[0] = 0;
	for(int a = 1; a <= 10; ++a) dp[a] = a;
	for(int x = 1; x <= n; ++x)
		for(int a = 2; a <= 10; ++a) {
			int rem = (x + a - 1) / a;
			dp[x] = min(dp[x], dp[rem] + a);
		}
	printf("%d\n", answer + dp[n]);
}