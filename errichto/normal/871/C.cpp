#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int mod = 1e9 + 7;

const int C = 2e5 + 5;
const int nax = 2 * C;
int g[nax];
vector<int> inv[nax];
int cnt[nax];

void init(int x) {
	++cnt[x];
	g[x] = x;
	inv[x] = {x};
}

void uni(int a, int b) {
	a = g[a], b = g[b];
	if(a == b) return;
	if(inv[a].size() > inv[b].size()) swap(a, b);
	cnt[b] += cnt[a];
	cnt[a] = 0;
	for(int x : inv[a]) {
		g[x] = b;
		inv[b].push_back(x);
	}
	inv[a].clear();
}

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = (long long) r * a % mod;
		a = (long long) a * a % mod;
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> in(n);
	vector<int> values;
	for(pair<int,int> & p : in) {
		scanf("%d%d", &p.first, &p.second);
		values.push_back(p.first);
		values.push_back(p.second);
	}
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	auto where = [&] (int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
	for(pair<int,int> & p : in) {
		p.first = where(p.first);
		p.second = where(p.second) + C;
		init(p.first);
		init(p.second);
	}
	debug() << imie(in);
	for(pair<int,int> & p : in) {
		uni(p.first, p.second);
	}
	
	int answer = 1;

	for(int i = 0; i < nax; ++i) {
		assert((cnt[i] == 0) == (inv[i].empty()));
		if(cnt[i] == 0) continue;
		const int rows = inv[i].size();
		const int points = cnt[i] / 2;
		assert(cnt[i] % 2 == 0);
		debug() << imie(rows) imie(points);
		
		int total = 1;
		int here = 1; // C(rows, 0)
		for(int j = 1; j <= min(rows, points); ++j) {
			here = (long long) here * (rows + 1 - j) % mod;
			here = (long long) here * my_inv(j) % mod;
			total = (total + here) % mod;
		}
		
		answer = (long long) answer * total % mod;
	}
	
	printf("%d\n", answer);
}