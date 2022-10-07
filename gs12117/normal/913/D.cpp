#include<cstdio>
#include<algorithm>
int n, m;
struct prob {
	int a, t, idx;
	bool operator<(const prob&r)const {
		return t < r.t;
	}
};
prob pl[200100];
prob pd[200100];
int pdl;
int bsrc(int x) {
	pdl = 0;
	for (int i = 0; i < n; i++) {
		if (pl[i].a >= x) {
			pd[pdl] = pl[i];
			pdl++;
		}
	}
	if (pdl < x)return 0;
	std::sort(pd, pd + pdl);
	int td = 0;
	for (int i = 0; i < x; i++) {
		td += pd[i].t;
		if (td > m)return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &pl[i].a, &pl[i].t);
		pl[i].idx = i + 1;
	}
	int ans = -1;
	for (int i = 18; i >= 0; i--) {
		ans += 1 << i;
		if (bsrc(ans) == 0)ans -= 1 << i;
	}
	bsrc(ans);
	printf("%d\n", ans);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d ", pd[i].idx);
	}
	return 0;
}