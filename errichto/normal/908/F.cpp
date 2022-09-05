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

const int nax = 3e5 + 5;
int x[nax];
char type[nax];
int n;

int findFirst(char ch) {
	int i = 0;
	while(i < n && type[i] != ch) ++i;
	return i;
}
int findLast(char ch) {
	int i = n - 1;
	while(i >= 0 && type[i] != ch) --i;
	return i;
}
int findNext(char ch, int i) {
	while(i < n && type[i] != ch) ++i;
	return i;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %c", &x[i], &type[i]);
	int g = findFirst('G');
	if(g == n) {
		debug() << ">>>>>>>>> spec g == n";
		int answer = 0;
		for(char ch : {'R', 'B'}) {
			int a = findFirst(ch);
			if(a != n) answer += x[findLast(ch)] - x[a];
		}
		printf("%d\n", answer);
		return 0;
	}
	long long answer = 0;
	for(char ch : {'R', 'B'}) {
		int a = findFirst(ch);
		if(a < g)
			answer += x[g] - x[a];
	}
	//~ puts("x");
	while(true) {
		int g2 = findNext('G', g + 1);
		debug() << imie(g) imie(g2);
		if(g2 == n) break;
		
		vector<int> ple;
		for(char ch : {'R', 'B'}) {
			vector<int> w;
			for(int i = g; i <= g2; ++i) {
				if(type[i] != ch) w.push_back(x[i]);
			}
			assert((int) w.size() >= 2);
			if((int) w.size() == 2) ple.push_back(-1);
			else {
				int best = 0;
				for(int i = 0; i < (int) w.size() - 1; ++i)
					best = max(best, w[i+1] - w[i]);
				ple.push_back(best);
			}
		}
		assert((int) ple.size() == 2);
		sort(ple.begin(), ple.end());
		int LEN = x[g2] - x[g];
		debug() << imie(ple);
		if(ple[0] == -1) {
			answer += LEN;
			if(ple[1] != -1)
				answer += LEN - ple[1];
		}
		else {
			int one = 3 * LEN - ple[0] - ple[1];
			int two = 2 * LEN;
			answer += min(one, two);
		}
		
		g = g2;
	}
	for(char ch : {'R', 'B'}) {
		int a = findLast(ch);
		if(a > g)
			answer += x[a] - x[g];
	}
	
	printf("%lld\n", answer);
}