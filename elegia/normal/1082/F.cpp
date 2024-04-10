#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

typedef long long ll;

using namespace std;

struct Node {
	int cnt, id, dep;
	Node* ch[10];
};

const int N = 510, K = 11;

int n, t, k, ans;

Node* rt;

char s[N];
int dp[N][N][K];

Node* create();
void dfs(Node* p);
void merge(int* a, int* b);

int main() {
	rt = create();
	scanf("%d%d", &n, &k);
	while (n--) {
		int m;
		scanf("%s%d", s, &m);
		Node* p = rt;
		for (char* q = s; *q; ++q) {
			if (!p->ch[*q - '0']) {
				p->ch[*q - '0'] = create();
				p->ch[*q - '0']->dep = p->dep + 1;
			}
			p = p->ch[*q - '0'];
		}
		p->cnt += m;
		ans += m * p->dep;
	}
	dfs(rt);
	ans -= dp[1][0][k];
	printf("%d\n", ans);
	return 0;
}

void dfs(Node* p) {
	int u = p->id;
	for (int c = 0; c < 10; ++c)
		if (p->ch[c]) {
			dfs(p->ch[c]);
			int v = p->ch[c]->id;
			for (int d = 0; d <= p->dep; ++d)
				for (int i = k; i >= 0; --i)
					for (int j = i; j >= 0; --j)
						dp[u][d][i] = max(dp[u][d][i], dp[u][d][j] + dp[v][d][i - j]);
		}
	for (int d = 1; d <= p->dep; ++d)
		for (int i = 0; i <= k; ++i) {
			dp[u][d][i] += p->cnt * d;
	//		printf("%d %d %d: %d\n", u, d, i + 1, dp[u][d][i]);
		}
	for (int d = 0; d < p->dep; ++d)
		for (int i = 1; i <= k; ++i)
			dp[u][d][i] = max(dp[u][d][i], dp[u][p->dep][i - 1]);
}

Node* create() {
	static Node pool[N];
	static Node* p = pool;
	p->id = ++t;
	return p++;
};