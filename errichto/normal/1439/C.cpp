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

struct Node {
	//    big        small
	int leftmost = 0, rightmost = 0, lazy_max = 0, cnt = 0;
	long long sum = 0;
	void make_eq(int x) {
		assert(x >= leftmost);
		assert(x >= lazy_max);
		leftmost = rightmost = lazy_max = x;
		sum = (long long) cnt * x;
	}
	void init(int x) {
		cnt = 1;
		leftmost = rightmost = sum = x;
	}
	void merge(const Node& left, const Node& right) {
		leftmost = left.leftmost;
		rightmost = right.rightmost;
		cnt = left.cnt + right.cnt;
		sum = left.sum + right.sum;
	}
};
vector<Node> tree;

int money, meals;
int base;
void rec(int id, int low, int high, int q_low, int q_high, int max_with) {
	if(high < q_low || q_high < low) {
		return;
	}
	if(tree[id].cnt == 0) {
		return;
	}
	// push
	if(id < base && tree[id].lazy_max) {
		tree[2*id].make_eq(tree[id].lazy_max);
		tree[2*id+1].make_eq(tree[id].lazy_max);
		tree[id].lazy_max = 0;
	}
	if(q_low <= low && high <= q_high) {
		// debug() << imie(id);
		if(max_with >= 1) { // maximizing
			if(max_with <= tree[id].rightmost) {
				return;
			}
			if(max_with >= tree[id].leftmost) {
				tree[id].make_eq(max_with);
				return;
			}
			// go resursively and pass this max_with
		}
		else {
			if(money < tree[id].rightmost) {
				debug() << imie(id) "can't afford";
				return; // can't afford
			}
			if(money >= tree[id].sum) {
				debug() << imie(id) imie(money) imie(tree[id].sum) imie(tree[id].cnt);
				meals += tree[id].cnt;
				money -= tree[id].sum;
				return;
			}
			// go resursively, left first
		}
	}
	if(id >= base) {
		return;
	}
	int last_left = (low + high) / 2;
	rec(2 * id, low, last_left, q_low, q_high, max_with);
	rec(2 * id + 1, last_left + 1, high, q_low, q_high, max_with);
	tree[id].merge(tree[2*id], tree[2*id+1]);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	base = 1;
	while(base < n) {
		base *= 2;
	}
	tree.resize(2 * base);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		tree[base+i].init(x);
	}
	for(int i = base - 1; i >= 1; --i) {
		tree[i].merge(tree[2*i], tree[2*i+1]);
	}
	while(q--) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if(type == 1) {
			rec(1, 0, base - 1, 0, x - 1, y);
		}
		else {
			money = y;
			meals = 0;
			rec(1, 0, base - 1, x - 1, base - 1, 0);
			printf("%d\n", meals);
		}
	}
}