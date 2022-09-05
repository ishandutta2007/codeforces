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

const int nax = 2e5 + 5;
vector<pair<int,int>> edges[nax];
bitset<nax> B[10][10];
bool ok[10][10];
bool big_ok[10][10][10][10];
int k;
int answer;

void rec(vector<int> v) {
	if((int) v.size() == k) {
		debug() << imie(v);
		answer++;
		return;
	}
	int a = (int) v.size() + 1;
	for(int i = 0; i < a; ++i) {
		if(ok[a][i]) {
			bool bad = false;
			for(int b = 1; b < a; ++b) {
				if(!big_ok[a][i][b][v[b-1]]) {
					bad = true;
					break;
				}
			}
			if(!bad) {
				v.push_back(i);
				rec(v);
				v.pop_back();
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[a].emplace_back(w, b);
		// edges[b].emplace_back(w, a);
	}
	for(int a = 1; a <= n; ++a) {
		if(edges[a].empty()) {
			puts("0");
			return 0;
		}
		sort(edges[a].begin(), edges[a].end());
		debug() << imie(a) imie(edges[a]);
	}
	for(int out = 1; out <= k; ++out) {
		for(int i = 0; i < out; ++i) {
			ok[out][i] = true;
		}
	}
	for(int out = 1; out <= k; ++out) {
		for(int a = 1; a <= n; ++a) {
			if((int) edges[a].size() == out) {
				for(int i = 0; i < (int) edges[a].size(); ++i) {
					int b = edges[a][i].second;
					if(B[out][i][b]) {
						ok[out][i] = false;
					}
					B[out][i][b] = 1;
				}
			}
		}
	}
	for(int a = 1; a <= k; ++a) {
		for(int i = 0; i < a; ++i) {
			for(int b = a; b <= k; ++b) {
				for(int j = 0; j < b; ++j) {
					if((B[a][i] & B[b][j]) == 0) {
						big_ok[a][i][b][j] = big_ok[b][j][a][i] = true;
					}
				}
			}
		}
	}
	rec({});
	printf("%d\n", answer);
}