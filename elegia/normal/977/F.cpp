#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <iostream>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
int u;
map<int, int> cur;
int a[N], dp[N], nxt[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i; --i) {
		nxt[i] = cur[a[i] + 1];
		dp[i] = dp[nxt[i]] + 1;
		if (dp[u] < dp[i])
			u = i;
		cur[a[i]] = i;
	}
	printf("%d\n", dp[u]);
	while (u) {
		printf("%d ", u);
		u = nxt[u];
	}
	return 0;
}