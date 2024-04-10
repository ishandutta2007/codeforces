#pragma GCC optimize ("Ofast")
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

typedef long long ll;

const int nax = 4e6 + 5;
pair<pair<int,int>,int> memo[nax][2];
const int inf = 2e9 + 5;

int main() {
	int L, n1, n2, t;
	scanf("%d%d%d%d", &L, &n1, &n2, &t);
	vector<pair<int,int>> events;
	set<int> exists[2];
	for(int i = 0; i < n1; ++i) {
		int x;
		scanf("%d", &x);
		exists[0].insert(x);
		events.push_back({x, 0});
		events.push_back({x, 2});
		events.push_back({x+1, 2});
	}
	for(int i = 0; i < n2; ++i) {
		int x;
		scanf("%d", &x);
		exists[1].insert(x);
		events.push_back({x, 1});
		events.push_back({x, 2});
		events.push_back({x+1, 2});
	}
	sort(events.begin(), events.end());
	
	int when[2] = {t, t};
	pair<int,int> from[2];
	from[0] = {-1, 0};
	from[1] = {-1, 1};
	
	for(int i = 0; i < (int) events.size(); ++i) if(i == 0 || events[i] != events[i-1]) {
		int x = events[i].first;
		if(events[i].second == 2) {
			for(int a : {0, 1}) {
				int b = a ^ 1;
				if(exists[b].count(x)) continue;
				if(when[a] != inf) {
					int maybe = max(when[a], x);
					if(when[b] > maybe) {
						when[b] = maybe;
						memo[i][b] = {from[a], INT_MIN+x}; // move
						from[b] = {i, b};
					}
				}
			}
			continue;
		}
		int line = events[i].second;
		if(when[line] < x) {
			memo[i][line] = {from[line], when[line]}; //attack
			when[line] += t;
			from[line] = {i, line};
		}
		else when[line] = inf;
		debug() << imie(i) imie(x) imie(line) imie(when[line]);
	}
	if(when[0] == inf && when[1] == inf) {
		puts("No");
		return 0;
	}
	puts("Yes");
	pair<int,int> p;
	if(when[0] != inf) p = from[0];
	else p = from[1];
	vector<int> w;
	while(p.first != -1) {
		w.push_back(memo[p.first][p.second].second);
		p = memo[p.first][p.second].first;
	}
	if(p.second == 1) w.push_back(INT_MIN + 0);
	//~ cerr << "p.second = " << p.second << "\n";
	reverse(w.begin(), w.end());
	vector<int> changes;
	vector<pair<int,int>> shots;
	//~ for(int x : w) {
		//~ if(x < 0) printf("move %d\n", x - INT_MIN);
		//~ else printf("attack %d\n", x);
	//~ }
	int current_line = 0;
	for(int x : w) {
		if(x < 0) {
			changes.push_back(x - INT_MIN);
			current_line ^= 1;
		}
		else shots.push_back({x, current_line});
	}
	printf("%d\n", (int) changes.size());
	for(int x : changes) printf("%d ", x);
	puts("");
	printf("%d\n", (int) shots.size());
	for(pair<int,int> q : shots) printf("%d %d\n", q.first, q.second + 1);
}