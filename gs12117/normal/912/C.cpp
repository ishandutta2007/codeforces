#include<cstdio>
#include<queue>
long long int n, m;
long long int b, db, kh;
long long int sh[100100];
long long int mh[100100];
long long int rg[100100];
long long int kp[100100];
long long int kn;
long long int lpt;
long long int ans;
struct hcng {
	long long int t, e, h;
	bool operator<(const hcng&r)const {
		return t > r.t;
	}
};
struct kcng {
	long long int t, e;
	bool operator<(const kcng&r)const {
		return t > r.t;
	}
};
std::priority_queue<hcng> pqh;
std::priority_queue<kcng> pqk;
void proc(long long int time) {
	while (pqh.size() > 0 && pqh.top().t <= time) {
		long long int e = pqh.top().e;
		long long int h = pqh.top().h;
		kn -= kp[e];
		sh[e] = h - rg[e] * pqh.top().t;
		pqh.pop();
		kp[e] = 0;
		if (sh[e] + rg[e] * time <= kh || mh[e] <= kh) {
			kp[e] = 1;
			if (rg[e] != 0 && mh[e] > kh) {
				kcng t;
				t.e = e;
				t.t = (kh + rg[e] - sh[e]) / rg[e];
				pqk.push(t);
			}
		}
		kn += kp[e];
	}
	while (pqk.size() > 0 && pqk.top().t <= time) {
		long long int e = pqk.top().e;
		kn -= kp[e];
		pqk.pop();
		kp[e] = 0;
		if (sh[e] + rg[e] * time <= kh || mh[e] <= kh) {
			kp[e] = 1;
			if (rg[e] != 0 && mh[e] > kh) {
				kcng t;
				t.e = e;
				t.t = (kh + rg[e] - sh[e]) / rg[e];
				pqk.push(t);
			}
		}
		kn += kp[e];
	}
	lpt = time;
	if (ans < kn*(b + db*time))ans = kn*(b + db*time);
}
int main() {
	scanf("%lld%lld", &n, &m);
	scanf("%lld%lld%lld", &b, &db, &kh);
	for (long long int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &mh[i], &sh[i], &rg[i]);
		if (sh[i] <= kh) {
			kp[i] = 1;
			kn++;
			if (rg[i] != 0 && mh[i] > kh) {
				kcng t;
				t.e = i;
				t.t = (kh + rg[i] - sh[i]) / rg[i];
				pqk.push(t);
			}
		}
	}
	for (long long int i = 0; i < m; i++) {
		hcng t;
		scanf("%lld%lld%lld", &t.t, &t.e, &t.h);
		t.e--;
		pqh.push(t);
	}
	lpt = 0;
	ans = b*kn;
	while (pqh.size() > 0 || pqk.size() > 0) {
		long long int ne = 1e18;
		if (pqh.size() > 0) {
			ne = pqh.top().t;
		}
		if (pqk.size() > 0) {
			if (ne > pqk.top().t)ne = pqk.top().t;
		}
		if (lpt < ne - 1)proc(ne - 1);
		proc(ne);
	}
	if (kn > 0 && db > 0) {
		ans = -1;
	}
	printf("%lld\n", ans);
	return 0;
}