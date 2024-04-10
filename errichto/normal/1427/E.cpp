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

/*
int len(int x) {
	for(int bit = 30; bit >= 0; --bit) {
		if((1 << bit) <= x) {
			return bit;
		}
	}
	return -1;
}

int check(int start) {
	set<int> s{start};
	int l = len(start);
	for(int rep = 0; rep < 10; ++rep) {
		set<int> s2 = s;
		for(int x : s) {
			for(int y : s) {
				s2.insert(x + y);
				s2.insert(x ^ y);
			}
		}
		s = s2;
		for(int x : s) {
			if(x != 0 && len(x) < l) {
				return rep + 1;
			}
		}
		// debug() << imie(s);
	}
	return -1;
}*/

#define int long long

set<pair<int,int>> set_sums, set_xors;
// vector<pair<int,int>> sums, xors;
vector<pair<char, pair<int,int>>> operations;
void SUM(int a, int b) {
	if(!set_sums.count({a, b})) {
		set_sums.insert({a, b});
		operations.emplace_back('+', make_pair(a, b));
		// sums.push_back({a, b});
	}
}
void XOR(int a, int b) {
	if(!set_xors.count({a, b})) {
		set_xors.insert({a, b});
		operations.emplace_back('^', make_pair(a, b));
		// xors.push_back({a, b});
	}
}

int significant(int x) {
	for(int bit = 30; bit >= 0; --bit) {
		if(x & (1 << bit)) {
			return bit;
		}
	}
	return -1;
}

int test(int x) {
	// int init_x = x;
	if(x % 4 == 3) {
		SUM(x, x);
		XOR(x, 2 * x);
		x = (x ^ (2 * x));
	}
	assert(x % 4 == 1);
	int len = significant(x);
	for(int rep = 0; rep < len; ++rep) {
		SUM(x << rep, x << rep);
	}
	int big_x = x << len;
	// debug() << imie(x) imie(big_x);
	XOR(x, big_x);
	int new_xor = x ^ big_x;
	SUM(x, big_x);
	int new_sum = x + big_x;
	// debug() << imie(new_xor) imie(new_sum);
	XOR(new_xor, new_sum);
	int power_of_two = new_xor ^ new_sum;
	assert(__builtin_popcount(power_of_two) == 1);
	assert(power_of_two > x);
	assert(power_of_two & (x * 2));
	// while(!(x & power_of_two)) {
		// x *= 2;
	// }
	SUM(x, x);
	XOR(power_of_two, 2 * x);
	int ans = power_of_two ^ (x * 2);
	
	while(significant(ans) != significant(x)) {
		SUM(ans, ans);
		ans *= 2;
	}
	XOR(ans, x);
	ans ^= x;
	// debug() << imie(init_x) imie(ans);
	assert(significant(ans) < significant(x) && ans % 2 == 1);
	return ans;
}

void path(int x) {
	int steps = 0;
	while(x != 1 && ++steps <= 22) {
		cerr << x << ", ";
		x = test(x);
	}
	assert(steps <= 21);
	cerr << 1 << endl;
}

#undef int
int main() {
#define int long long
	// for(int x = 3; x <= 20; x += 2) {
		int x;
		scanf("%lld", &x);
		path(x);
		printf("%lld\n", (int) operations.size());
		for(auto pp : operations) {
			printf("%lld %c %lld\n", pp.second.first, pp.first, pp.second.second);
		}
		return 0;
	// }
}

 // 101
// 1010
// 1111

   // 1001
  // 1001
// 1001000
// 1010001
// 1000001
  // 10000

   // 1xy1   y=0
// 1xy1000
// 1xy0xy1 -- XOR
// 1xy0xy1 -- SUM
 // +1
 
// XOR of last two:

// 0010000
  // 1xy1 
// XOR:
   // xy10 <-- double this to get 1 on first position
   // 1xy1  XOR    if x=1 then shorter odd number   :)
   
   // if x=0
   
   // y100
   // 1xy1