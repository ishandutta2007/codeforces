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
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int,int>>> edges(n);
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[a].emplace_back(b, c);
	}
	for(int start = 0; start < n; ++start) {
		int must = INT_MAX;
		for(pair<int,int> e : edges[start]) {
			must = min(must, e.second);
		}
		must--;
		while(must % n != 0) {
			must--;
		}
		for(pair<int,int>& e : edges[start]) {
			e.second -= must;
		}
		// vector<vector<bool>> is(n, vector<bool>(n + 1));
		vector<int> dist(n, 2 * n + 1);
		dist[start] = 0;
		// for(int i = 0; i < n; ++i) {
			// is[i][dist[i]] = true;
		// }
		for(int d = 0; d <= 2 * n; ++d) {
			for(int a = 0; a < n; ++a) {
				if(dist[a] == d) {
					debug() << imie(start) imie(a) imie(d);
					if(d != 0) {
						dist[(a+1)%n] = min(dist[(a+1)%n], d + 1);
					}
					for(const pair<int,int>& e : edges[a]) {
						int b = e.first + d;
						while(b >= n) {
							b -= n;
						}
						debug() << "> " imie(b) imie(d+e.second);
						if(a == b) {
							b++;
							if(b == n) {
								b = 0;
							}
							dist[b] = min(dist[b], d + 1 + e.second);
						}
						else {
							dist[b] = min(dist[b], d + e.second);
						}
					}
				}
			}
			if(d == 0) {
				dist[start] = 2 * n;
			}
		}
			// for(int a : q[d]) {
				// if(dist[a] == d) {
					
				// }
			// }
		// }
		
		// debug() << imie(must);
		for(int j = 0; j < n; ++j) {
			if(start == j) {
				printf("%d ", 0);
			}
			else {
				printf("%d ", must + dist[j]);
			}
		}
		puts("");
		for(pair<int,int>& e : edges[start]) {
			e.second += must;
		}
	}
}