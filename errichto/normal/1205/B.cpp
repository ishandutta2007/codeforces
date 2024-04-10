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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> count_bits(60);
	vector<long long> in;
	while(n--) {
		long long x;
		cin >> x;
		if(x == 0) {
			continue;
		}
		in.push_back(x);
		for(int i = 0; i < 60; ++i) {
			if(x & (1LL << i)) {
				if(++count_bits[i] >= 3) {
					cout << "3\n";
					return 0;
				}
			}
		}
	}
	n = in.size();
	assert(n <= 120);
	vector<vector<int>> edges(n);
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(in[i] & in[j]) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	int shortest = INT_MAX;
	for(int start = 0; start < n; ++start) {
		// run BFS
		vector<int> dist(n, -1);
		vector<int> parent(n, -1);
		dist[start] = 0;
		vector<int> q{start};
		for(int i = 0; i < (int) q.size(); ++i) {
			int a = q[i];
			for(int b : edges[a]) {
				if(dist[b] == -1) {
					dist[b] = dist[a] + 1;
					parent[b] = a;
					q.push_back(b);
				}
				else if(b != parent[a]) {
					shortest = min(shortest, dist[a] + dist[b] + 1);
				}
			}
		}
	}
	if(shortest == INT_MAX) {
		shortest = -1;
	}
	cout << shortest << "\n";
}