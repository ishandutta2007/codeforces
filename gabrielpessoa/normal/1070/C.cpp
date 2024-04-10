#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

struct tariff {
	ll l, r, c, p;
	bool operator < (const tariff &t) const {
		return p < t.p;
	}
};

int n, k, m;
tariff a[ms];
ll bitCores[ms];
ll bitPrecos[ms];
vector<pair<int, int>> events[ms];

void updateCores(int idx, ll v) {
	while(idx <= m) {
		bitCores[idx] += v;
		idx += idx & -idx;
	}
}

ll queryCores(int idx) {
	ll r = 0;
	while(idx > 0) {
		r += bitCores[idx];
		idx -= idx & -idx;
	}
	return r;
}

void updatePrecos(int idx, ll v) {
	while(idx <= m) {
		bitPrecos[idx] += v;
		idx += idx & -idx;
	}
}

ll queryPrecos(int idx) {
	ll r = 0;
	while(idx > 0) {
		r += bitPrecos[idx];
		idx -= idx & -idx;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].l >> a[i].r >> a[i].c >> a[i].p;
	}
	sort(a+1, a + m + 1);
	for(int i = 1; i <= m; i++) {
		events[a[i].l].emplace_back(i, 0);
		events[a[i].r+1].emplace_back(i, 1);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(auto p : events[i]) {
			if(p.second == 0) {
				updateCores(p.first, a[p.first].c);
				updatePrecos(p.first, a[p.first].c*a[p.first].p);
			} else {
				updateCores(p.first, -a[p.first].c);
				updatePrecos(p.first, -a[p.first].c*a[p.first].p);
			}
		}
		if(queryCores(m) >= k) {
			int lo = 1, hi = m;
			while(lo < hi) {
				int mid = (lo+hi)/2;
				if(queryCores(mid) < k) {
					lo = mid + 1;
				} else {
					hi = mid;
				}
			}
			ans += queryPrecos(lo-1) + (k - queryCores(lo-1))*a[lo].p;
		} else {
			ans += queryPrecos(m);
		}
	}
	cout << ans << endl;
}