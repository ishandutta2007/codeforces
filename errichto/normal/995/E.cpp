#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;

#define set unordered_set

int mod;
int mul(int a, int b) { return (ll) a * b % mod; }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }

void gen(int start, set<int> & B, vector<pair<int,int>> & w) {
	B.reserve(10123123);
	w.push_back({start, -3});
	for(int i = 0; i < (int) w.size() && (int) w.size() <= 2000 * 1000; ++i) {
		//~ debug() << imie(w);
		int x = w[i].first;
		for(int y : {(x + 1) % mod, (x + mod - 1) % mod, my_inv(x)})
			if(!B.count(y)) {
				B.insert(y);
				w.push_back({y, x});
			}
	}
	debug() << imie(w);
}

vector<int> go(vector<pair<int,int>> & w, int A, int B) {
	vector<int> r;
	sort(w.begin(), w.end());
	while(A != B) {
		int i = lower_bound(w.begin(), w.end(), make_pair(B, -5)) - w.begin();
		int prv = w[i].second;
		if((prv + 1) % mod == B) r.push_back(1);
		else if((prv + mod - 1) % mod == B) r.push_back(2);
		else r.push_back(3);
		B = prv;
	}
	reverse(r.begin(), r.end());
	return r;
}

int main() {
	int A, B;
	scanf("%d%d%d", &A, &B, &mod);
	debug() << imie(my_inv(3));
	set<int> one, two;//<nax> one = 0, two = 0;
	vector<pair<int,int>> L, R;
	gen(A, one, L);
	gen(B, two, R);
	for(pair<int,int> p : L) {
		//~ assert(one[p.first]);
		if(two.count(p.first)) {//[p.first]) {
			vector<int> a = go(L, A, p.first);
			vector<int> b = go(R, B, p.first);
			reverse(b.begin(), b.end());
			debug() << imie(p.first) imie(a) imie(b);
			for(int & x : b) {
				if(x == 1) x = 2;
				else if(x == 2) x = 1;
			}
			for(int  x: b) a.push_back(x);
			printf("%d\n", (int) a.size());
			for(int x : a) printf("%d ", x);
			puts("");
			return 0;
		}
	}
	assert(false);
}