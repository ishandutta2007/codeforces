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

const int nax = 1e5 + 5;
vector<int> edges[nax];
int degree[nax];
bool removed[nax];
int times[nax];

void NO() {
	puts("NO");
	exit(0);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	vector<int> q;
	for(int i = 1; i <= n; ++i) {
		if(degree[i] == 1) {
			q.push_back(i);
		}
	}
	for(int rep = 0; rep < k; ++rep) {
		for(int x : q) {
			removed[x] = true;
		}
		if(q.empty()) {
			NO();
		}
		set<int> must, can;
		for(int x : q) {
			for(int y : edges[x]) {
				if(!removed[y]) {
					++times[y];
					must.insert(y);
					if(--degree[y] == (rep == k - 1 ? 0 : 1)) {
						can.insert(y);
					}
				}
			}
		}
		if(must != can) {
			NO();
		}
		for(int x : must) {
			if(times[x] < 3) {
				NO();
			}
		}
		q.clear();
		for(int x : must) {
			q.push_back(x);
		}
	}
	vector<int> tmp;
	for(int i = 1; i <= n; ++i) {
		if(!removed[i]) {
			tmp.push_back(i);
		}
	}
	if((int) tmp.size() != 1) {
		NO();
	}
	puts("YES");
}