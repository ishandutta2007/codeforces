#include<cstdio>
#include<queue>
long long int ans;
int anst;
long long int dev;
int n;
int a[1001000];
int diff[1001000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		diff[i] = a[i] - i - 1;
	}
	std::priority_queue<std::pair<int, int>> pq;
	for (int i = 0; i < n; i++) {
		if (diff[i] < 0) {
			pq.push({ diff[i],i });
			dev -= diff[i];
		}
		else {
			dev += diff[i];
		}
	}
	ans = dev;
	anst = 0;
	for (int i = 0; i < n; i++) {
		if (ans > dev) {
			ans = dev;
			anst = n - i;
		}
		dev -= diff[i] + i;
		diff[i] -= n;
		dev += -i - diff[i];
		pq.push({ diff[i],i });
		while (pq.size() > 0 && pq.top().first == -i) {
			pq.pop();
		}
		dev -= (int)pq.size();
		dev += n - (int)pq.size();
	}
	printf("%I64d %d", ans, anst);
}