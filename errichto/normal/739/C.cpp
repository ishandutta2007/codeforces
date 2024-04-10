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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int inf = 1e9 + 5;
typedef long long ll;

void maxi(int & a, int b) {
	a = max(a, b);
}

struct Node {
	int left0, right0, left1, right1, left01, right01,
		full0, full1, full01, internal;
	void merge(const Node & a, const Node & b) {
		left0 = max(a.left0, a.full0 + b.left0);
		left1 = max(a.left1, a.full1 + b.left1);
		right0 = max(b.right0, a.right0 + b.full0);
		right1 = max(b.right1, a.right1 + b.full1);
		left01 = max({a.left01, a.full01 + b.left1, a.full0 + b.left01});
		right01 = max({b.right01, b.full01 + a.right0, b.full1 + a.right01});
		full0 = max(-inf, a.full0 + b.full0);
		full1 = max(-inf, a.full1 + b.full1);
		full01 = max({-inf, a.full0 + b.full01, a.full01 + b.full1});
		internal = max({a.internal, b.internal, a.right01 + b.left1, a.right0 + b.left01});
		maxi(left0, full0);
		maxi(right0, full0);
		maxi(left1, full1);
		maxi(right1, full1);
		maxi(left01, left0);
		maxi(right01, right1);
		maxi(full01, max(full0, full1));
		maxi(internal, max({left0,right0,left1,right1,left01,right01,full0,full1,full01}));
	}
	void cons(ll diff) {
		left0 = right0 = left1 = right1 = left01
				= right01 = full0 = full1 = full01 = -inf;
		internal = 0;
		if(diff > 0)
			left0 = right0 = left01 = right01 = full0 = full01 = internal = 1;
		if(diff < 0)
			left1 = right1 = right01 = left01 = full1 = full01 = internal = 1;
	}
};

const int pot = 512 * 1024;
Node tr[2*pot];
int init[pot], small[pot];
ll diff[pot];

void modify(int i, int by) {
	tr[pot+i].cons(diff[i] += by);
	for(int x = (pot + i) / 2; x >= 1; x /= 2)
		tr[x].merge(tr[2*x], tr[2*x+1]);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &init[i]);
	for(int i = 1; i <= n - 1; ++i)
		diff[i] = init[i+1] - init[i];
	for(int i = 0; i < pot; ++i)
		tr[pot+i].cons(diff[i]);
	for(int i = pot - 1; i >= 1; --i)
		tr[i].merge(tr[2*i], tr[2*i+1]);
	debug() << imie(tr[1].internal + 1);
	debug() << imie(tr[2].right0) << imie(tr[3].left1);
	int q;
	scanf("%d", &q);
	while(q--) {
		int low, high, by;
		scanf("%d%d%d", &low, &high, &by);
		if(low > 1) modify(low - 1, by);
		if(high < n) modify(high, -by);
		printf("%d\n", tr[1].internal + 1);
	}
}