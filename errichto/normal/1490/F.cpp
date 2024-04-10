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

void test_case() {
	int n;
	cin >> n;
	map<int,int> freq;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++freq[x];
	}
	// radix sort / count sort        O(N*log(N)) -> O(N+MAX_VALUE)
	vector<int> cnt(n + 1);
	for(pair<int,int> p : freq) {
		cnt[p.second]++;
	}
	vector<int> f;
	for(int value = 0; value <= n; ++value) {
		for(int j = 0; j < cnt[value]; ++j) {
			f.push_back(value);
		}
	}
	
	long long saved = 0;
	for(int i = 0; i < (int) f.size(); ++i) {
		saved = max(saved, (long long) f[i] * ((int) f.size() - i));
	}
	cout << n - saved << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}