#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
 
#include <numeric> 
 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

 
typedef pair<int, int> pii;


#define mp make_pair


int n,a,b;
vector<pii> edges;
vector<int> adj[310000];
unsigned long long t[310000];
int size[310000];
char color[310000];
int order[310000];
int deg[310000];

int dfs(int v, int p, int e) {
	if (size[e] != -1) return size[e];

	size[e] = 1;

	for (int i = 0; i < adj[v].size(); i++) {
		int dest;
		if (adj[v][i] >= n-1) {
			dest = edges[adj[v][i] - (n-1)].first;
		}
		else {
			dest = edges[adj[v][i]].second;
		}
		if (dest != p) size[e] += dfs(dest, v, adj[v][i]);
	}

	return size[e];
}

unsigned long long newr() {
	unsigned long long a = rand();
	unsigned long long b = rand();
	unsigned long long c = rand();
	unsigned long long d = rand();
	unsigned long long e = rand();
	 
	return (a << 48) + (b << 32) + (c << 16) + d + (e&1);
}

pair<int, unsigned long long> get_seq(int e) {
	int v, p;
	if (e >= (n-1)) {
		v = edges[e-(n-1)].first;
		p = edges[e-(n-1)].second;
	}
	else {
		v = edges[e].second;
		p = edges[e].first;
	}

	pair<int, unsigned long long> ans;
	ans.first = color[v];
	ans.second = 0;

	for (int i = 0; i < adj[v].size(); i++) {
		int dest;
		if (adj[v][i] >= n-1) {
			dest = edges[adj[v][i] - (n-1)].first;
		}
		else {
			dest = edges[adj[v][i]].second;
		}

		if (dest != p) {
			unsigned long long th = t[adj[v][i]];
			ans.second += th;
		}
	}

	return ans;
}

bool comps(int a, int b) {
	return size[a] < size[b];
}

int verif(int v, int p) {
	set<unsigned long long> seen;
	int ans = 0;
	if (adj[v].size() < 4) ans++;

	for (int e : adj[v]) {
		int ot;
		if (e >= n-1) ot = edges[e - (n-1)].first;
		else ot = edges[e].second;
		if (ot == p) continue;

		unsigned long long th = t[e];
		if (seen.find(th) == seen.end()) {
			ans += verif(ot, v);
			seen.insert(th);
		}
	}

	return ans;
}

void solve() {
	srand(5886);
	scanf("%d", &n);

	memset(size, -1, sizeof(size));
	edges.clear();
	for (int i = 0; i < n; i++) adj[i].clear();
	
	//for (int i = 0; i < n; i++) {
	//	scanf(" %c", &color[i]);
	//}

	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		edges.push_back(mp(a,b));
		adj[a].push_back(i);
		adj[b].push_back((n-1) + i);
		deg[a]++; deg[b]++;
	}

	for (int i = 0; i < n-1; i++) {
		if (size[i] == -1) dfs(edges[i].second, edges[i].first, i);
		if (size[(n-1) + i] == -1) dfs(edges[i].first, edges[i].second, i + (n-1));
	}

	for (int i = 0; i < 2*(n-1); i++) {
		order[i] = i;
	}
	sort(order, order + 2*(n-1), comps);

	int cur = 0;
	while (cur < 2*(n-1)) {
		int st = cur;
		int th = size[order[cur]];
		while (cur < 2*(n-1) && size[order[cur]] == th) cur++;

		vector< pair< pair<int, long long >, int > > seqs;
		for (int k = st; k < cur; k++) {
			seqs.push_back(make_pair(get_seq(order[k]), order[k]));
		}

		sort(seqs.begin(), seqs.end());

		unsigned long long cur_t = 0;
		for (int k = 0; k < seqs.size(); k++) {
			if (k == 0 || seqs[k].first != seqs[k-1].first) {
				cur_t = newr();
			}
			//printf("t[%d]=%llu (%d %llu)\n", seqs[k].second, cur_t, seqs[k].first.first, seqs[k].first.second);
			t[seqs[k].second] = cur_t;
		}
	}

	vector<int> leaf, nxt_leaf;
	REP(i,n) if (deg[i] <= 1) nxt_leaf.push_back(i);

	int rem = n;
	while (rem > 2) {
		swap(leaf,nxt_leaf);
		nxt_leaf.clear();
		for (int x : leaf) {
			rem--;
			for (int e : adj[x]) {
				int ot;
				if (e >= n-1) ot = edges[e - (n-1)].first;
				else ot = edges[e].second;

				if (deg[ot]) {
					if (--deg[ot] == 1) nxt_leaf.push_back(ot);
				}
			}
		}
	}

	int ans;
	if (nxt_leaf.size() == 1) {
		ans = verif(nxt_leaf[0], -1);
	}
	else {
		int v1 = nxt_leaf[0], v2 = nxt_leaf[1];
		ans = verif(v1, v2);

		for (int e : adj[v1]) {
			int ot;
			if (e >= n-1) ot = edges[e - (n-1)].first;
			else ot = edges[e].second;

			if (ot == v2) {
				if (e >= n-1) e -= n-1;
				if (t[e] != t[e + (n-1)]) ans += verif(v2, v1);
			}
		}
	}

	printf("%d\n", ans);
}


int main() {
    solve();
}