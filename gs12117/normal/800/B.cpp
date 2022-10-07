#include<cstdio>
#include<cmath>
int n;
double loc[100100][2];
double ans;
double mdist(int a) {
	int b = (a + 1) % n;
	int c = (b + 1) % n;
	double prod = (loc[a][0] - loc[c][0])*(loc[a][1] - loc[b][1]) - (loc[a][0] - loc[b][0])*(loc[a][1] - loc[c][1]);
	double dist = sqrt((loc[a][0] - loc[c][0])*(loc[a][0] - loc[c][0]) + (loc[a][1] - loc[c][1])*(loc[a][1] - loc[c][1]));
	return prod / dist / 2;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &loc[i][0], &loc[i][1]);
	}
	ans = 1e18;
	for (int i = 0; i < n; i++) {
		double t = mdist(i);
		if (t < ans)ans = t;
	}
	printf("%.10lf", ans);
}