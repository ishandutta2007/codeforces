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



int main() {
	int n, INIT;
	scanf("%d%d", &n, &INIT);
	vector<int> a(n), b(n);
	for(int & x : a) scanf("%d", &x);
	for(int & x : b) scanf("%d", &x);
	a.push_back(a[0]);
	b.push_back(b[0]);
	double low = 0, high = 1e9 + 5;
	for(int rep = 0; rep < 50; ++rep) {
		double mid = (low + high) / 2;
		if(rep == 0) mid = 1;
		if(rep >= 1 && high > 1) mid = sqrt(low * high);
		//~ mid = 10;
		vector<double> dp(n + 1, -1);
		dp[0] = mid;
		for(int i = 0; i < n; ++i) if(dp[i] >= 0) {
			double W = INIT + dp[i];
			W -= W / a[i];
			for(int j = i + 1; j <= i + 1; ++j) if(j < n || i == n - 1) {
				double maybe = W - W / b[j];
				dp[j] = max(dp[j], maybe - INIT);
			}
		}
		debug() << imie(dp);
		if(dp[n] >= 0) high = mid;
		else low = mid;
	}
	double answer = (low + high) / 2;
	if(answer > 1e9 + 2) puts("-1");
	else printf("%.10lf\n", answer);
}