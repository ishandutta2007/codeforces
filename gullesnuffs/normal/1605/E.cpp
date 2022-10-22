#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
//#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

/*set<ll> divisors(ll n) {
	auto f = factor(n);
	set<ll> ret;
	rep(i,0,(1<<sz(f))) {
		ll p = 1;
		rep(j,0,sz(f)) {
			if (i&(1<<j))
				p *= f[j];
		}
		ret.insert(p);
	}
	return ret;
}*/

void solve() {
	int n;
#ifdef DEBUG
	n = 200000;
#else
	cin >> n;
#endif
	vector<ll> a(n);
	vector<ll> b(n);
#ifdef DEBUG
	rep(i,0,n)
		a[i] = rand()%1000000;
	rep(i,0,n)
		b[i] = rand()%1000000;
#else
	rep(i,0,n)
		cin >> a[i];
	rep(i,0,n)
		cin >> b[i];
#endif
	// Need to add (add[0][i]+b*add[1][i])
	vector<ll> add[2];
	add[0] = vector<ll>(n+1);
	add[1] = vector<ll>(n+1);
	add[0][1] = -a[0];
	add[1][1] = 1;
	vector<vector<ll>> divisors(n+1);
	rep(i,1,n+1) {
		for (int j = i; j <= n; j += i)
			divisors[j].push_back(i);
	}
	rep(i,2,n+1) {
		add[0][i] = b[i-1]-a[i-1];
		//auto factors = divisors(i);
		for (auto f : divisors[i]) {
			if (f == i)
				continue;
			add[0][i] -= add[0][f];
			add[1][i] -= add[1][f];
		}
	}
	// diffchange[i] = diff[i+1] - diff[i]
	//vector<ll> diffchange(1000005);
	vector<ll> diffi(n+1);
	ll cost = 0;
	map<ll, vector<int>> relevant;
	// diff[0] = cost[1]-cost[0]
	ll diff = 0;
	rep(i,1,n+1) {
		cost += abs(add[0][i]);
		diffi[i] = abs(add[0][i]+add[1][i])-abs(add[0][i]);
		diff += diffi[i];
		if (add[1][i]) {
			ll B = -add[0][i]/add[1][i];
			rep(j,B-2,B+2) {
				relevant[j].push_back(i);
			}
		}
	}
	vector<ll> ans(1000005);
	rep(B,0,1000003) {
		ans[B] = cost;
		for (int i : relevant[B]) {
			ll newdiffi = abs(add[0][i]+(B+1)*add[1][i])-abs(add[0][i]+B*add[1][i]);
			diff += newdiffi - diffi[i];
			diffi[i] = newdiffi;
		}
		cost += diff;
	}
#ifndef DEBUG
	int q;
	cin >> q;
	rep(i,0,q) {
		ll x;
		cin >> x;
		cout << ans[x] << endl;
	}
#endif
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	solve();
}