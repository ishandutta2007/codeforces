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

using ll = long long;

vector<ll> get_powers(ll x, ll R) {
	vector<ll> they{1};
	while((__int128) they.back() * x <= R) {
		they.push_back(they.back() * x);
	}
	return they;
}

int main() {
	ll x, y;
	cin >> x >> y;
	ll L, R;
	cin >> L >> R;
	vector<ll> a = get_powers(x, R), b = get_powers(y, R);
	vector<ll> total;
	for(ll i : a) {
		for(ll j : b) {
			if(i + j <= R) {
				total.push_back(i + j);
			}
		}
	}
	total.push_back(L - 1);
	total.push_back(R + 1);
	sort(total.begin(), total.end());
	// const ll INF = 1e18L + 5;
	ll answer = 0;
	for(int i = 0; i < (int) total.size() - 1; ++i) {
		assert(total[i] <= R);
		if(total[i] >= L - 1) {
			answer = max(answer, total[i+1] - total[i] - 1);
		}
	}
	cout << answer << endl;
}