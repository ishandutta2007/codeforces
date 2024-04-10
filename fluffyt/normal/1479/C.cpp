#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 100005;
struct Edge { int v, w; };
int L, R;
vector<Edge> edge[40];

int main() {
	scanf("%d%d", &L, &R);
	puts("YES");
	if (L == R) {
		puts("2 1");
		printf("1 2 %d\n", L);
		return 0;
	}
	int s = 2;
	if (L == 1) s = 1;
	else edge[1].push_back(Edge { 2, L - 1 });
	R -= L - 1;
	for (int i = 0; i <= 20; i++)
	for (int j = 0; j < i; j++)
		edge[32 - i].push_back(Edge { 32 - j, j == 0 ? 1 : 1 << (j - 1) });
	edge[s].push_back(Edge { 3, 1 });
	for (int i = 0; i < 20; i++) if (R >> i & 1) {
		int t = R >> (i + 1) << (i + 1);
		if (t > 0) {
			assert(t > 1);
			edge[3].push_back(Edge { 31 - i, t - 1 });
		} else {
			for (Edge &e : edge[31 - i]) edge[s].push_back(e);
		}
	}
	int m = 0;
	for (int i = 1; i <= 32; i++) m += edge[i].size();
	printf("%d %d\n", 32, m);
	for (int i = 1; i <= 32; i++)
	for (Edge &e : edge[i]) printf("%d %d %d\n", i, e.v, e.w);
	return 0;
}