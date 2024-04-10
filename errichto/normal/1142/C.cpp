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

using ll = long long;

//~ struct Q {
	

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> in(n);
	for(pair<int,int>& p : in) {
		scanf("%d%d", &p.first, &p.second);
	}
	sort(in.begin(), in.end());
	vector<pair<int,int>> only;
	for(int i = 0; i < n; ++i) {
		if(i == n - 1 || in[i+1].first != in[i].first) {
			only.push_back(in[i]);
		}
	}
	in = only;
	n = in.size();
	debug() << imie(in);
	int answer = 0;
	int a = 0;
	while(a != n - 1) {
		auto f = [&](int i) {
			return make_pair((ll) (in[i].first + in[a].first) * (in[i].first - in[a].first) - (in[i].second - in[a].second), in[i].first - in[a].first);
		};
		++answer;
		int best = a + 1;
		pair<ll,ll> p_best = f(a+1);
		for(int b = a + 2; b < n; ++b) {
			pair<ll,ll> p_maybe = f(b);
			if(a == 0) {
				debug() << imie(b) imie(p_maybe);
			}
			// p_maybe <= p_best
			ll one = p_maybe.first * p_best.second;
			ll two = p_maybe.second * p_best.first;
			if(one <= two) {
				best = b;
				p_best = p_maybe;
			}
			else if(b % 16 == 0) {
				int memo = in[b].second;
				in[b].second = 1000 * 1000;
				p_maybe = f(b);
				one = p_maybe.first * p_best.second;
				two = p_maybe.second * p_best.first;
				in[b].second = memo;
				if(one > two) {
					break;
				}
			}
		}
		a = best;
	}
	printf("%d\n", answer);
}