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
	int n, k, given;
	scanf("%d%d%d", &n, &k, &given);
	vector<int> cnt(1024, 0);
	vector<int> tmp(1024, 0);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}
	while(k--) {
		fill(tmp.begin(), tmp.end(), 0);
		int par = 0;
		for(int i = 0; i < 1024; ++i) {
			int move = (cnt[i] + 1 - par) / 2;
			tmp[i^given] += move;
			tmp[i] += cnt[i] - move;
			par ^= cnt[i] % 2;
		}
		swap(cnt, tmp);
	}
	for(int i = 1023; i >= 0; --i)
		if(cnt[i]) {
			printf("%d ", i);
			break;
		}
	for(int i = 0; i < 1024; ++i)
		if(cnt[i]) {
			printf("%d\n", i);
			return 0;
		}
	assert(false);
	/*vector<int> w(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &w[i]);
	sort(w.begin(), w.end());
	vector<int> small, big;
	for(int a : w) {
		if(a / 1024 == w[0] / 1024)
			small.push_back(a);
		else if(a / 1024 == w.back() / 1024)
			big.push_back(a);
	}
	vector<int> ans;
	for(int turn = 0; turn < 2; ++turn) {
		vector<int> vec;
		int smaller = 0;
		if(turn == 0) vec = small;
		else {
			vec = big;
			smaller = n - (int) vec.size();
		}
		for(int rep = 0; rep < k; ++rep) {
			sort(vec.begin(), vec.end());
			for(int i = smaller % 2; i < (int) vec.size(); i += 2)
				vec[i] ^= given;
		}
		for(int a : vec) ans.push_back(a);
	}
	sort(ans.begin(), ans.end());
	printf("%d %d\n", ans.back(), ans[0]);*/
}