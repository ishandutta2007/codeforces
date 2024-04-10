#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 400 + 5;
int n, m;
int G[maxN][maxN];

struct Status {
	int train, bus;
	int t;
	Status(int tr, int bu, int t) : train(tr), bus(bu), t(t) {}
};
bool vis[maxN][maxN][2];

int solve() {
	memset(vis, 0, sizeof(vis));
	queue<Status> Q;
	while(!Q.empty()) Q.pop();
	Q.push(Status(1, 1, 0));
	vis[1][1][0] = true;
	int step = 0;
	while(!Q.empty()) {
		int sz = Q.size();
		++step;
		while(sz--) {
			Status st = Q.front(); Q.pop();
			int train = st.train, bus = st.bus;
			if(st.t == 0) {
				if(train == n) {
//					printf("0 : push %d %d\n", train, bus);
					Q.push(Status(train, bus, 1));
					continue;
				}
				for(int v = 1; v <= n; ++v) if(v != train && G[train][v]) {
//					printf("0 : %d %d -> %d %d\n", train, bus, v, bus);
					if(vis[v][bus][1]) continue;
					else vis[v][bus][1] = true;
					Q.push(Status(v, bus, 1));
				}
			} else if(st.t == 1) {
				if(bus == n) {
//					pass
					if(train == n) return step / 2;
//					pass
				// 	printf("1 : push %d %d\n", train, bus);
					Q.push(Status(train, bus, 0));
					continue;
				}
				for(int v = 1; v <= n; ++v) if(v != bus && !G[bus][v] && (v != train || v == n)) {
//					printf("1 : %d %d -> %d %d\n", train, bus, train, v);
					if(vis[train][v][0]) continue;
					else vis[train][v][0] = true;
					Q.push(Status(train, v, 0));
//					pass
					if(train == n && v == n) return step / 2;
//					pass
				}
			} else {
				assert(false);
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(G, 0, sizeof(G));
	for(int kase = 1; kase <= m; ++kase) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
	printf("%d\n", solve());
	return 0;
}