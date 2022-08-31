#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) ((x) & (- (x)))
ll a[1000010];
ll id[1000010];
ll minx[1000010], maxx[1000010];
ll n;
inline void add1(ll x, ll k) {
	for(; x; x -= lowbit(x)) maxx[x] = max(maxx[x], k);
}
inline ll get_ans1(ll x) {
	ll ans = 0;
	for(; x <= n; x += lowbit(x)) ans = max(ans, maxx[x]);
	return ans;
}
inline void add2(ll x, ll k) {
	for(; x; x -= lowbit(x)) minx[x] = min(minx[x], k);
}
inline ll get_ans2(ll x) {
	ll ans = 1e9;
	for(; x <= n; x += lowbit(x)) ans = min(ans, minx[x]);
	return ans;
}
ll l[1000010], r[1000010], suml[2000010], sumr[2000010];
struct query {
	int isl, r, k, f, id;
	friend inline int operator < (const query &a, const query &b) {
		return a.r < b.r;
	}
} q[4000010];
ll sum1[1000010], sum2[1000010], cnt1[1000010], cnt2[1000010], m, cnt, ans[1000010];
inline void addr(ll x, ll k) {
	ll _x = x;
	for(; x; x -= lowbit(x)) sum1[x] += k;
	for(; _x; _x -= lowbit(_x)) cnt1[_x] ++;
}
inline void addl(ll x, ll k) {
	ll _x = x;
	for(; x <= n; x += lowbit(x)) sum2[x] += k;
	for(; _x <= n; _x += lowbit(_x)) cnt2[_x] ++;
}
inline ll get_sumr(ll x) {
	ll ans = 0;
	for(; x <= n; x += lowbit(x)) ans += sum1[x];
	return ans;
}
inline ll get_suml(ll x) {
	ll ans = 0;
	for(; x; x -= lowbit(x)) ans += sum2[x];
	return ans;
}
inline ll get_cntr(ll x) {
	ll ans = 0;
	for(; x <= n; x += lowbit(x)) ans += cnt1[x];
	return ans;
}
inline ll get_cntl(ll x) {
	ll ans = 0;
	for(; x; x -= lowbit(x)) ans += cnt2[x];
	return ans;
}
int ql[1000010], qr[1000010];
int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i <= n; i++) id[a[i]] = i;
	for(int i = 1; i <= n; i++) {
		l[i] = get_ans1(a[i]);
		add1(a[i], i);
	}
	for(int i = 1; i <= n; i++) minx[i] = n + 1;
	for(int i = n; i > 0; i--) {
		r[i] = get_ans2(a[i]);
		add2(a[i], i);
	}
	// for(int i = 1; i <= n; i++) printf("%lld ", l[i]);
	// puts("");
	// for(int i = 1; i <= n; i++) printf("%lld ", r[i]);
	// puts("");
	for(int i = 1; i <= m; i++) scanf("%d", ql + i);
	for(int i = 1; i <= m; i++) scanf("%d", qr + i);
	for(int i = 1; i <= n; i++) suml[i] = suml[i - 1] + l[i], sumr[i] = sumr[i - 1] + r[i];
	for(int i = 1; i <= m; i++) {
		int l = ql[i], r = qr[i];
		ans[i] = l - r - 1 + sumr[r] - sumr[l - 1] + suml[l - 1] - suml[r];
		q[++cnt] = query{1, r, l, 1, i};
		q[++cnt] = query{0, r, r, 1, i};
		q[++cnt] = query{1, l - 1, l, -1, i};
		q[++cnt] = query{0, l - 1, r, -1, i};
	}
	int nowr = 0;
	sort(q + 1, q + 1 + cnt);
	for(int i = 1; i <= cnt; i++) {
		while(nowr < q[i].r) {
			nowr ++;
			addl(l[nowr] + 1, l[nowr] + 1);
			addr(r[nowr] - 1, r[nowr] - 1);
		}
		// printf("%d %d %d %d %d\n", q[i].f, q[i].id, q[i].isl, q[i].k, q[i].r);
		// printf("%lld %lld %lld %lld\n", get_suml(q[i].k), get_cntl(q[i].k), get_sumr(q[i].k), get_cntr(q[i].k));
		// printf("%lld\n", q[i].isl ? q[i].f * (get_suml(q[i].k) - q[i].k * get_cntl(q[i].k)) : q[i].f * (get_cntr(q[i].k) * q[i].k - get_sumr(q[i].k)));
		if(q[i].isl) ans[q[i].id] += q[i].f * (get_suml(q[i].k) - q[i].k * get_cntl(q[i].k));
		else ans[q[i].id] += q[i].f * (get_cntr(q[i].k) * q[i].k - get_sumr(q[i].k));
	}
	for(int i = 1; i <= m; i++) printf("%lld ", ans[i]);
	return 0;
}