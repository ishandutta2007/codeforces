#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;

int n, cnt;
bool flag = false;
int a[N];
bool vis[N];
char ans[N][N];

vector<vector<int> > cyc;

void link(int r, int u, int v) {
	ans[r][u] = ans[r][v] = (u < v ? '/' : '\\');
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	memset(ans, '.', sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		if (a[i] == i || vis[i])
			continue;
		vector<int> cur;
		int x = i;
		while (!vis[x]) {
			vis[x] = true;
			cur.push_back(x);
			x = a[x];
		}
		reverse(cur.begin(), cur.end());
		vector<int>::iterator it = max_element(cur.begin(), cur.end());
		reverse(cur.begin(), it);
		reverse(it, cur.end());
		cyc.push_back(cur);
	}
	if (cyc.empty())
		printf("%d\n", n);
	else {
		printf("%d\n", n - 1);
		int pos = -1, chose = 0;
		for (int j = 0; j < cyc.size(); ++j) {
			if (pos < cyc[j].back()) {
				pos = cyc[j].back();
				chose = j;
			}
		}
		cnt = n;
		for (int i = cyc[chose].size() - 2; i; --i)
			link(cnt--, cyc[chose][i - 1], cyc[chose][i]);
		link(cnt--, pos, cyc[chose].front());
		for (int j = 0; j < cyc.size(); ++j)
			if (j != chose) {
				ans[cnt][pos] = '/';
				for (int i = cyc[j].size() - 1; i; --i)
					link(cnt--, cyc[j][i - 1], cyc[j][i]);
				link(cnt--, pos, cyc[j].front());
			}
	}
	for (int i = 1; i <= n; ++i) {
		ans[i][n + 1] = 0;
		puts(ans[i] + 1);
	}
	
#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}