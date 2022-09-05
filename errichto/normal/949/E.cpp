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

vector<int> best(50);

vector<int> so_far;

void rec(int bit, const vector<bool> & must, const int magic) {
	assert((int) must.size() == 2 * magic + 1);
	if(so_far.size() >= best.size()) return;
	bool anything = false, any_odd = false;
	for(int i = -magic; i <= magic; ++i) if(must[i+magic]) {
		anything = true;
		if(i % 2) any_odd = true;
	}
	if(!anything) {
		best = so_far;
		return;
	}
	const int new_magic = magic / 2;
	debug() << imie(must) imie(magic);
	if(!any_odd) {
		vector<bool> must2(2 * new_magic + 1);
		for(int i = -magic; i <= magic; ++i) if(must[i+magic])
			must2[i/2 + new_magic] = true;
		must2[new_magic] = false;
		rec(bit + 1, must2, new_magic);
		return;
	}
	assert(any_odd);
	for(int used : {-1, 1}) {
		so_far.push_back(used * (1 << bit));
		vector<bool> must2(2 * new_magic + 1);
		bool ok = true;
		for(int i = -magic; i <= magic; ++i) if(must[i+magic]) {
			if(i % 2 == 0)
				must2[i/2 + new_magic] = true;
			else {
				if(abs((i - used) / 2) > new_magic) ok = false;
				else must2[(i-used)/2 + new_magic] = true;
			}
		}
		if(ok) {
			must2[new_magic] = false;
			rec(bit + 1, must2, new_magic);
		}
		so_far.pop_back();
	}
}

int main() {
	int n;
	scanf("%d", &n);
	const int magic = 256 * 1024;
	//~ const int magic = 256;
	vector<bool> must(2 * magic + 1);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		must[x+magic] = true;
	}
	rec(0, must, magic);
	printf("%d\n", (int) best.size());
	for(int x : best) printf("%d ", x);
	puts("");
}