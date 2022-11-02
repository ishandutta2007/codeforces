#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 200000 + 233;
const int maxM = 200000 + 233;

inline bool chmin(int &a, const int &b) { return a > b ? a = b, true : false; }
inline bool chmax(int &a, const int &b) { return a < b ? a = b, true : false; }

int n, m, k, l[maxN], r[maxN];
vector<int> G[maxN], T[maxN];
int ind[maxN], outd[maxN];

bool set_segments() {
	if(n < k) return false;
	queue<int> Q;
	for(int u = 1; u <= n; ++u) if(!ind[u]) Q.push(u);
	int cnt = 0;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); ++cnt;
		for(int v : G[u]) {
			chmin(r[v], r[u] - 1);
			if(--ind[v] == 0) Q.push(v);
		}
	}
	if(cnt != n) return false;
	for(int u = 1; u <= n; ++u) if(!outd[u]) Q.push(u);
	cnt = 0;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); ++cnt;
		for(int v : T[u]) {
			chmax(l[v], l[u] + 1);
			if(--outd[v] == 0) Q.push(v);
		}
	}
	if(cnt != n) return false;
	for(int u = 1; u <= n; ++u) if(l[u] > r[u]) return false;
	return true;
}

int t;
int val[maxN];
set<int> S[maxN];
typedef set < pii > PQ;
PQ pq;
void update(int u) {
	for(int v : T[u]) {
		if(l[v] < val[u] + 1) {
			if(t < l[v]) S[l[v]].erase(v);
			else pq.erase(pii(r[v], v));
			S[val[u] + 1].insert(v);
			l[v] = val[u] + 1;
		}
	}
}

bool set_values() {
	for(int u = 1; u <= n; ++u) S[l[u]].insert(u);
//	for(int u = 1; u <= n; ++u) printf("%d : %d %d\n", u, l[u], r[u]);
	for(t = 1; t <= k; ++t) {
		
		for(int u : S[t]) pq.insert(pii(r[u], u));
//		printf("t = %d : ", t);
		if(pq.empty()) return false;
//		for(int u : S[t]) printf("%d ", u); printf("\n");
		do {
			int u = pq.begin()->second; pq.erase(pq.begin());
			if(l[u] > r[u] /*|| l[u] > t*/) return false;
			val[u] = t;
			update(u);
		} while(!pq.empty() && r[pq.begin()->second] == t);
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &r[i]);
	for(int i = 1; i <= n; ++i) {
		if(r[i]) l[i] = r[i] = r[i];
		else l[i] = 1, r[i] = k;
	}
	memset(ind, 0, sizeof(ind));
	memset(outd, 0, sizeof(outd));
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		T[y].push_back(x);
		outd[x]++; ind[y]++;
	}
	if(!set_segments() || !set_values()) {
		printf("-1\n"); return 0;
	}
	for(int u = 1; u <= n; ++u) printf("%d%c", val[u], u == n ? '\n' : ' ');
	return 0;
}