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

const int inf = 1e9 + 5;
const int nax = 105;
int t[nax][nax];
int row[nax], col[nax];

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
			scanf("%d", &t[i][j]);
	int small = inf;
	for(int i = 1; i <= h; ++i)
		small = min(small, t[i][1]);
	for(int i = 1; i <= h; ++i) {
		int tmp = t[i][1] - small;
		row[i] = tmp;
		for(int j = 1; j <= w; ++j)
			t[i][j] -= tmp;
	}
	small = inf;
	for(int j = 1; j <= w; ++j)
		small = min(small, t[1][j]);
	for(int j = 1; j <= w; ++j) {
		int tmp = t[1][j] - small;
		col[j] = tmp;
		for(int i = 1; i <= h; ++i)
			t[i][j] -= tmp;
	}
	int all = t[1][1];
	debug() << "a";
	if(all < 0) NO();
	debug() << "b";
	for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j)
			if(t[i][j] != all) NO();
	if(h >= w) for(int j = 1; j <= w; ++j) col[j] += all;
	else for(int i = 1; i <= h; ++i) row[i] += all;
	int s = 0;
	for(int i = 1; i <= h; ++i) s += row[i];
	for(int j = 1; j <= w; ++j) s += col[j];
	printf("%d\n", s);
	for(int i = 1; i <= h; ++i) for(int r = 0; r < row[i]; ++r) printf("row %d\n", i);
	for(int j = 1; j <= w; ++j) for(int r = 0; r < col[j]; ++r) printf("col %d\n", j);
}