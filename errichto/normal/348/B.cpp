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

const int nax = 1e5 + 5;
int cost[nax];
vector<int> edges[nax];
long long sum_all;

// (mul, value)
pair<int, long long> dfs(int a, int par) {
	bool is_leaf = true;
	for(int b : edges[a]) {
		if(b != par) {
			is_leaf = false;
		}
	}
	if(is_leaf) {
		return {1, cost[a]};
	}
	int mul = -1;
	vector<long long> values;
	for(int b : edges[a]) {
		if(b != par) {
			pair<int, long long> his = dfs(b, a);
			if(mul == -1) {
				mul = his.first;
			}
			else if(his.first != -1) {
				__int128 tmp = (__int128) his.first * mul / __gcd(his.first, mul);
				if(tmp > 1e13 * 1.0001) {
					printf("%lld\n", sum_all);
					exit(0);
				}
				mul = tmp;
			}
			values.push_back(his.second);
		}
	}
	assert(mul != -1);
	long long total_value = 0;
	long long small = -1;
	for(long long x : values) {
		x = x / mul * mul;
		if(small == -1 || x < small) {
			small = x;
		}
		// small = min(small, x);
	}
	assert(small != -1);
	total_value = small * (long long) values.size();
	if(total_value == 0) {
		printf("%lld\n", sum_all);
		exit(0);
	}
	debug() << imie(a) imie(mul) imie(total_value);
	long long tmp = (long long) mul * (long long) values.size();
	if(tmp > 1e9) {
		printf("%lld\n", sum_all);
		exit(0);
	}
	return {(long long) mul * values.size(), total_value};
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &cost[i]);
		sum_all += cost[i];
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	printf("%lld\n", sum_all - dfs(0, -1).second);
}