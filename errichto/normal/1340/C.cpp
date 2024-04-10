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

const int nax = 1e4 + 5;
const int INF = 1e9 + 5;
vector<pair<int,int>> dist[nax];
int inv[nax][1005];
// pairs (id, time%1000)

long long BIG_INF = 1e15 + 5;
long long answer = BIG_INF;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> they(m);
	for(int& x : they) {
		scanf("%d", &x);
	}
	int green, red;
	scanf("%d%d", &green, &red);
	sort(they.begin(), they.end());
	dist[0].emplace_back(0, 0);
	for(int id = 0; id <= m; ++id) {
		for(int t = 0; t < 1005; ++t) {
			inv[id][t] = INF;
		}
	}
	inv[0][0] = 0;
	for(int D = 0; D <= m; ++D) {
		for(int i = 0; i < (int) dist[D].size(); ++i) {
			pair<int,int> p = dist[D][i];
			int id = p.first;
			int time_remi = p.second;
			debug() << imie(id) imie(time_remi) imie(D);
			if(id == m - 1) {
				answer = min(answer, (long long) D * (red + green) + time_remi);
				// return 0;
			}
			if(inv[id][time_remi] != D) {
				continue;
			}
			for(int id2 : {id - 1, id + 1}) {
				if(0 <= id2 && id2 < m) {
					int time_remi2 = time_remi + abs(they[id] - they[id2]);
					if(time_remi2 > green) {
						continue;
					}
					int D2 = D;
					if(time_remi2 == green) {
						if(id2 == m - 1) {
							answer = min(answer, (long long) D * (red + green) + green);
						}
						D2++;
						time_remi2 = 0;
					}
					if(inv[id2][time_remi2] > D2) {
						inv[id2][time_remi2] = D2;
						dist[D2].emplace_back(id2, time_remi2);
					}
				}
			}
		}
	}
	if(answer == BIG_INF) {
		answer = -1;
	}
	printf("%lld\n", answer);
	// puts("-1");
	// Wrong answer #18
}