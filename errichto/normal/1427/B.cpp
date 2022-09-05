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

char s[1000123];

void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	assert(n == (int) strlen(s));
	vector<int> blocks;
	for(int i = 0; i < n; ++i) {
		bool good_start = (i > 0);
		if(s[i] == 'W') {
			continue;
		}
		int len = 1;
		while(i + 1 < n && s[i+1] == 'L') {
			len++;
			i++;
		}
		if(good_start && i != n - 1) {
			blocks.push_back(len);
		}
	}
	sort(blocks.begin(), blocks.end());
	int answer = 0;
	int remaining = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'W') {
			answer++;
		}
		else {
			remaining++;
		}
		if(s[i] == 'W' && i > 0 && s[i-1] == 'W') {
			answer++;
		}
	}
	if(remaining == n && k > 0) {
		answer--;
	}
	debug() << imie(answer) imie(remaining);
	for(int x : blocks) {
		if(k >= x) {
			k -= x;
			answer += 2 * x + 1;
			remaining -= x;
		}
		else {
			break;
		}
	}
	answer += 2 * min(k, remaining);// WLLWLLW
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}