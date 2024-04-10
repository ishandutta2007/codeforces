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

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	// long long answer = 0;
	vector<vector<int>> answer(n);
	for(int rep = 0; rep < m; ++rep) {
		int v = INT_MAX;
		pair<int,int> smallest{-1, -1};
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(a[i][j] < v) {
					v = a[i][j];
					smallest = {i, j};
				}
			}
		}
		// answer += v;
		a[smallest.first][smallest.second] = INT_MAX;
		vector<int> path;
		for(int i = 0; i < n; ++i) {
			if(i != smallest.first) {
				int big = -1;
				for(int j = 0; j < m; ++j) {
					if(a[i][j] != INT_MAX && (big == -1 || a[i][j] > a[i][big])) {
						big = j;
					}
				}
				assert(big != -1);
				path.push_back(a[i][big]);
				a[i][big] = INT_MAX;
			}
			else {
				path.push_back(v);
			}
			answer[i].push_back(path.back());
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int x : answer[i]) {
			printf("%d ", x);
		}
		puts("");
	}
	// printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}