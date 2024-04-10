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



int main() {
	string s;
	cin >> s;
	int needs[3] = {0, 0, 0};
	for(char ch : s) {
		if(ch == 'B') needs[0]++;
		else if(ch == 'S') needs[1]++;
		else if(ch == 'C') needs[2]++;
		else assert(false);
	}
	int has[3];
	for(int i = 0; i < 3; ++i) {
		cin >> has[i];
	}
	int prices[3];
	for(int i = 0; i < 3; ++i) {
		cin >> prices[i];
	}
	long long money;
	cin >> money;
	long long answer = 0;
	while((has[0] && needs[0]) || (has[1] && needs[1]) || (has[2] && needs[2])) {
		long long cost = 0;
		for(int who = 0; who < 3; ++who) {
			int use = min(has[who], needs[who]);
			has[who] -= use;
			cost += (needs[who] - use) * prices[who];
		}
		if(cost <= money) {
			answer++;
		}
		money -= cost;
	}
	if(money >= 0) {
		long long cost = 0;
		for(int who = 0; who < 3; ++who) {
			cost += prices[who] * needs[who];
		}
		answer += money / cost;
	}
	printf("%lld\n", answer);
}