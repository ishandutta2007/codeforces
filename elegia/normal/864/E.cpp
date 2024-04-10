#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct node {
	int t, d, p, id;

	bool operator<(const node& x) const { return d < x.d; }
};

const int N = 110;

int n, ans, ax, ay;
int dp[N][2000], lst[N][2000];
vector<node> v;
vector<int> va;

int main() {
	node tmp;
	scanf("%d", &n);
	for (tmp.id = 1; tmp.id <= n; ++tmp.id) {
		scanf("%d%d%d", &tmp.t, &tmp.d, &tmp.p);
		if (tmp.t < tmp.d)
			v.push_back(tmp);
	}
	n = v.size();
	if (!n) {
		puts("0\n0");
		return 0;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; ++i) {
		dp[i][v[i - 1].t] = v[i - 1].p;
		if (dp[i][v[i - 1].t] > ans) {
			ans = dp[i][v[i - 1].t];
			ax = i;
			ay = v[i - 1].t;
		}
		for (int j = v[i - 1].t; j < v[i - 1].d; ++j)
			for (int k = 1; k < i; ++k)
				if (dp[i][j] < dp[k][j - v[i - 1].t] + v[i - 1].p) {
					dp[i][j] = dp[k][j - v[i - 1].t] + v[i - 1].p;
					lst[i][j] = k;
					if (ans < dp[i][j]) {
						ans = dp[i][j];
						ax = i;
						ay = j;
					}
				}
	}
	printf("%d\n", ans);
	while (ax) {
		va.push_back(v[ax - 1].id);
		ay -= v[ax - 1].t;
		ax = lst[ax][ay + v[ax - 1].t];
	}
	printf("%lu\n", va.size());
	for (int i = va.size() - 1; ~i; --i)
		if (i)
			printf("%d ", va[i]);
		else
			printf("%d\n", va[0]);
	return 0;
}