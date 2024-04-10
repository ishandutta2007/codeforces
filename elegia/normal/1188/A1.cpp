#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int N = 100010;

int n;
int deg[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		++deg[u]; ++deg[v];
	}
	if (count(deg + 1, deg + n + 1, 2))
		puts("NO");
	else
		puts("YES");
	return 0;
}