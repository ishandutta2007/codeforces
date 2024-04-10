#include <bits/stdc++.h>
using namespace std;

const long double CHANGE = 1e-8;
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

const int nax = 2e5 + 5;
vector<int> w[nax];
int deg[nax]; // number of non-removed neighbours
bool removed[nax];
set<int> values[nax];

/*int trueDegree(int a) {
	assert(!removed[a]);
	return deg[a] + values[a].size();
}*/

void rec(int a) {
	if(removed[a] || (int) values[a].size() >= 2 || deg[a] != 1) return;
	int cnt = 0;
	for(int x : values[a]) cnt += x;
	do {
		++cnt;
		removed[a] = true;
		bool any = false;
		for(int b : w[a]) if(!removed[b]) {
			a = b;
			any = true;
			break;
		}
		assert(any);
		--deg[a];
	} while(deg[a] == 1 && values[a].empty());
	assert(cnt >= 1);
	debug() << imie(a) << imie(values[a]);
	/*if(values[a].count(cnt)) values[a].erase(cnt);
	else*/ values[a].insert(cnt);
	debug() << imie(a) << imie(values[a]) << "\n";
	rec(a);
}

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int rep = 0; rep < n - 1; ++rep) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i)
		deg[i] = w[i].size();
	for(int i = 1; i <= n; ++i) {
		debug() << "rec(" << imie(i) << ")";
		rec(i);
	}
	int who = -1;
	for(int i = 1; i <= n; ++i)
		if(!removed[i]) {
			if(who != -1) NO();
			who = i;
		}
	assert(who != -1);
	if((int) values[who].size() >= 3) NO();
	int len = 0;
	for(int x : values[who]) len += x;
	debug() << imie(len);
	while(len % 2 == 0) len /= 2;
	printf("%d\n", len);
}