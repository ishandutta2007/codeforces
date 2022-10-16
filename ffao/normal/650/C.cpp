#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int n,m;
vector<int> adj[1100000];
int p[1100000];
int val[1100000];

int toh(int x, int y) {
	return x * m + y;
}

int fnd(int x) {
	if (p[x]==x) return x;
	return p[x]=fnd(p[x]);
}

void lnk(int a, int b) {
	//printf("lnk %d %d\n", a,b);
	int x = fnd(a), y = fnd(b);
	if (x == y) return;

	if (adj[x].size() > adj[y].size()) swap(x,y);
	p[x] = y;
	for (int conn : adj[x]) adj[y].push_back(conn);
}

int rec(int kk) {
	if (val[kk]) return val[kk];

	val[kk] = 1;
	for (int t : adj[kk]) {
		//printf("%d -> %d\n", kk, t);
		val[kk] = max(val[kk], rec(fnd(t)) + 1);
	}
	return val[kk];
}

int main(){
	scanf("%d %d", &n, &m);

	vector< vector<int> > a(n, vector<int>(m));

	for (int i = 0; i < n*m; i++) p[i]=i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	vector< pair<int, int> > tr;
	for (int i = 0; i < n; i++) {
		tr.clear();
		for (int j = 0; j < m; j++) tr.push_back({a[i][j], j});
		sort(tr.begin(), tr.end());
	
		for (int j = 1; j < m; j++) {
			int aa = toh(i,tr[j-1].second);
			int bb = toh(i, tr[j].second);
			if (tr[j-1].first == tr[j].first) lnk(aa, bb);
			else {
				//printf("edg %d %d\n", bb, aa);
				adj[fnd(bb)].push_back(fnd(aa)); 
			}
		}
	}

	for (int i = 0; i < m; i++) {
		tr.clear();
		for (int j = 0; j < n; j++) tr.push_back({a[j][i], j});
		sort(tr.begin(), tr.end());
	
		for (int j = 1; j < n; j++) {
			int aa = toh(tr[j-1].second, i);
			int bb = toh(tr[j].second, i);
			if (tr[j-1].first == tr[j].first) lnk(aa, bb);
			else {
				adj[fnd(bb)].push_back(fnd(aa)); 
			}
		}
	}

	for (int i = 0; i < (n*m); i++) if (p[i] == i) rec(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", val[ fnd(toh(i,j)) ]);
		}
		printf("\n");
	}

}