#include <bits/stdc++.h>
using namespace std;

int wei[510];
char buf[510];
vector <int> seq;

int Query() {
	printf("? %s\n", buf);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		buf[i] = '0';
	}
	for (int i = 0; i < m; i++) {
		buf[i] = '1';
		wei[i] = Query();
		buf[i] = '0';
	}
	for (int i = 0; i < m; i++) {
		buf[i] = '0';
		seq.push_back(i);
	}
	sort(seq.begin(), seq.end(), [&](int x, int y) -> bool {return wei[x] < wei[y];});
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int x = seq[i];
		buf[x] = '1';
		if (Query() == ans + wei[x]) {
			ans += wei[x];
		} else {
			buf[x] = '0';
		}
	}
	printf("! %d\n", ans);
	return 0;
}