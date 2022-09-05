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

const int nax = 2e5 + 5;
int in[12][nax];

int type[nax], x[nax], y[nax];
bool yes[nax];
int he[nax][13];
int answer[nax];
const int inf = 1e9 + 5;

int main() {
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 0; i < k; ++i)
		for(int j = 0; j < n; ++j) {
			in[i][j] = rand() % (1000 * 1000 * 1000);
			scanf("%d", &in[i][j]);
		}
	for(int i = 0; i < q; ++i) {
		type[i] = 1 + rand() % 3;
		y[i] = rand() % 5 + 1;
		x[i] = rand() % 5 + 1;
		scanf("%d%d%d", &type[i], &x[i], &y[i]);
		--x[i];
		--y[i];
		if(type[i] == 3) {
			answer[i] = inf;
			vector<pair<int,int>> they;
			for(int j = 0; j < k; ++j)
				they.push_back({in[j][y[i]], j});
			sort(they.begin(), they.end());
			int tmp_mask = (1 << k) - 1;
			he[i][k] = tmp_mask;
			for(int j = 0; j < k; ++j) {
				tmp_mask ^= (1 << they[j].second);
				he[i][k-j-1] = tmp_mask;
			}
			assert(tmp_mask == 0);
		}
	}
	for(int mask = 0; mask < (1 << k); ++mask) {
		const int pc = __builtin_popcount(mask);
		for(int i = 0; i < k; ++i)
			yes[i] = bool(mask & (1 << i));
		int cnt = k;
		for(int i = 0; i < q; ++i) {
			if(type[i] == 1) yes[cnt++] = yes[x[i]] || yes[y[i]];
			else if(type[i] == 2) yes[cnt++] = yes[x[i]] && yes[y[i]];
			else if(type[i] == 3) {
				if(yes[x[i]] && he[i][pc] == mask)
					answer[i] = min(answer[i], pc);
			}
			else assert(false);
		}
	}
	for(int i = 0; i < q; ++i) if(type[i] == 3) {
		debug() << imie(i) imie(answer[i]);
		int mask = he[i][answer[i]];
		int small = inf;
		for(int j = 0; j < k; ++j)
			if(mask & (1 << j)) {
				debug() << ">>> " imie(j) imie(y[i]) imie(in[j][y[i]]);
				small = min(small, in[j][y[i]]);
			}
		printf("%d\n", small);
	}
}