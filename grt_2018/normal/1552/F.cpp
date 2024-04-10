#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10, mod = 998244353;
int n;
int x[nax], y[nax];
bool s[nax];
map<int,int>sc;
int T[(1 << 20)], R;
int dp[nax];

int ask(int l, int r) {
	l += R; r += R;
	int w = (T[l] + (r != l ? T[r] : 0)) % mod;
	while(l / 2 != r / 2) {
		if(l % 2 == 0) w = (w + T[l + 1]) % mod;
		if(r % 2 == 1) w = (w + T[r - 1]) % mod;
		l /= 2;
		r /= 2;
	}
	return w;
}

void upd(int a, int b) {
	a += R;
	T[a] += b;
	while(a > 1) {
		a /= 2;
		T[a] = (T[2*a] + T[2*a+1]) % mod;
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> s[i];
		sc[x[i]]; sc[y[i]];
	}
	sc[0];
	int nr = 0;
	for(auto &it : sc) it.ND = nr++;
	R = 1;
	while(R < nr) R *= 2;
	for(int i = 1; i <= n; ++i) {
		int w = ask(sc[y[i]], sc[x[i]]);
		dp[i] = (w + x[i] - y[i]) % mod;
		upd(sc[x[i]], dp[i]);
	}
	int ans = 0;
	int last = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i]) {
			ans = (ans + x[i] - last) % mod;
			ans = (ans + dp[i]) % mod;
			last = x[i];
		}
	}
	ans = (ans + x[n] + 1 - last) % mod;
	if(ans < 0) ans += mod;
	cout << ans;
}