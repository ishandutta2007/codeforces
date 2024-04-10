#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int NO_ANS = 2147483647;

struct edge { int u, v, l; };

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	vector <edge> e(m);
	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].l), e[i].u--, e[i].v--;
	vector <int> ok(n, false);
	for (int i = 0; i < k; i++)
	{
		int q; scanf("%d", &q); q--;
		ok[q] = true;
	}
	int ans = NO_ANS;                                           
	for (int i = 0; i < m; i++)
		if (ok[e[i].u] ^ ok[e[i].v]) ans = min(ans, e[i].l);
	if (ans == NO_ANS) ans = -1;
	printf("%d\n", ans);
}