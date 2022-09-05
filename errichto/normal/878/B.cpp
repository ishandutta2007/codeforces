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
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	int interior = 0;
	vector<pair<int,int>> t;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if(t.empty() || t.back().first != x)
			t.push_back({x, 1});
		else {
			t.back().second++;
			if(t.back().second == k) {
				t.pop_back();
				++interior;
			}
		}
	}
	vector<pair<int,int>> memo = t;
	int border = 0;
	int start = 0;
	while((int) t.size() - start >= 2 && t[start].first == t.back().first
			&& t[start].second + t.back().second >= k) {
		int tmp = t[start].second + t.back().second;
		border += tmp / k;
		tmp -= tmp / k * k;
		if(tmp == 0) {
			++start;
			t.pop_back();
		}
		else {
			t.pop_back();
			t[start].second = tmp;
		}
	}
	debug() << imie(interior) imie(border);
	long long answer = (long long) interior * m * k + (long long) border * (m - 1) * k;
	
	if((int) t.size() == start + 1) {
		long long a = (long long) m * t[start].second;
		answer += a / k * k;
		a -= a / k * k;
		if(a == 0) {
			debug() << "spec case";
			vector<pair<int,int>> nowy;
			for(int i = 0; i < start; ++i)
				nowy.push_back(memo[i]);
			for(int i = (int) t.size(); i < (int) memo.size(); ++i)
				nowy.push_back(memo[i]);
			debug() << imie(nowy);
			vector<pair<int,int>> dwa;
			for(pair<int,int> p : nowy) {
				if(dwa.empty() || dwa.back().first != p.first)
					dwa.push_back(p);
				else {
					dwa.back().second += p.second;
					answer += dwa.back().second / k * k;
					dwa.back().second %= k;
					if(dwa.back().second == 0)
						dwa.pop_back();
				}
			}
		}
	}
	printf("%lld\n", (long long) n * m - answer);
}