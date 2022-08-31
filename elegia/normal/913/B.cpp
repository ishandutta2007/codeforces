#include <cstdio>

using namespace std;

const int N = 1010;

int prt[N], cnt[N], lcnt[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		int u;
		scanf("%d", &u);
		prt[i] = u;
		++cnt[u];
	}
	for (int i = 2; i <= n; ++i) {
		if (cnt[i] == 0)
			++lcnt[prt[i]];
	}
	bool flag = true;
	if (lcnt[1] < 3)
		flag = false;
	for (int i = 2; i <= n; ++i)
		if (cnt[i] != 0 && lcnt[i] < 3)
			flag = false;
	if (flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}