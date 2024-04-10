#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

int n;
long long W[1000010], C;
deque <pll> q;
long long op[1000010];
long long a[1000010];

int main() {
	goto MAIN;
	BAD:;
	printf("NO\n");
	return 0;
	GOOD:;
	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%lld ", a[i]);
	printf("\n");
	return 0;
	MAIN:;
	scanf("%d%lld", &n, &C);
	for (int i = 0; i < n - 2; i++) scanf("%lld", &W[i]);
	int k = 1, flag = 0; long long b = 0;
	q.push_back(mp(0, C));
	for (int i = 0; i < n - 2; i++) {
		long long w = W[i];
		while (q.size() && (flag ? q.front().se : q.back().fi) * k + b > w) {
			flag ? q.pop_front() : q.pop_back();
		}
		if (!q.size()) goto BAD;
		if (w < (flag ? q.front().fi : q.back().se) * k + b) {
			(flag ? q.front().fi : q.back().se) = (w - b) / k;
		}
		if ((flag ? q.front().fi : q.back().se) * k + b == w) {
			q.clear();
			flag ? q.push_front(mp((w - b) / k, -b / k)) : q.push_back(mp(-b / k, (w - b) / k));
			op[i] = -1;
		} else {
			op[i] = (flag ? q.front().fi : q.back().se) * k + b;
			flag ^= 1;
			k *= -1, b *= -1, b += w;
			long long tmp = (w - b) / k;
			if ((flag ? q.front().fi : q.back().se) * k + b < w - 1) {
				flag ? q.push_front(mp(tmp, tmp)) : q.push_back(mp(tmp, tmp));
			} else (flag ? q.front().fi : q.back().se) = tmp;
		}
	}
	a[n - 2] = (flag ? q.front().fi : q.back().se) * k + b;
	int rev = 0;
	for (int i = n - 3; i >= 0; i--) {
		long long w = W[i];
		if (op[i] == -1) rev ^= 1, a[i] = rev ? -w : w;
		else if (abs(a[i + 1]) == w) rev ^= 1, a[i] = rev ? -op[i] : op[i];
		else a[i] = rev ? -w - a[i + 1] : w - a[i + 1];
	}
	for (int i = n - 1; i >= 1; i--) a[i] = a[i - 1];
	a[0] = 0;
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	long long minj = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < n; i++) minj = min(minj, a[i]);
	for (int i = 0; i < n; i++) a[i] -= minj;
	goto GOOD; 
	return 0;
}