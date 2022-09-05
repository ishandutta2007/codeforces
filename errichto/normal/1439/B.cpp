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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct my_hash {
    const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + RANDOM);
    }
};
// gp_hash_table<int,int,my_hash> m;
void test_case() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<vector<int>> edges(n + 1);
	vector<gp_hash_table<int,int,my_hash>> mapka(n + 1);
	vector<int> degree(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
		mapka[a][b] = 1;
		mapka[b][a] = 1;
		++degree[a];
		++degree[b];
	}
	vector<bool> alive(n + 1, true);
	set<pair<int,int>> s;
	for(int i = 1; i <= n; ++i) {
		s.insert({degree[i], i});
	}
	// vector<int> when(n + 1);
	// int turn = 1;
	while(!s.empty()) {
		pair<int,int> p = *s.begin();
		s.erase(s.begin());
		int a = p.second;
		alive[a] = false;
		if(degree[a] >= k) {
			vector<int> vec;
			for(int i = 1; i <= n; ++i) {
				if(a == i || alive[i]) {
					vec.push_back(i);
				}
			}
			debug() << "high degrees";
			printf("%d %d\n", 1, (int) vec.size());
			for(int x : vec) printf("%d ", x);
			puts("");
			return;
		}
		if(degree[a] == k - 1) {
			// check for clique
			vector<int> clique{a};
			// ++turn;
			// when[a] = turn;
			for(int b : edges[a]) {
				if(alive[b]) {
					// when[b] = turn;
					clique.push_back(b);
				}
			}
			assert((int) clique.size() == k);
			bool ok = true;
			for(int i = 0; i < k && ok; ++i) {
				int x = clique[i];
				for(int j = i + 1; j < k; ++j) {
					if(mapka[x].find(clique[j]) == mapka[x].end()) {
						ok = false;
						break;
					}
				}
			}
			if(ok) {
				printf("%d\n", 2);
				for(int x : clique) printf("%d ", x);
				puts("");
				return;
			}
		}
		for(int b : edges[a]) {
			if(alive[b]) {
				s.erase({degree[b], b});
				--degree[b];
				s.insert({degree[b], b});
			}
		}
	}
	puts("-1");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}