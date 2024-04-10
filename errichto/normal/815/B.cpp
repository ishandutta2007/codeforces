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

//~ void solve(vector<int> w, bool what = true) {
	//~ if((int) w.size() == 1) printf("%d ", w[0]);
	//~ else {
		//~ vector<int> nowy;
		//~ for(int i = 0; i < (int) w.size() - 1; ++i) {
			//~ nowy.push_back(what ? w[i] + w[i+1] : w[i] - w[i+1]);
			//~ what = !what;
		//~ }
		//~ solve(nowy, what);
	//~ }
//~ }

const int mod = 1e9 + 7;

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

//~ const int nax = 1
//~ int fac[nax];

int main() {
	int n;
	scanf("%d", &n);
	vector<int> w(n);
	for(int i = 0; i < n; ++i) scanf("%d", &w[i]);
	if(n == 1) {
		printf("%d\n", w[0]);
		return 0;
	}
	bool flag = true;
	if(n % 2 == 1) {
		vector<int> nowy;
		for(int i = 0; i < (int) w.size() - 1; ++i) {
			nowy.push_back(flag ? w[i] + w[i+1] : w[i] - w[i+1]);
			flag = !flag;
		}
		w = nowy;
		n = w.size();
	}
	vector<int> vec{1};
	int impo = n / 2 - 1;
	for(int i = 1; i <= impo; ++i) {
		int x = vec.back();
		x = (long long) x * (impo - i + 1) % mod * my_inv(i) % mod;
		vec.push_back(x);
	}
	debug() << imie(vec);
	debug() << imie(w.size()) imie(vec.size());
	assert(w.size() == 2 * vec.size());
	int answer = 0;
	for(int i = 0; i < (int) w.size(); ++i) {
		int mul = vec[i/2];
		if(n % 4 == 0 && i % 2) mul *= -1;
		answer = (answer + (long long) mul * w[i]) % mod;
	}
	answer %= mod;
	answer += mod;
	printf("%d\n", answer % mod);
	//~ assert(n % 2 == 0);
	//~ for(int n = 1; n <= 20; ++n) if(n % 2 == 0) {
		//~ vector<int> w(n);
		//~ for(int i = 0; i < n; ++i) {
			//~ w[i] = 1;
			//~ solve(w);
			//~ w[i] = 0;
		//~ }
		//~ puts("");
	//~ }
}