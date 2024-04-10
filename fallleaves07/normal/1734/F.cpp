#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int count(LL loc) {
	int ans = 0;
	while (loc > 0) {
		ans ^= (loc & 1);
		loc >>= 1;
	}
	return ans;
}

LL f[66][2][2][2], n, m;
bool vis[66][2][2][2];
LL solve(LL b, LL vx, LL inc, LL up) {
	if (vis[b][vx][inc][up]) {
		return f[b][vx][inc][up];
	}
	if (b < 0) {
		if (inc) {
			return 0;
		}
		return ((vx == 0) && (inc == 0)) ? 1 : 0;
	}
	vis[b][vx][inc][up] = true;
	LL &ret = f[b][vx][inc][up];
	ret = 0;
	for (int i = 0; i < 2; i++) {
		if (up && i > ((m >> b) & 1)) {
			break;
		}
		bool upnow = (up && (i == ((m >> b) & 1)));
		for (int k = 0; k < 2; k++) {
			int val = i + ((n >> b) & 1) + k;
			if (val > 1 && inc) {
				ret += solve(b - 1, vx ^ i ^ (val & 1), k, upnow);
			}
			if (val <= 1 && !inc) {
				ret += solve(b - 1, vx ^ i ^ (val & 1), k, upnow);
			}
		}
	}
	return ret;
}

void solve() {
	cin >> n >> m;
	--m;
	memset(vis, 0, sizeof(vis));
	printf("%lld\n", solve(62, 1, 0, 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}