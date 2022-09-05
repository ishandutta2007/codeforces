#include "bits/stdc++.h"
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

using ll = long long;

const int MAX_N = 5e5 + 5;
bool visited[MAX_N];
vector<int> group[MAX_N];
vector<int> his_groups[MAX_N];
bool done[MAX_N];
int answer[MAX_N];

vector<int> gather;

void dfs(int a) {
	gather.push_back(a);
	assert(!visited[a]);
	visited[a] = true;
	for(int g : his_groups[a]) {
		if(!done[g]) {
			done[g] = true;
			for(int b : group[g]) {
				if(!visited[b]) {
					dfs(b);
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			group[i].push_back(x);
			his_groups[x].push_back(i);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			dfs(i);
			for(int x : gather) {
				answer[x] = gather.size();
			}
			gather.clear();
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d ", answer[i]);
	}
	puts("");
}