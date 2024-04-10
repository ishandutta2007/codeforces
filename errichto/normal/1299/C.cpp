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
	vector<pair<double, int>> s;
	s.emplace_back(-1., 1);
	for(int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		double sum = value;
		int cnt = 1;
		// while(s.back().first / s.back().second > sum / cnt) {
		while(s.back().first * cnt > sum * s.back().second) {
			sum += s.back().first;
			cnt += s.back().second;
			s.pop_back();
		}
		s.emplace_back(sum, cnt);
	}
	for(int i = 1; i < (int) s.size(); ++i) {
		double sum = s[i].first;
		int cnt = s[i].second;
		double x = sum / cnt;
		for(int j = 0; j < cnt; ++j) {
			printf("%.10lf\n", x);
		}
	}
}