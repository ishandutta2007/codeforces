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

const int mod = 998244353;

const int nax = 2005;
char sl[nax];
vector<pair<int,int>> w[nax];

void add_edge(int a, int b, int c) {
	w[a].emplace_back(b, c);
	w[b].emplace_back(a, c);
}

bool vis[nax];
int col[nax];
bool ok;
void dfs(int a) {
	assert(!vis[a]);
	vis[a] = true;
	for(const pair<int,int>& edge : w[a]) {
		int b = edge.first, type = edge.second;
		if(!vis[b]) {
			col[b] = col[a] ^ type;
			dfs(b);
		}
		else {
			if(col[b] != (col[a] ^ type)) {
				ok = false;
			}
		}
	}
}

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	if(n == 1) {
		puts("0");
		return 0;
	}
	int answer = 0;
	for(int n2 = 1; n2 < n; ++n2) {
		for(int i = 0; i < n; ++i) {
			int j = n - 1 - i;
			if(i < j) {
				add_edge(i, j, 0);
			}
		}
		for(int i = 0; i < n2; ++i) {
			int j = n2 - 1 - i;
			if(i < j) {
				add_edge(i + n, j + n, 0);
			}
		}
		for(int i = 0; i < n2; ++i) {
			char c = sl[n-1-i];
			if(c == '?') {
				continue;
			}
			add_edge(n - 1 - i, n2 - 1 - i + n, c == '1');
		}
		add_edge(0, n, 0); // both are 1
		for(int i = 0; i < n - n2; ++i) {
			if(sl[i] != '?') {
				add_edge(0, i, sl[i] == '0');
			}
		}
		
		ok = true;
		int cnt = 0;
		for(int i = 0; i < n + n2; ++i) {
			if(!vis[i]) {
				++cnt;
				dfs(i);
			}
		}
		cnt--;
		if(ok) {
			int tmp = 1;
			for(int rep = 0; rep < cnt; ++rep) {
				tmp *= 2;
				if(tmp >= mod) {
					tmp -= mod;
				}
			}
			answer += tmp;
			answer %= mod;
		}
		for(int i = 0; i < n + n2; ++i) {
			col[i] = 0;
			w[i].clear();
			vis[i] = false;
		}
	}
	printf("%d\n", answer);
}