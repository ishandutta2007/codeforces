#include <bits/stdc++.h>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &x, T2 y){if (x > y) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 &x, T2 y){if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define x1 x1228
#define pb push_back
const int MAXN = 200001;

int n, m;
int l[MAXN], r[MAXN];
int cnt[MAXN];
int d[MAXN * 4];
int add[MAXN];


void change(int i, int x) {
	chkmax(d[i], x);
	while (i >> 1 > 0) {
		i >>= 1;
		d[i] = max(d[i * 2], d[i * 2 + 1]);
	}
}

int rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	int vn = v << 1;
	int vm = (vl + vr) >> 1;
	return max(rmq(vn, vl, vm, l, r), rmq(vn + 1, vm + 1, vr, l, r));
}


int f[MAXN];


int main() {
	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		add[l[i]]++;
		add[r[i] + 1]--;
	}
	int cur = 0;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		cur += add[i];
		cnt[i] = cur;
	}
	int ss = 1;
	while (ss <= n + 1) {
		ss <<= 1;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		//cout << cnt[i] << endl;
		int d = rmq(1, 1, ss, 1, cnt[i] + 1) + 1;
		chkmax(ans, d);
		f[i] = d;
		change(ss + cnt[i], d);
	}
	memset(d, 0, sizeof(d));
	for (int i = m; i >= 1; i--) {
		int d = rmq(1, 1, ss, 1, cnt[i] + 1) + 1;
		chkmax(ans, f[i] + d - 1);
		change(ss + cnt[i], d);
	}
	cout << ans << '\n';
	return 0;	
}