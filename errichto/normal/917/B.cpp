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

const int nax = 105;
vector<pair<int,int>> w[nax];
int dp[nax][nax][26];

int rec(int a, int b, int at_least) {
	int & me = dp[a][b][at_least];
	if(me != -1) return me;
	
	me = 0;
	for(pair<int,int> edge : w[a])
		if(edge.second >= at_least)
			if(rec(b, edge.first, edge.second) == 0) {
				debug() << imie(a) imie(b) imie(at_least) " because " << edge.second;
				me = 1;
				break;
			}
	
	return me;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < 26; ++k)
				dp[i][j][k] = -1;
	for(int i = 0; i < m; ++i) {
		int a, b;
		char ch;
		scanf("%d%d %c", &a, &b, &ch);
		debug() << imie(a) imie(b) imie(ch);
		int val = ch - 'a';
		--a;
		--b;
		w[a].push_back({b, val});
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(rec(i, j, 0)) printf("A");
			else printf("B");
		}
		puts("");
	}
		//~ scanf(
		//~ scanf("%d%d %c", &a[i], &b[i], &ch[i]);
		//~ --a[i];
		//~ --b[i];
		//~ ++wych[a[i]];
		//~ inv[a[i]].push_back(i);
	//~ }
	
	
	
	//~ for(int rep = 0; rep < 105; ++rep)
		//~ for(int i = 0; i < m; ++i)
			//~ if(wych[b[i]] == 0) {
				//~ bool any_lost = false, any = false;
				//~ for(int j : inv[b[i]]) if(ch[j] >= ch[i]) {
					//~ any = true;
					//~ if(!win[j])
						//~ any_lost = true;
				//~ }
				//~ if(!any) win[i] = true;
				//~ else if(any_lost) win[i] = true;
				//~ else win[i] = false;
			//~ }
	//~ for(int i = 0; i < m; ++i)
		//~ if(win[i])
			//~ ans[an
}