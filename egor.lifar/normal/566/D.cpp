#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


#define rank rank1


int n, q;
int rank[200002];
int parent[200002];
int l = 0;


void make_set(int i) {
	rank[i] = 1;
	parent[i] = i;
}



int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	parent[v] = find_set(parent[v]);
	return parent[v];
}

int set_union(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rank[a] <= rank[b]) {
			parent[a] = b;
			rank[b] = max(rank[a] + 1, rank[b]);
			return b;
		} else {
			parent[b] = a;
			rank[a] = max(rank[b] + 1, rank[a]);
			return a;
		}
	}
	return a;
}


int who[200002];
vector<pair<int, int> > v;


int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	l = (int)sqrt(n) + 1;
	int t1 = 0;
 	while (t1 < n) {
 		v.push_back(make_pair(t1, min(n - 1, t1 + l - 1)));
 		t1 += l;
 	}
	for (int k = 0; k < q; k++) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 3) {
			if (find_set(x - 1) == find_set(y - 1)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			continue;
		}
		if (t == 1) {
			if (find_set(x - 1) == find_set(y - 1)) {
				continue;
			}
			x--;
			y--;
			int c = find_set(x), d = find_set(y);
			int a = set_union(x, y);
			if (a == d) {
				swap(c, d);
			}
			for (int i = 0; i < (int)v.size(); i++) {
				if (who[i] == d + 1) {
					who[i] = c + 1;
				}
			}
			continue;
		}
		if (t == 2) {
			x--;
			y--;
			int h = -1;
			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i].first > y || v[i].second < x) {
					continue;
				}
				if (v[i].first >= x && v[i].second <= y) {
					if (who[i] == 0) {
						for (int j = v[i].first; j <= v[i].second; j++) {
							if (h == -1) {
								h = find_set(j);
							}
							h = set_union(h, j);
						}
					} else {
						if (h == -1) {
							h = who[i] - 1;
						}
						h = set_union(h, who[i] - 1);
					}
				} else {
					for (int j = v[i].first; j <= v[i].second; j++) {
						if (j >= x && j <= y) {
							if (h == -1) {
								h = find_set(j);
							}
							h = set_union(h, j);
						}
					}
				}
			}
			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i].first >= x && v[i].second <= y) {
					who[i] = h + 1;
				}
			}
		}
	}
    return 0;
}