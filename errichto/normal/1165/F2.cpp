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

using ll = long long;




int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> k(n);
	int sum_k = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &k[i]);
		sum_k += k[i];
	}
	vector<vector<int>> sales(n);
	// sales[i] is the list of days when the i-th product
	// 		is on sale
	while(m--) {
		int day, type;
		scanf("%d%d", &day, &type);
		assert(1 <= type && type <= n);
		sales[type-1].push_back(day - 1);
	}
	int low = 0, high = 2 * sum_k;
	while(low < high) {
		int duration = (low + high) / 2;
		vector<int> possible_sales(duration);
		for(int type = 0; type < n; ++type) {
			// look for the rightmost sale
			int big = -1;
			for(int day : sales[type]) {
				if(day < duration) {
					big = max(big, day);
				}
			}
			if(big != -1) {
				possible_sales[big] += k[type];
			}
		}
		int money = 0, saved = 0;
		for(int day = 0; day < duration; ++day) {
			money++;
			int use_here_on_sale = min(money, possible_sales[day]);
			money -= use_here_on_sale;
			saved += use_here_on_sale;
		}
		int total_money_needed = 2 * sum_k - saved;
		debug() << imie(duration) imie(saved) imie(total_money_needed);
		if(total_money_needed <= duration) {
			high = duration;
		}
		else {
			low = duration + 1;
		}
	}
	printf("%d\n", low);
}