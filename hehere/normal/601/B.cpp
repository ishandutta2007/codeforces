#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <stack>
using std::stack;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 100000 + 233;
const int maxQ = 100 + 5;
int n, q;
int a[maxN], d[maxN], p[maxN], rk[maxN];
int pre[maxN], post[maxN];

int abs(int x) {
	return x < 0 ? -x : x;
}

bool cmp(int x, int y) {
	return d[x] > d[y];
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i) d[i] = abs(a[i + 1] - a[i]), p[i] = i;
	std::sort(p + 1, p + n-1 + 1, cmp);
	for(int i = 1; i < n; ++i) rk[p[i]] = i;
	stack<int> S;
	S.push(0); rk[0] = 0;
	for(int i = 1; i < n; ++i) {
		while(rk[S.top()] > rk[i]) S.pop();
		pre[i] = S.top(); S.push(i);
	}
	while(!S.empty()) S.pop();
	S.push(n + 2); rk[n + 2] = 0;
	for(int i = n - 1; i >= 1; --i) {
		while(rk[S.top()] > rk[i]) S.pop();
		post[i] = S.top(); S.push(i);
	}
//	for(int i = 1; i < n; ++i) printf("%d ", pre[i]); printf("\n");
//	for(int i = 1; i < n; ++i) printf("%d ", post[i]); printf("\n");
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		LL ans = 0;
		for(int i = 1; i < n; ++i) if(l <= p[i] && p[i] < r) {
			int lb = std::max(l, pre[p[i]] + 1);
			int rb = std::min(r, post[p[i]]);
			LL da = (p[i] - lb + 1) * (LL)(rb - p[i]) * (LL)d[p[i]];
//			printf("%d %d %d %d\n", l, pre[p[i]] + 1, r, post[p[i]]);
//			printf("%lld times of contrib. for %d\n", (p[i] - lb + 1) * (LL)(rb - p[i]), p[i]);
			ans += da;
		}
//		for(int i = l; i < r; ++i) {
//			for(int j = i + 1; j <= r; ++j) {
//				LL dans = 0;
//				for(int k = i; k < j; ++k) dans = std::max(dans, (LL)d[k]);
//				ans += dans;
//			}
//		}
		cout << ans << endl;
	}
	return 0;
}