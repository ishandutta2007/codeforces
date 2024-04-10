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
	int n, dist, b;
	scanf("%d%d%d", &n, &dist, &b);
	vector<int> t(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	const int last_left = (n - 1) / 2;
	
	int cnt_good = 0;
	int up_to = -1;
	int rem = 0;
	for(int i = 0; i <= last_left; ++i) {
		while(up_to + 1 < n && up_to + 1 <= i + (long long) dist * (i + 1)) {
			up_to++;
			rem += t[up_to];
		}
		if(rem >= b) {
			rem -= b;
			++cnt_good;
		}
	}
	
	int failed_left = last_left + 1 - cnt_good;
	debug() << imie(cnt_good) imie(failed_left);
	cnt_good = 0;
	up_to = n;
	rem = 0;
	for(int i = n - 1; i > last_left; --i) {
		while(up_to - 1 >= 0 && up_to - 1 >= i - (long long) dist * (n - i)) {
			up_to--;
			rem += t[up_to];
		}
		if(rem >= b) {
			rem -= b;
			++cnt_good;
		}
	}
	debug() << imie(cnt_good);
	int failed_right = n - 1 - last_left - cnt_good;
	printf("%d\n", max(failed_left, failed_right));
	
	//~ int low = 0, high = (n + 1) / 2;
	//~ while(low < high) {
		//~ int at_most_failed = (low + high) / 2;
		//~ int at_least_good = last_left + 1 - at_most_failed;
		
	//~ }
	//~ printf("%d\n", low);
}