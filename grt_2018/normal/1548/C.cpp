#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 3000 * 1000 + 10, mod = 1e9 + 7;
int n, q;
int ans[nax];
int f[nax], inv[nax];

int fast_pow(int a, int b) {
	int w = 1;
	while(b > 0) {
		if(b & 1) {
			w = ((ll)w * a) % mod;
		}
		b /= 2;
		a = ((ll)a * a) % mod;
	}
	return w;
}

int bi(int a, int b) {
	if(b > a) return 0;
	return ((ll)f[a] * inv[b] % mod) * inv[a - b] % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	f[0] = inv[0] = 1;
	for(int i = 1; i <= 3 * n + 3; ++i) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		inv[i] = fast_pow(f[i], mod - 2);
	}
	ans[3 * n] = 1;
	//cout << ans[n] << " " << ans[n + 1] << "\n";
	for(int i = 3 * n - 1; i >= 1; --i) {
		ans[i] = ((ll)bi(3 * n + 3, i + 3) - 3LL * (ans[i + 1] + ans[i + 2])) % mod;
		if(ans[i] < 0) ans[i] += mod;
	}
	while(q--) {
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
}