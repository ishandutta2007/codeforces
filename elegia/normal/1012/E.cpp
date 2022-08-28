#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
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

struct Node {
	int x, id, rid;

	bool operator<(const Node& rhs) const { return x < rhs.x; }
};

const int N = 200010;

int n, s;
int a[N], b[N], rk[N], rr[N], f[N];
bool vis[N];
Node na[N];
vector<vector<int> > modi;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	iota(f + 1, f + n + 1, 1);
	memcpy(b, a, sizeof(a));
	sort(b + 1, b + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[i]) {
			++cnt;
			na[cnt].x = a[i];
			na[cnt].id = cnt;
			na[cnt].rid = i;
		}
	}
	if (cnt > s) {
		puts("-1");
		return 0;
	}
	sort(na + 1, na + cnt + 1);
	for (int i = 1; i <= cnt; ++i) {
		rr[na[i].id] = na[i].rid;
		rk[na[i].id] = i;
	}
	for (int i = 1; i <= cnt; ++i)
		f[i] = find(rk[i]);
	for (int i = 1; i <= cnt; ++i) {
		if (na[i].x == na[i - 1].x && find(i) != find(i - 1)) {
			f[find(i)] = find(i - 1);
			swap(rk[na[i].id], rk[na[i - 1].id]);
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		if (vis[i])
			continue;
		int x = i;
		vector<int> cur;
		while (!vis[x]) {
			cur.push_back(rr[x]);
			vis[x] = true;
			x = rk[x];
		}
		modi.push_back(cur);
	}
	int spl = min(s - cnt, (int)modi.size());
	if (spl > 2) {
		vector<int> tmp, lit;
		while (spl--) {
			lit.push_back(modi.back().front());
			tmp.insert(tmp.end(), modi.back().begin(), modi.back().end());
			modi.pop_back();
		}
		reverse(lit.begin(), lit.end());
		modi.push_back(tmp);
		modi.push_back(lit);
	}
	printf("%lu\n", modi.size());
	for (const auto& mo : modi) {
		printf("%lu\n", mo.size());
		for (int x : mo)
			printf("%d ", x);
		putchar('\n');
	}
	return 0;
}