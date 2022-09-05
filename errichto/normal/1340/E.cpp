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

const int nax = 15123;
const int INF = 1e9 + 5;
vector<pair<int,int>> edges[nax];

int kol[nax];

vector<int> path[3];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edges[a].emplace_back(b, i);
		edges[b].emplace_back(a, i);
	}
	// vector<int> me{1, 2, 3};
	
	vector<int> me;
	srand(6969);
	me.push_back(1 + rand() % n);
	for(int rep = 0; rep < 2; ++rep) {
		vector<int> dist(n + 1, INF);
		int kol_size = 0;
		for(int x : me) {
			kol[kol_size++] = x;
			dist[x] = 0;
		}
		for(int i = 0; i < kol_size; ++i) {
			int a = kol[i];
			for(const pair<int,int>& edge : edges[a]) {
				int b = edge.first;
				if(dist[b] == INF) {
					dist[b] = dist[a] + 1;
					kol[kol_size++] = b;
				}
			}
		}
		int best = -1;
		for(int a = 1; a <= n; ++a) {
			if(best == -1 || dist[a] > dist[best]) {
				best = a;
			}
		}
		assert(best != -1);
		me.push_back(best);
	}
	
	
	
	
	
	cout << me[0] << " " << me[1] << " " << me[2] << endl;
	int enemy;
	cin >> enemy;
	auto is_done = [&]() {
		return me[0] == enemy || me[1] == enemy || me[2] == enemy;
	};
	vector<int> used(m + 1);
	for(int turn = 1; turn <= (n >= 100 ? n - 1 : n); ++turn) {
		// cout << me[0] << " " << me[1] << " " << me[2] << endl;
		// continue;
		cerr << "turn = " << turn << endl;
		if(is_done()) {
			return 0;
		}
		
		
		vector<int> dist(n + 1, INF);
		
		
		// for(int& x : dist) {
			// x = INF;
		// }
		{
			int kol_size = 0;
			kol[kol_size++] = enemy;
			dist[enemy] = 0;
			for(int i = 0; i < kol_size && (dist[me[0]] == INF || dist[me[1]] == INF || dist[me[2]] == INF); ++i) {
				int a = kol[i];
				for(const pair<int,int>& edge : edges[a]) {
					int b = edge.first;
					if(dist[b] == INF) {
						dist[b] = dist[a] + 1;
						kol[kol_size++] = b;
					}
				}
			}
		}
		vector<int> order{0, 1, 2};
		sort(order.begin(), order.end(), [&](int a, int b) {
			return dist[a] < dist[b];
		});
		
		
		int tu_turn = -1;
		for(int which : order) {
			int& start = me[which];
			if(rand() % 10 == 0 && n >= 100) {
				start = edges[start][rand()%edges[start].size()].first;
				continue;
			}
			tu_turn++;
			// if((int) path[which].size() >= 9) {
				// int nxt = path[which][0];
				// path[which].erase(path[which].begin());
				// start = nxt;
				// continue;
			// }
			// path[which].clear();
			for(int rep = 0; rep < 2; ++rep) {
				// bfs dijkstra
				if(tu_turn != 0) {
					for(int& x : dist) {
						x = INF;
					}
					int kol_size = 0;
					kol[kol_size++] = enemy;
					dist[enemy] = 0;
					for(int i = 0; i < kol_size && dist[start] == INF; ++i) {
						int a = kol[i];
						for(const pair<int,int>& edge : edges[a]) {
							int b = edge.first;
							int id = edge.second;
							if((rep == 1 || used[id]!=turn) && dist[b] == INF) {
								dist[b] = dist[a] + 1;
								kol[kol_size++] = b;
							}
						}
					}
				}
				// bool can_fill = true;
				// for(int wh : {0, 1, 2}) {
					// if(!path[wh].empty()) {
						// can_fill = false;
					// }
				// }
				if(dist[start] != INF) {
					int tmp = start;
					int first_move = -1;
					while(tmp != enemy) {
						if(which == 2 && first_move != -1) {
							break;
						}
						// for(int rep = 0; rep < 2; ++rep) {
							bool done = false;
							debug();
							for(const pair<int,int>& e : edges[tmp]) {
								int b = e.first;
								int id = e.second;
								debug() << imie(rep) imie(b) imie(id) imie(used[id]) imie(dist[b]) imie(dist[tmp]);
								if(rep == 0 && used[id]==turn) {
									continue;
								}
								if(dist[b] + 1 == dist[tmp]) {
									used[id] = turn;
									tmp = b;
									if(first_move == -1) {
										first_move = b;
									}
									else {
										// if(can_fill && tu_turn == 2 && (int) path[which].size() <= 15) path[which].push_back(b);
									}
									done = true;
									break;
								}
							}
							assert(done);
							// if(done) {
								// break;
							// }
							// assert(rep != 1);
						// }
					}
					assert(first_move != -1);
					start = first_move;
					break;
				}
				assert(rep != 1); // no path :( :( :(
			}
		}
		cout << me[0] << " " << me[1] << " " << me[2] << endl;
		
		if(is_done()) {
			return 0;
		}
		cin >> enemy;
		// enemy = edges[enemy][rand()%edges[enemy].size()].first;
		if(is_done()) {
			return 0;
		}
	}
	assert(false); // :((((
}