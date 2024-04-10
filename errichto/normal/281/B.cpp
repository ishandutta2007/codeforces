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

const ll B = 1e5;
pair<ll, ll> get_p(ll a) {
	return {a / B, a % B};
}
pair<ll, ll> mul(pair<ll,ll> a, pair<ll,ll> b) {
	ll one = a.first * b.first * B + a.first * b.second + a.second * b.first;
	ll two = a.second * b.second;
	one += two / B;
	two %= B;
	return {one, two};
}

bool is_smaller(ll a, ll b, ll c, ll d) {
	return mul(get_p(a), get_p(d)) < mul(get_p(b), get_p(c));
	// return a * d < b * c;
	// a/b < c/d
	assert(b);
	assert(d);
	ll one = a / b, two = c / d;
	if(one != two) {
		return one < two;
	}
	if(a % b != c % d) {
		return a % b < c % d;
	}
	return false;
}

bool is_eq(ll a, ll b, ll c, ll d) {
	return mul(get_p(a), get_p(d)) == mul(get_p(b), get_p(c));
	// return a * d == b * c;
	// a/b < c/d
	assert(b);
	assert(d);
	ll one = a / b, two = c / d;
	if(one != two) {
		return false;
	}
	if(a % b != c % d) {
		return false;
	}
	return false;
}


int main() {
	ll x, y, n;
	cin >> x >> y >> n;
	ll a = 1, b = 1;
	for(ll down = 1; down <= n; ++down) {
		// up/down=x/y
		for(ll up : {x*down/y, x*down/y+1}) {
			ll one = abs(up * y - x * down);
			ll two = y * down;
			
			ll three = abs(a * y - x * b);
			ll four = y * b;
			
			// one/two vs. three/four
			if(is_smaller(one, two, three, four) || (is_eq(one, two, three, four) && up < a)) {
				a = up;
				b = down;
			}
		}
	}
	printf("%lld/%lld\n", a, b);
}