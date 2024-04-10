#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct Node {
	map <int, int> *all;
	int maxj;
	long long sum;
	Node() {maxj = 0, sum = 0;}
};

void merge(Node &x, Node y) {
	if (x.all->size() < y.all->size()) swap(x, y);
	for (map <int, int> :: iterator it = y.all->begin(); it != y.all->end(); it++) {
		int tmp = x.all->operator [](it->fi) + it->se;
		if (tmp > x.maxj) x.maxj = tmp, x.sum = it->fi;
		else if (tmp == x.maxj) x.sum += it->fi;
		x.all->operator [](it->fi) += it->se;
	}
}

vector <int> from[100010];
int a[100010];
long long ans[100010];

Node dfs(int x, int last) {
	Node now; now.all = new map <int, int> ;
	assert(now.all->begin() == now.all->end());
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		merge(now, dfs(v, x));
	}
	int tmp = now.all->operator [](a[x]) + 1;
	if (tmp > now.maxj) now.maxj = tmp, now.sum = a[x];
	else if (now.maxj == tmp) now.sum += a[x];
	now.all->operator [](a[x])++;
	ans[x] = now.sum;
	return now;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	return 0;
}