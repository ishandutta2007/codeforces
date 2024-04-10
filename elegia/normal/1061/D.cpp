#include <cstdio>

#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

const int N = 100010, P = 1000000007;

int n, x, y;

pair<int, int> a[N * 2];

int main() {
	int ans = 0;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		ans = (ans + (r - l) * (ll)y + x) % P;
		a[i * 2 - 1] = make_pair(l, 0);
		a[i * 2] = make_pair(r, 1);
	}
	sort(a + 1, a + n * 2 + 1);
	stack<int> stk;
	for (int i = 1; i <= n * 2; ++i) {
		if (a[i].second == 0) {
			if (!stk.empty() && (a[i].first - stk.top()) * (ll)y - x < 0) {
				ans = (ans + (a[i].first - stk.top()) * (ll)y - x) % P;
				if (ans < 0)
					ans += P;
				stk.pop();
			}
		} else
			stk.push(a[i].first);
	}
	printf("%d\n", ans);
	return 0;
}