#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> os;

int a[100005], d;
bool vis[100005][15][5];
double memo[100005][15][5], eps = 1e-9;
vector<int> ans;

double dp(int pos, int digit, int valid) {
	if (pos == 0) {
		if (valid && (digit == d))
			return 0.0;
		return -1000000000.0;
	}
	if (vis[pos][digit][valid])
		return memo[pos][digit][valid];
	vis[pos][digit][valid] = true;
	double ret = dp(pos - 1, digit, valid);
	ret = max(ret, log2(a[pos]) + dp(pos - 1, (digit * a[pos]) % 10, 1));
	memo[pos][digit][valid] = ret;
	return ret;
}

void backtrack(int pos, int digit, int valid) {
	if (pos == 0)
		return;
	if (fabs(dp(pos, digit, valid) - dp(pos - 1, digit, valid)) <= eps)
		backtrack(pos - 1, digit, valid);
	else {
		ans.pb(a[pos]);
		backtrack(pos - 1, (digit * a[pos]) % 10, 1);
	}
}

int main() {
	/*os x;
	x.order_of_key(v); // banyak objek < v
	*x.find_by_order(v); // objek ke-v (0-based)*/
	int n;
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (dp(n, 1, 0) < 0)
		puts("-1");
	else {
		backtrack(n, 1, 0);
		printf("%d\n", (int) ans.size());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}