#include<cstdio>
#include<algorithm>
int n;
long long int a[100100];
int q;
long long int b[100100][2];
struct qry {
	long long int dist;
	int idx;
	bool operator<(const qry&r)const {
		return dist < r.dist;
	}
};
qry ql[100100];
long long int c[100100];
long long int res[100100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%lld%lld", &b[i][0], &b[i][1]);
		ql[i].dist = b[i][1] - b[i][0] + 1;
		ql[i].idx = i;
	}
	std::sort(a, a + n);
	std::sort(ql, ql + q);
	for (int i = 0; i < n - 1; i++) {
		c[i] = a[i + 1] - a[i];
	}
	std::sort(c, c + n - 1);
	long long int ans = 0;
	long long int pl = 0;
	int j = 0;
	for (int i = 0; i < q; i++) {
		while (j < n - 1 && c[j] <= ql[i].dist) {
			ans += (n - j)*(c[j] - pl);
			pl = c[j];
			j++;
		}
		ans += (n - j)*(ql[i].dist - pl);
		pl = ql[i].dist;
		res[ql[i].idx] = ans;
	}
	for (int i = 0; i < q; i++) {
		printf("%lld ", res[i]);
	}
	return 0;
}