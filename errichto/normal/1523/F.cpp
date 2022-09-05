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

int when[1<<14][101]; // mask, score
// int max_score[1<<14][101]; // mask, quest
bitset<101> yes[1<<14][101]; // mask, score, quest
const int INF = 1e9 + 5;

pair<int,int> towers[14];
pair<int,int> quests[101];
int needed[101];
int tt_dist[14][14];
int qt_dist[101][14];
int tq_dist[14][101];
int qq_dist[101][101];
int n, m;
int mask_dist[1<<14][101];
int tt_mask_dist[1<<14][14];
bitset<101> jumps_from[101];

void min_self(int& a, int b) {
	a = min(a, b);
}
void max_self(int& a, int b) {
	a = max(a, b);
}

int dist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void read() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &towers[i].first, &towers[i].second);
	}
	vector<vector<int>> order;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &quests[i].first, &quests[i].second, &needed[i]);
		order.push_back({needed[i], quests[i].first, quests[i].second});
	}
	sort(order.begin(), order.end());
	for(int i = 0; i < m; ++i) {
		needed[i] = order[i][0];
		quests[i].first = order[i][1];
		quests[i].second = order[i][2];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			tt_dist[i][j] = dist(towers[i], towers[j]);
		}
		for(int j = 0; j < m; ++j) {
			qt_dist[j][i] = tq_dist[i][j] = dist(towers[i], quests[j]);
		}
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < m; ++j) {
			qq_dist[i][j] = dist(quests[i], quests[j]);
		}
	}
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int q = 0; q < m; ++q) {
			mask_dist[mask][q] = INF;
			for(int t = 0;t < n; ++t) {
				if(mask & (1 << t)) {
					min_self(mask_dist[mask][q], qt_dist[q][t]);
				}
			}
		}
		for(int t = 0; t < n; ++t) {
			tt_mask_dist[mask][t] = INF;
			for(int t2 = 0; t2 < n; ++t2) {
				if(mask & (1 << t2)) {
					min_self(tt_mask_dist[mask][t], tt_dist[t][t2]);
				}
			}
		}
	}
	for(int q = 0; q < m; ++q) {
		for(int q2 = q + 1; q2 < m; ++q2) {
			if(needed[q] + qq_dist[q][q2] <= needed[q2]) {
				jumps_from[q][q2] = 1;
			}
		}
	}
}

int main() {
	read();
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int i = 0; i < 101; ++i) {
			when[mask][i] = INF;
		}
	}
	for(int t = 0; t < n; ++t) {
		when[1<<t][0] = 0;
	}
	for(int q = 0; q < m; ++q) {
		yes[0][1][q] = 1;
		// max_score[0][q] = 1;
	}
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int score = 0; score < m; ++score) {
			// quest -> activated tower (in the past)
			for(int q = 0; q < m; ++q) {
				if(yes[mask][score][q]) {
					min_self(when[mask][score], needed[q]);
					for(int t2 = 0; t2 < n; ++t2) {
						// quest -> not activated tower? (in the past)
						if(!(mask & (1 << t2))) {
							min_self(when[mask|(1<<t2)][score], needed[q] + qt_dist[q][t2]); // TODO, faster
						}
					}
				}
			}
			// quest -> quest
			for(int q = 0; q < m; ++q) {
				if(yes[mask][score][q]) {
					yes[mask][score+1] |= jumps_from[q];
				}
			}
			// tower -> tower
			for(int t = 0; t < n; ++t) {
				if(!(mask & (1 << t))) {
					min_self(when[mask|(1<<t)][score], when[mask][score] + tt_mask_dist[mask][t]);
				}
			}
			// tower -> quest
			for(int q = 0; q < m; ++q) {
				if(when[mask][score] + mask_dist[mask][q] <= needed[q]) {
					yes[mask][score+1][q] = true;
					// max_self(max_score[mask][q], score + 1);
				}
			}
		}
	}
	int answer = 0;
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int score = 0; score <= m; ++score) {
			for(int q = 0; q < m; ++q) {
				if(yes[mask][score][q]) {
					max_self(answer, score);
				}
			}
			// answer = max(answer, max_score[mask][q]);
		}
	}
	printf("%d\n", answer);
}