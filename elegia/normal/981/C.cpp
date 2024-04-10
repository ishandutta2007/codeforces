#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

#define LOG(FMT...) fprintf(stderr)

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 100010;

int n;
int deg[N];
vector<int> leafs;

void adde(int u, int v);
void dfs(int u);

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("No");
		return 0;
	}
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		++deg[u];
		++deg[v];
	}
	int cnt = 0;
	int chose = 1;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] > 2) {
			++cnt;
			chose = i;
		} else if (deg[i] == 1)
			leafs.push_back(i);
	}
	if (cnt > 1) {
		puts("No");
		return 0;
	}
	if (deg[chose] == 1) {
		puts("Yes\n1");
		printf("%d %d\n", leafs[0], leafs[1]);
	} else {
		printf("Yes\n%d\n", leafs.size());
		for (int u : leafs)
			printf("%d %d\n", chose, u);
	}
	return 0;
}