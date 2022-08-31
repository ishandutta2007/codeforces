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

int n, m;
int f[N], sum1[N], sum2[N], deg[N];
bool flag[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
		sum1[i] = 1;
	}
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		++deg[u];
		++deg[v];
		u = find(u);
		v = find(v);
		if (u != v) {
			f[u] = v;
			sum1[v] += sum1[u];
			sum2[v] += sum2[u];
		}
		++sum2[v];
	}
	for (int i = 1; i <= n; ++i) {
		if (f[i] != i) {
			flag[i] = true;
		} else if (sum1[i] != sum2[i])
			flag[i] = true;
		if (deg[i] != 2)
			flag[find(i)] = true;
	}
	printf("%ld\n", count(flag + 1, flag + n + 1, false));
	return 0;
}