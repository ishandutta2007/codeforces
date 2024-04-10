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



int main() {
	int n, allowed;
	scanf("%d%d", &n, &allowed);
	vector<pair<int,pair<int,int>>> in(n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		in[i] = {a, {b, i + 1}};
	}
	//~ for(pair<int,pair<int,int>> & p)
		//~ scanf("%d%d", &p.first, &p.second);
	
	sort(in.rbegin(), in.rend());
	multiset<pair<int,int>> secik;
	int current = 0;
	int nxt = 0;
	for(int k = n; k >= 1; --k) {
		while(nxt < (int) in.size() && in[nxt].first == k) {
			current += in[nxt].second.first;
			secik.insert(in[nxt++].second);
		}
		while((int) secik.size() > k) {
			auto it = secik.end();
			--it;
			current -= it -> first;
			secik.erase(it);
		}
		if((int) secik.size() == k && current <= allowed) {
			printf("%d\n", k);
			printf("%d\n", k);
			for(pair<int,int> p : secik) printf("%d ", p.second);
			puts("");
			return 0;
		}
	}
	puts("0");
	puts("0");
	puts("");
}