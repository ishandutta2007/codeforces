#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

typedef long long ll;

const int nax = 1505;
int dp[nax][nax];
const int inf = 1e9 + 5;

void maxi(int& a, int b) {
	a = max(a, b);
}

int main() {
	int n, cnt_seg, m, kth_value;
	scanf("%d%d%d%d", &n, &cnt_seg, &m, &kth_value);
	vector<int> in(n);
	for(int& x : in) {
		scanf("%d", &x);
	}
	vector<int> reach(n);
	for(int i = 0; i < n; ++i) {
		reach[i] = i + 1;
	}
	while(cnt_seg--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		for(int i = a; i <= b; ++i) {
			reach[i] = min(reach[i], a);
		}
	}
	vector<int> sorted = in;
	sort(sorted.begin(), sorted.end());
	sorted.resize( unique(sorted.begin(), sorted.end()) - sorted.begin() );
	int low = 0, high = (int) sorted.size();
	while(low < high) {
		int i_mid = (low + high) / 2;
		int up_to = sorted[i_mid];
		vector<int> pref(n);
		for(int i = 0; i < n; ++i) {
			if(i) {
				pref[i] = pref[i-1];
			}
			if(in[i] <= up_to) {
				++pref[i];
			}
		}
		auto interval = [&](int a, int b) {
			return pref[b] - (a == 0 ? 0 : pref[a-1]);
		};
		for(int i = 0; i <= max(n, m) + 1; ++i) {
			for(int j = 0; j <= max(n, m) + 1; ++j) {
				dp[i][j] = -inf;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j <= m; ++j) {
				maxi(dp[i+1][j], dp[i][j]);
				maxi(dp[i][j+1], dp[i][j]);
				maxi(dp[i+1][j+1], dp[i][j]);
			}
			if(reach[i] == i + 1) {
				continue;
			}
			for(int j = 0; j < m; ++j) {
				maxi(dp[i+1][j+1], dp[reach[i]][j] + interval(reach[i], i));
			}
		}
		if(dp[n][m] >= kth_value) {
			high = i_mid;
		}
		else {
			low = i_mid + 1;
		}
	}
	if(low == (int) sorted.size()) {
		puts("-1");
	}
	else {
		printf("%d\n", sorted[low]);
	}
}