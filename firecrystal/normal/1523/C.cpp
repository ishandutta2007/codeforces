#include <iostream>
#include <cstdio>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1005;

int n, a[N], b[N], i, t;

void out() {
	printf("%d", b[1]);
	for (int i = 2; i <= t; i++) printf(".%d", b[i]);
	puts("");
}

void dfs(int u) {
	b[++t] = 1;
	out();
	++i;
	if (i > n) return;
	while (1) {
		if (a[i] == b[t] + 1) {
			b[t]++;
			out();
			i++;
		} else if (a[i] == 1) {
			dfs(u + 1);
		} else {
			break;
		}
	}
	--t;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		t = 0;
		i = 1;
		dfs(1);
	}
	return 0;
}