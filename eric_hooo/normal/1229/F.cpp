#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[35010], L[35010], R[35010];
priority_queue <long long> P;
priority_queue <long long, vector <long long>, greater <long long> > Q;
long long PP, QQ;
int n;

long long calc(long long mid) {
	while (P.size()) P.pop(); while (Q.size()) Q.pop(); PP = QQ = 0;
	for (int i = 0; i < n; i++) P.push(mid);
	for (int i = 0; i < n; i++) Q.push(mid);
	long long F = 0;
	for (int i = 0; i < n; i++) {
		PP += a[i] - R[i], QQ += a[i] - L[i];
		assert(P.top() + PP <= Q.top() + QQ);
		if (P.top() + PP > 0) {
			P.push(0 - PP), P.push(0 - PP);
			F += abs(P.top() + PP), Q.push(P.top() + PP - QQ), P.pop();
		} else if (Q.top() + QQ < 0) {
			Q.push(0 - QQ), Q.push(0 - QQ);
			F += abs(Q.top() + QQ), P.push(Q.top() + QQ - PP), Q.pop();
		} else P.push(0 - PP), Q.push(0 - QQ);
	}
	if (mid < P.top() + PP) {
		long long cur = 0;
		while (P.top() + PP > mid) {
			cur++; long long x = P.top() + PP; P.pop();
			if (!P.size() || P.top() + PP < mid) {F += (x - mid) * cur; break;}
			F += (x - P.top() - PP) * cur;
		}
	} else if (mid > Q.top() + QQ) {
		long long cur = 0;
		while (Q.top() + QQ < mid) {
			cur++; long long x = Q.top() + QQ; Q.pop();
			if (!Q.size() || Q.top() + QQ > mid) {F += (mid - x) * cur; break;}
			F += (Q.top() + QQ - x) * cur;
		}
	}
	return F;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i], &L[i], &R[i]);
	long long l = -2000000000, r = 2000000000;
	while (l < r) {
		long long mid = l + r >> 1;
		if (calc(mid) - calc(mid + 1) > 0) l = mid + 1;
		else r = mid;
	}
	printf("%I64d\n", calc(l));
	return 0;
}