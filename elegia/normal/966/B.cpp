#include <cstdio>
#include <cstring>

#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Node {
	int v, id;

	bool operator<(const Node &rhs) const {
		return v < rhs.v;
	}

	bool operator>(const Node &rhs) const {
		return rhs < *this;
	}

	bool operator<=(const Node &rhs) const {
		return !(rhs < *this);
	}

	bool operator>=(const Node &rhs) const {
		return !(*this < rhs);
	}
};

const int N = 300010;

int n, x1, x2;
Node a[N];
int ans[N];
bool vis[N];
int k1[N], k2[N];

int main() {
	scanf("%d%d%d", &n, &x1, &x2);
	for (int i = 1; i <= n; ++i)
		a[i].id = i;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	sort(a + 1, a + n + 1, greater<Node>());
	for (int i = 1; i <= n; ++i) {
		k1[i] = (x1 + a[i].v - 1) / a[i].v;
		k2[i] = (x2 + a[i].v - 1) / a[i].v;
	}
	int mex = -1, pos = 0;
	for (int i = n; i > 1; --i) {
		if (mex < i - k2[i]) {
			pos = i;
			mex = i - k2[i];
		}
		if (i - 1 >= k1[i - 1] && k1[i - 1] <= mex) {
			puts("Yes");
			printf("%d %d\n", k1[i - 1], k2[pos]);
			for (int j = 1; j <= k1[i - 1]; ++j) {
				printf("%d ", a[i - j].id);
				vis[i - j] = true;
			}
			putchar('\n');
			int cnt = k2[pos];
			while (cnt) {
				if (!vis[pos]) {
					--cnt;
					printf("%d ", a[pos].id);
				}
				--pos;
			}
			putchar('\n');
			return 0;
		}
	}
	mex = -1;
	pos = 0;
	for (int i = n; i > 1; --i) {
		if (mex < i - k1[i]) {
			pos = i;
			mex = i - k1[i];
		}
		if (i - 1 >= k2[i - 1] && k2[i - 1] <= mex) {
			puts("Yes");
			printf("%d %d\n", k1[pos], k2[i - 1]);
			for (int j = 1; j <= k2[i - 1]; ++j) {
				ans[j] = a[i - j].id;
				vis[i - j] = true;
			}
			int cnt = k1[pos];
			while (cnt) {
				if (!vis[pos]) {
					--cnt;
					printf("%d ", a[pos].id);
				}
				--pos;
			}
			putchar('\n');
			for (int j = 1; j <= k2[i - 1]; ++j)
				printf("%d ", ans[j]);
			putchar('\n');
			return 0;
		}
	}
	puts("No");
	return 0;
}