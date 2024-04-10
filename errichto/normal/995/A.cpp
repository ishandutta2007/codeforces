#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

typedef long long ll;

const int nax = 105;
int in[4][nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &in[i][j]);
	vector<vector<int>> moves;
	vector<pair<int,int>> order;
	for(int i = 1; i <= 2; ++i) {
		for(int j = 0; j < n; ++j) {
			order.push_back({i, j});
			if(in[i][j] && in[i][j] == in[i^1][j]) {
				moves.push_back({in[i][j], i ^ 1, j});
				in[i][j] = 0;
			}
		}
	}
	reverse(order.begin() + order.size() / 2, order.end());
	//~ if(moves.empty()) {
		//~ puts("-1");
		//~ return 0;
	//~ }
	debug() << imie(order);
	int done = moves.size();
	while(done < k) {
		debug() << imie(done);
		for(int i = 0; i < 4; ++i)
			debug() << imie(i) << range(in[i], in[i] + n);
		debug();
		int fi = 0;
		while(fi < (int) order.size() && in[order[fi].first][order[fi].second]) ++fi;
		if(fi == (int) order.size()) {
			puts("-1");
			return 0;
		}
		bool hack = false;
		for(int ii = 0; ii < (int) order.size(); ++ii) {
			int i = (fi + ii) % (int) order.size();
			int j = (i + 1) % order.size();
			if(!in[order[i].first][order[i].second] && in[order[j].first][order[j].second]) {
				if(ii == 0) hack = true;
				if(ii == (int) order.size() - 1 && hack) continue;
				moves.push_back({in[order[j].first][order[j].second], order[i].first, order[i].second});
				swap(in[order[i].first][order[i].second], in[order[j].first][order[j].second]);
			}
		}
		for(int i = 1; i <= 2; ++i)
			for(int j = 0; j < n; ++j)
				if(in[i][j] && in[i][j] == in[i^1][j]) {
					moves.push_back({in[i][j], i ^ 1, j});
					++done;
					in[i][j] = 0;
				}
	}
	printf("%d\n", (int) moves.size());
	for(vector<int> w : moves) {
		printf("%d %d %d\n", w[0], w[1] + 1, w[2] + 1);
	}
}