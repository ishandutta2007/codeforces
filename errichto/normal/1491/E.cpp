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
vector<int> edges[nax];
vector<int> fib{1, 1};
int subtree[nax];
bool forbidden[nax];
vector<pair<int,int>> gather;

using ull = unsigned long long;
ull his[nax];

ull dfs_subtree(int a, int parent, int goal = -1) {
	subtree[a] = 1;
	ull total_hasz = his[a];
	for(int b : edges[a]) {
		if(b != parent && !forbidden[b]) {
			total_hasz ^= dfs_subtree(b, a, goal);
			if(subtree[b] == goal) {
				gather.emplace_back(a, b);
			}
			subtree[a] += subtree[b];
		}
	}
	return total_hasz;
}

long long all;
map<ull, bool> memo[105];
bool rec(int a, int i_fib) {
	debug() << imie(a) imie(i_fib);
	int n = fib[i_fib];
	all += n;
	debug() << imie(all);
	debug() << "rec" imie(a) imie(n);
	if(n <= 3) {
		return true;
	}
	ull hasz = dfs_subtree(a, -1);
	auto it = memo[i_fib].find(hasz);
	if(it != memo[i_fib].end()) {
		return it->second;
	}
	while(true) {
		bool any = false;
		for(int b : edges[a]) {
			if(!forbidden[b] && subtree[b] < subtree[a] && subtree[b] >= (n + 1) / 2) {
				a = b;
				any = true;
				break;
			}
		}
		if(!any) {
			break;
		}
	}
	debug() << "centroid = " imie(a);
	// 13 -> subtrees of size 5
	dfs_subtree(a, -1, fib[i_fib-2]);
	// for(int i = 1; i <= n; ++i) {
		
	vector<pair<int,int>> candidates = gather;
	gather.clear();
	debug() << imie(candidates);
	assert((int) candidates.size() <= 2);
	random_shuffle(candidates.begin(), candidates.end());
	for(pair<int,int> edge : candidates) {
		int parent = edge.first;
		int child = edge.second;
		int S_PAR = i_fib-1;
		int S_CHILD = i_fib-2;
		if(rand() % 2) {
			swap(parent, child);
			swap(S_PAR, S_CHILD);
		}
		forbidden[child] = true;
		bool one = rec(parent, S_PAR);
		forbidden[child] = false;
		if(!one) {
			continue;
		}
		forbidden[parent] = true;
		bool two = rec(child, S_CHILD);
		forbidden[parent] = false;
		if(one && two) {
			return memo[i_fib][hasz] = true;
		}
	}
	return memo[i_fib][hasz] = false;
}

void NO() {
	puts("NO");
	cerr << imie(all) << endl;
	exit(0);
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<unsigned long long> distrib(0ULL, (ull) -1);
    // cout << distrib(rng) << endl;
    // return 0;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		his[i] = distrib(rng);
	}
	while(fib.back() < n) {
		fib.push_back(fib.back() + fib.end()[-2]);
	}
	debug() << imie(fib);
	if(fib.back() != n) {
		NO();
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int a = 1; a <= n; ++a) {
		if(edges[a].size() > fib.size()) {
			NO();
		}
	}
	debug() << "running...";
	bool answer = rec(1, (int) fib.size() - 1);
	puts(answer ? "YES" : "NO");
	cerr << imie(all) << endl;
}