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
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> moves;
	auto f = [&] (int x) {
		moves.push_back(x);
		assert(0 <= x && x <= n);
		string nowy;
		for(int i = 0; i < x; ++i)
			nowy += a[n-1-i];
		for(int i = 0; i < n - x; ++i)
			nowy += a[i];
		a = nowy;
	};
	
	map<char, int> mapka;
	for(char ch : a) ++mapka[ch];
	for(char ch : b) --mapka[ch];
	for(auto pp : mapka) if(pp.second) {
		puts("-1");
		return 0;
	}
	int low = n / 2;
	if(a[0] != b[low]) {
		int where = 0;
		while(a[where] != b[low]) ++where;
		if(where == n - 1) {
			f(n);
			debug() << "izi";
		}
		else {
			debug() << "hard";
			f(n-where-1);
			f(n);
		}
	}
	assert(a[0] == b[low]);
	int high = low;
	int order = 0;
	int pref = 1;
	while(pref < n) {
		if(order == 0) {
			assert(low >= 1);
			char want = b[low-1];
			int where = pref;
			while(a[where] != want) ++where;
			f(n-where);
			f(n- (n-where+pref));
			f(n);
			--low;
		}
		else {
			char want = b[high+1];
			int where = pref;
			while(a[where] != want) ++where;
			f(n-where);
			f(n- (n-where+pref));
			f(n);
			++high;
		}
		
		order = 1 - order;
		++pref;
	}
	if(a != b) f(n);
	assert(a == b);
	printf("%d\n", (int) moves.size());
	for(int x : moves) printf("%d ", x);
	puts("");
}