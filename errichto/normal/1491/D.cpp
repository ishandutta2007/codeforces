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

vector<int> turn(int a) {
	vector<int> bits(30);
	for(int i = 0; i < 30; ++i) {
		if(a & (1 << i)) {
			bits[i] = 1;
		}
	}
	return bits;
}

bool query() {
	int a, b;
	scanf("%d%d", &a, &b);
	if(a > b) {
		return false;
	}
	vector<int> A = turn(a);
	vector<int> B = turn(b);
	int balance = 0;
	for(int i = 0; i < 30; ++i) {
		balance += A[i];
		balance -= B[i];
		if(balance < 0) {
			return false;
		}
	}
	return true;
}
	// debug() << imie(a) imie(b);
	// bool can_not = true, can_carry = false;
	// for(int i = 0; i < 30; ++i) {
		// bool new_can_not = false;
		// bool new_can_carry = false;
		// if((a & (1 << i)) && !(b & (1 << i))) {
			// if(can_not) {
				// new_can_carry = true;
			// }
			// if(can_carry) {
				// new_can_carry = true;
			// }
		// }
		// else if((a & (1 << i)) && (b & (1 << i))) {
			// if(can_not) {
				// new_can_not = true;
			// }
			// if(can_carry) {
				// new_can_carry = true;
			// }
		// }
		// else if(!(a & (1 << i)) && (b & (1 << i))) {
			// if(can_carry) {
				// new_can_not = true;
			// }
		// }
		// else if(!(a & (1 << i)) && !(b & (1 << i))) {
			// if(can_not) {
				// new_can_not = true;
			// }
			// if(can_carry) {
				// new_can_carry = true;
			// }
		// }
		// else {
			// assert(false);
		// }
		// can_not = new_can_not;
		// can_carry = new_can_carry;
	// }
	// puts(can_not ? "YES" : "NO");
// }

int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		puts(query() ? "YES" : "NO");
	}
}