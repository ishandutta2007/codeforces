#include <bits/stdc++.h>
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

/*1 6 8 12
6 = 2^1 * 3^1 * 5^0 * 7^0 * ...
number of prime divisors of X is log(X)
(N+Q)*log(X) nonzeros in total

                   v
exponents[2] = {0, 1, 3, 2}
     1) 1:1, 2:3, 3:2
     2) sorted DS to get minimum
exponents[3] = {0, 1, 0, 0}  1:1
exponents[5] = {0, 0, 0, 0}


exponents[2] = map(position -> exponent)*/

const int MAX = 2e5 + 5;
int n;
map<int,int> exponents[MAX];
multiset<int> ms[MAX];
bool is_prime[MAX];
int prime_divisor[MAX];

void sieve() {
	for(int p = 2; p < MAX; ++p) {
		is_prime[p] = true;
	}
	for(int p = 2; p < MAX; ++p) {
		if(is_prime[p]) {
			prime_divisor[p] = p;
			for(int a = 2 * p; a < MAX; a += p) {
				prime_divisor[a] = p;
				is_prime[a] = false;
			}
		}
	}
	for(int p = 2; p < 20; ++p) {
		debug() << imie(p) imie(prime_divisor[p]);
	}
}

int get_minimum(int p) {
	if((int) ms[p].size() == n) {
		return *ms[p].begin();
	}
	else {
		return 0;
	}
}

// 1600 -> 2^6 * 5^2
// factorization:
// 1) O(sqrt(X))
// 2) prime sieve in advance in O(MAX*log(MAX))
// 3) Pollard's Rho O(X^0.25)

vector<pair<int,int>> factorization(int x) {
	vector<pair<int,int>> v;
	while(x != 1) {
		int cnt = 0;
		int p = prime_divisor[x];
		while(x % p == 0) {
			x /= p;
			cnt++;
		}
		v.emplace_back(p, cnt);
	}
	return v;
}

int answer = 1;
void query(int i, int x) {
	for(pair<int,int> pair : factorization(x)) {
		int p = pair.first;
		int e = pair.second;
		int old_minimum = get_minimum(p);
		
		int& tmp = exponents[p][i];
		if(tmp != 0) {
			ms[p].erase(ms[p].find(tmp));
		}
		tmp += e;
		ms[p].insert(tmp);
		
		int new_minimum = get_minimum(p);
		for(int rep = 0; rep < new_minimum - old_minimum; ++rep) {
			answer = (long long) answer * p % 1'000'000'007;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int q;
	cin >> n >> q;
	// vector<int> a(n, 1);
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		query(i, x);
	}
	while(q--) {
		int i, x;
		cin >> i >> x;
		i--; // we use indices in [0, n-1]
		query(i, x);
		cout << answer << "\n";
	}
}

// for every prime, keep a multiset<int> with exponents of this prime