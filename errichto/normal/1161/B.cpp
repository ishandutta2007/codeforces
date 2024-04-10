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
	vector<pair<int,int>> they(m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		int dist = b - a;
		if(dist < 0) {
			dist += n;
		}
		if(dist > n / 2) {
			dist = n - dist;
			swap(a, b);
		}
		they[i] = {a, dist};
		if(2 * dist == n) {
			they.push_back({b, dist});
		}
		//~ scanf("%d%d", &they[i].first, &they[i].second);
		//~ int tmp = they[i].second - they[i].first;
		//~ if(tmp < 0) {
			//~ tmp += n;
		//~ }
		//~ if(
		//~ they[i].second -= they[i].first;
		//~ if(they[i].second < 0) {
			//~ they[i].second += n;
		//~ }
		
	}
	sort(they.begin(), they.end());
	they.resize( unique(they.begin(), they.end()) - they.begin() );
	m = they.size();
	int z = 0;
	debug() << imie(they);
	for(int k = 1; k < n; ++k) {
		if(n % k == 0) {
			while(z < m && they[0].first + k > they[z].first) {
				++z;
			}
			if(z < m) {
				debug() << imie(k) imie(z);
				bool ok = true;
				for(int i = 0; i < m - z; ++i) {
					int j = i + z;
					if(they[i].first + k != they[j].first || they[i].second != they[j].second) {
						ok = false;
						break;
					}
				}
				for(int i = m - z; i < m; ++i) {
					int j = i + z - m;
					if(they[i].first + k - n != they[j].first || they[i].second != they[j].second) {
						ok = false;
						break;
					}
				}
				if(ok) {
					puts("Yes");
					return 0;
				}
					
			}
		}
	}
	puts("No");
}