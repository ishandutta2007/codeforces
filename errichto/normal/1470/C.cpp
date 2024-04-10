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

#define int long long
#undef assert
#define assert(x) 

int n, k;
vector<int> a;
int hidden_impo;
void init(int impo) {
	hidden_impo = impo;
	a.clear();
	a.resize(n, k);
}
void process() {
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		int prv = (i == 0 ? n - 1 : i - 1);
		int nxt = (i == n - 1 ? 0 : i + 1);
		if(i == hidden_impo) {
			b[nxt] += a[i];
		}
		else {
			b[nxt] += (a[i] + 1) / 2;
			b[prv] += a[i] / 2;
		}
	}
	a = b;
	debug() << imie(a);
	assert(a[hidden_impo] == k);
	for(int i = 1; i < n / 2; ++i) {
		assert(a[(i+hidden_impo)%n] >= a[(i+1+hidden_impo)%n]);
	}
	for(int i = n / 2 + 1; i < n; ++i) {
		assert(a[(i+hidden_impo)%n] <= a[(i-1+hidden_impo)%n]);
	}
}
int query(int id) {
	printf("? %lld\n", id + 1);
	fflush(stdout);
	long long r;
	scanf("%lld", &r);
	return r;
	// assert(0 <= id && id < n);
	// int ret = a[id];
	// process();
	// return ret;
}

// void test(int n, int k) {
	// int impo = 12;
	// assert(4 <= n && k % 2 == 0);
	// vector<int> a(n, k);
	// for(int turn = 1; turn <= 1000; ++turn) {
		
	// }
	// for(int i = 0; i < n; ++i) {
		// if(i < 1000 || i > n - 1000) {
			// printf("%d ", a[i]);
		// }
	// }
	// puts("");
// }

#undef int
int main(int argc, char* argv[]) {
	#define int long long
	// srand(atoi(argv[1]));
	// debug() << imie(atoi(argv[1]));
	scanf("%lld%lld", &n, &k);
	// n = 4 + rand() % 10;
	// k = 2 * (1 + rand() % 10);
	// init(rand() % n);
	// debug() << imie(n) imie(k) imie(hidden_impo);
	// test(50123, 1024);
	// n = 4;
	// k = 2;
	// init(2);
	int whom = 0;
	int value;
	for(int diff = 1; true; ++diff) {
		whom = (whom + diff) % n;
		value = query(whom);
		if(value != k) {
			cerr << "iterations: " << diff << endl;
			break;
		}
	}
	// int value = query(whom);
	debug() << imie(whom) imie(value);
	assert(value != k);
	// assert(a[whom] != k);
	bool to_left = (value > k);
	for(int shift = 1 << 20; shift >= 1; shift /= 2) {
		if(shift >= n) {
			continue;
		}
		if(to_left) {
			int maybe = (whom + n - shift) % n;
			if(query(maybe) > k) {
				whom = maybe;
			}
		}
		else {
			int maybe = (whom + shift) % n;
			if(query(maybe) < k) {
				whom = maybe;
			}
		}
	}
	if(to_left) {
		whom = (whom + n - 1) % n;
	}
	else {
		whom = (whom + 1) % n;
	}
	assert(query(whom) == k);
	assert(whom == hidden_impo);
	printf("! %lld\n", whom + 1);
	
	// for(int n = 4; n <= 20; ++n) {
		// for(int k = 2; k <= 12; k += 2) {
			// test(n, k);
		// }
	// }
}