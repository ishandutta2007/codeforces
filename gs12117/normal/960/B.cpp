#include<cstdio>
#include<queue>
int n, m;
int a[1010];
int b[1010];
int ka, kb;
int d[1010];
std::priority_queue<int> pq;
int main() {
	scanf("%d%d%d", &n, &ka, &kb);
	m = ka + kb;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		d[i] = a[i] - b[i];
		if (d[i] < 0)d[i] = -d[i];
		pq.push(d[i]);
	}
	for (int i = 0; i < m; i++) {
		int x = pq.top();
		pq.pop();
		if (x == 0) {
			x++;
		}
		else {
			x--;
		}
		pq.push(x);
	}
	long long int ans = 0;
	while (pq.size() > 0) {
		long long int x = pq.top();
		ans += x*x;
		pq.pop();
	}
	printf("%lld", ans);
	return 0;
}