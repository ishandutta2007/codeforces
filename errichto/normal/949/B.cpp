#pragma GCC optimize ("Ofast")
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

typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	int q;
	scanf("%d", &q);
	vector<ll> queries(q);
	for(int i = 0; i < q; ++i)
		scanf("%lld", &queries[i]);
	vector<ll> answer(q);
	//~ vector<int> w(2 * n);
	//~ for(int i = 1; i <= n; ++i)
		//~ w[2*(i-1)] = i;
	//~ map<int,int> cnt;
	//~ for(int rep = 0; rep < n - 1; ++rep) {
		//~ int j = w.size();
		//~ --j;
		//~ while(!w[j]) --j;
		//~ int value = w[j];
		//~ ++cnt[value];
		//~ w[j] = 0;
		//~ --j;
		//~ while(w[j]) --j;
		//~ w[j] = value;
	//~ }
	//~ int big = 0;
	//~ for(pair<int,int> p : cnt) big = max(big, p.second);
	//~ printf("big = %d\n", big);
	//~ for(int i = 0; i < n; ++i) printf("%d ", w[i]); puts("");
	//~ return 0;
	//~ vector<int> my(n);
	ll i = 0;
	ll step = 2;
	ll start = 1;
	for(ll value = 1; value <= n; ++value) {
		if(i >= n) break;
		for(int iq = 0; iq < q; ++iq) {
			ll what = queries[iq] - 1;
			if(what % step == i)
				answer[iq] = value + (what - i) / step;
		}
		//~ my[i] = value;
		ll wholes = (n - 1 - i) / step;
		value += wholes;
		i += step * wholes;
		//~ debug() << imie(i) imie(wholes) imie(value);
		if(i + step / 2 < n) {
			//~ debug() << "a" imie(start) imie(step);
			i = start;
			start += step;
		}
		else {
			//~ debug() << "b";
			i = start + step;
		}
		step *= 2;
	}
	//~ for(i = 0; i < n; ++i) if(my[i]) assert(my[i] == w[i]); //printf("%d ", my[i]); puts("");
	//~ puts("OK");
	for(ll x : answer) {
		if(x == 0) x = n;
		printf("%lld\n", x);
	}
}