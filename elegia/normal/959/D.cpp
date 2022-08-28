#include <cstdio>

using namespace std;

const int N = 10000010;

int n, pc;
int a[N];
bool sie[N], vis[N];
int fac[N], pr[N];

void apply(int x);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int x = 2; x < N; ++x) {
		if (!vis[x]) {
			pr[++pc] = x;
			fac[x] = x;
		}
		for (int i = 1; pr[i] * x < N; ++i) {
			vis[pr[i] * x] = true;
			fac[pr[i] * x] = pr[i];
			if (x % pr[i] == 0)
				break;
		}
	}
	bool flag = true;
	int cur = 2;
	for (int i = 1; i <= n; ++i) {
		if (flag) {
			if (!sie[a[i]]) {
				printf("%d ", a[i]);
				apply(a[i]);
				continue;
			} else {
				flag = false;
				while (sie[a[i]])
					++a[i];
				apply(a[i]);
				printf("%d ", a[i]);
				continue;
			}
		}
		while (sie[cur])
			++cur;
		printf("%d ", cur);
		apply(cur);
	}
	return 0;
}

void apply(int cur) {
	while (cur != 1) {
		int pfac = fac[cur];
		cur /= pfac;
		if (!sie[pfac]) {
			for (int x = 1; x * pfac < N; ++x)
				sie[x * pfac] = true;
		}
	}
}