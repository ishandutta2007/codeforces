#include<cstdio>
#include<algorithm>
int n,p;
struct device{
	int a, b;
	bool operator<(const device&r)const {
		return ((long long int)b)*r.a < ((long long int)r.b)*a;
	}
};
device d[100100];
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &d[i].a, &d[i].b);
	}
	std::sort(d, d + n);
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += d[i].a;
	}
	if (p >= sum) {
		printf("-1");
		return 0;
	}
	double ans = 1e18;
	double tpw = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += d[i].a;
		tpw += d[i].b;
		if (sum > p&&ans > tpw / (sum - p))ans = tpw / (sum - p);
	}
	printf("%.10lf", ans);
	return 0;
}