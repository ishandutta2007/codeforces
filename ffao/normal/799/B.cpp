#include <bits/stdc++.h>
using namespace std;

int n,t,k,d;

int p[210000];
int colors[210000][2];

struct comp {
	bool operator() (int a, int b) {
		return p[a] < p[b];
	}
};

set< int, comp > shirts[5]; 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &colors[i][0]);
		shirts[colors[i][0]].insert(i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &colors[i][1]);
		shirts[colors[i][1]].insert(i);
	}

	for (scanf("%d", &t); t; t--) {
		scanf("%d", &k);

		if (shirts[k].empty()) printf("-1");
		else {
			int g = *shirts[k].begin();
			for (int i = 1; i <= 3; i++) shirts[i].erase(g);
			printf("%d", p[g]);
		}

		if (t) printf(" ");
		else printf("\n");
	}
}