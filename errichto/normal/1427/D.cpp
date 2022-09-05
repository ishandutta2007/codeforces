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
	int n;
	scanf("%d", &n);
	vector<int> cards(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &cards[i]);
	}
	// if n % 2 == 1 then put 1 at the beginning
	// end otherwise
	auto find = [&](int x) {
		for(int i = 0; i < n; ++i) {
			if(cards[i] == x) {
				return i;
			}
		}
		assert(false);
	};
	vector<vector<int>> print;
	auto ope = [&](vector<int> v) {
		debug() << imie(v);
		print.push_back(v);
		vector<vector<int>> new_v;
		int nxt = 0;
		for(int len : v) {
			vector<int> vec;
			while(len--) {
				vec.push_back(cards[nxt++]);
			}
			new_v.push_back(vec);
		}
		assert(nxt == n);
		reverse(new_v.begin(), new_v.end());
		cards.clear();
		for(vector<int> vec : new_v) {
			for(int x : vec) {
				cards.push_back(x);
			}
		}
		assert((int) cards.size() == n);
	};
	bool is_pref = true;
	if(n % 2 == 1 && cards[0] != 1) {
		int where = find(1);
		ope({where, n - where});
		assert(cards[0] == 1);
	}
	if(n % 2 == 0) {
		is_pref = false;
		if(cards[n-1] != 1) {
			int where = find(1);
			ope({where + 1, n - (where + 1)});
			assert(cards[n-1] == 1);
		}
	}
	
	for(int x = 2; x <= n; ++x) {
		int where = find(x);
		vector<int> v;
		debug() << imie(x) imie(cards) imie(is_pref);
		if(is_pref) {
			for(int i = 0; i < x - 1; ++i) {
				v.push_back(1);
			}
			v.push_back(where - x + 1 + 1);
			if(where != n - 1) {
				v.push_back(n - 1 - where);
			}
		}
		else {
			if(where != 0) {
				v.push_back(where);
			}
			v.push_back(n - where - x + 1);
			for(int i = 0; i < x - 1; ++i) {
				v.push_back(1);
			}
		}
		is_pref = !is_pref;
		ope(v);
	}
	debug() << imie(cards);
	assert((int) print.size() <= n);
	printf("%d\n", (int) print.size());
	for(vector<int> v : print) {
		printf("%d", (int) v.size());
		for(int x : v) {
			printf(" %d", x);
		}
		puts("");
	}
}