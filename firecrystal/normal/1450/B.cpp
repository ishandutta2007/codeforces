#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 105, INF = 0x3f3f3f3f;

int n, K, ans = INF, L[N], R[N], f[N];

PII e[N];


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(f, 0x3f, sizeof f);
		scanf("%d%d", &n, &K); ans = INF;
		for (int i = 1; i <= n; i++) scanf("%d%d", &e[i].first, &e[i].second);
		sort(e + 1, e + 1 + n);
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (abs(e[i].first - e[j].first) + abs(e[i].second - e[j].second) > K) break;
				R[i] = j;
			}
			for (int j = i; j; j--) {
				if (abs(e[i].first - e[j].first) + abs(e[i].second - e[j].second) > K) break;
				L[i] = j;
			}
			if (L[i] == 1 && R[i] == n) {
				ans = 1;
				break;
			}
		}
		if (ans == INF) puts("-1");
		else printf("%d\n", ans);	
	}	
	return 0;
}