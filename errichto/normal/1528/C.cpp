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

const int nax = 6e5 + 5;
vector<int> one[nax], two[nax];
int in[nax], out[nax];

int nxt = 0;
void dfs_two(int a, int parent) {
	// debug() << "two" imie(a) imie(parent);
	in[a] = nxt;
	nxt++;
	for(int b : two[a]) {
		if(b != parent) {
			dfs_two(b, a);
		}
	}
	out[a] = nxt;
	nxt++;
}

set<pair<int,int>> s;

bool contains(const pair<int,int>& a, const pair<int,int>& b) {
	return a.first <= b.first && b.second <= a.second;
}
int answer;

void dfs_one(int a, int parent) {
	// debug() << "one" imie(a) imie(parent);
	pair<int,int> me = {in[a], out[a]};
	bool bad = false;
	pair<int,int> to_remove{-1, -1};
	auto it = s.lower_bound(make_pair(in[a], INT_MIN));
	if(it != s.end() && contains(me, *it)) {
		bad = true;
	}
	if(it != s.begin() && contains(*prev(it), me)) {
		to_remove = *prev(it);
	}
	// for(pair<int,int> p : s) {
		// if(contains(me, p)) {
			// bad = true;
			// break;
		// }
		// if(contains(p, me)) {
			// to_remove = p;
		// }
	// }
	if(!bad) {
		if(to_remove.first != -1) {
			s.erase(to_remove);
		}
		s.insert(me);
		answer = max(answer, (int) s.size());
	}
	for(int b : one[a]) {
		if(b != parent) {
			dfs_one(b, a);
		}
	}
	if(!bad) {
		if(to_remove.first != -1) {
			s.insert(to_remove);
		}
		s.erase(me);
	}
}

void test_case() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		one[x].push_back(i);
	}
	for(int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		two[x].push_back(i);
	}
	
	// for(int i = 0; i < n - 1; ++i) {
		// int a, b;
		// scanf("%d%d", &a, &b);
		// one[a].push_back(b);
		// one[b].push_back(a);
	// }
	// for(int i = 0; i < n - 1; ++i) {
		// int a, b;
		// scanf("%d%d", &a, &b);
		// two[a].push_back(b);
		// two[b].push_back(a);
	// }
	dfs_two(1, -1);
	dfs_one(1, -1);
	
	printf("%d\n", answer);
	assert(s.empty());
	
	for(int i = 0; i <= n; ++i) {
		one[i].clear();
		two[i].clear();
	}
	nxt = 0;
	answer = 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}