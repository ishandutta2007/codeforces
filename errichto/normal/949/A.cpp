#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

typedef long long ll;

const int nax = 2e5 + 5;
char sl[nax];
vector<int> indices[nax];
vector<int> zeros, ones;

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	int nxt = 0;
	for(int id = 1; id <= n; ++id) {
		char ch = sl[id-1];
		if(ch == '0') {
			if(!ones.empty()) {
				int x = ones.back();
				ones.pop_back();
				indices[x].push_back(id);
				zeros.push_back(x);
			}
			else {
				int x = ++nxt;
				indices[x].push_back(id);
				zeros.push_back(x);
			}
		}
		else {
			if(zeros.empty()) NO();
			int x = zeros.back();
			zeros.pop_back();
			indices[x].push_back(id);
			ones.push_back(x);
		}
	}
	if(!ones.empty()) NO();
	printf("%d\n", nxt);
	for(int i = 1; i <= nxt; ++i) {
		printf("%d", (int) indices[i].size());
		for(int x : indices[i]) printf(" %d", x);
		puts("");
	}
}