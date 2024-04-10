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
	vector<int> a(n);
	int big = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		big = max(big, a[i]);
	}
	// 100 * 2e5 = 20 * 1e6 = 80MB * 2 = 160MB
	vector<vector<pair<int,int>>> when(big + 1, vector<pair<int,int>>(n + 1));
	int answer = 0;
	for(int x = 1; x <= big; ++x) {
		int cnt_max = 0, max_freq = 0, who_max = 0; // cnt_max is wrong
		vector<int> freq(big + 1);
		for(int i = 0; i < n; ++i) {
			int here = a[i];
			freq[here]++;
			if(freq[here] > max_freq) {
				max_freq = freq[here];
				cnt_max = 1;
				who_max = here;
			}
			else if(freq[here] == max_freq) {
				cnt_max++;
			}
			if(cnt_max >= 2) {
				answer = max(answer, i + 1);
			}
			if(cnt_max == 1 && who_max == x) {
				for(int y = 1; y <= big; ++y) {
					if(x == y) {
						continue;
					}
					if(x == 2 && i == 4 && y == 1) {
						debug() << "x";
					}
					int diff = freq[x] - freq[y];
					assert(diff > 0);
					// when first time same thing happened?
					pair<int,int> p = when[y][diff];
					if(p.first != x) {
						continue;
					}
					answer = max(answer, i - p.second);
				}
			}
			for(int y = 1; y <= big; ++y) {
				if((a[i] == x || a[i] == y) && freq[x] > freq[y]) {
					pair<int,int>& p = when[y][freq[x]-freq[y]];
					if(p.first != x) {
						p = {x, i};
					}
					// when[y][freq[x]-freq[y]] = {x, i};
				}
			}
		}
	}
	printf("%d\n", answer);
}