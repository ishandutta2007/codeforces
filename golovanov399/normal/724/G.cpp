#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

const int mod = 1000000007;
const int D = 61;
const long long DD = 1ll << D;

void make_good(vector<long long>& a) {
	long long q = 1ll << (D - 1);
	int i = 0;
	int n = a.size();
	while (q > 0 && i < n) {
		int j = i;
		while (j < n && (a[j] & q) == 0) {
			j += 1;
		}
		if (j == n) {
			q >>= 1;
			continue;
		}
		if (j != i) {
			swap(a[i], a[j]);
		}
		for (j = i + 1; j < n; j++) {
			if (a[j] & q) {
				a[j] ^= a[i];
			}
		}
		i++;
	}
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
}

const itn N = 111111;
vector<pair<int, long long>> a[N];
long long ans = 0;
long long val[N];
char used[N];

int main(){

	cin.sync_with_stdio(0);

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; i++) {
		int u = nxt() - 1, v = nxt() - 1;
		long long w;
		cin >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}

	for (int i = 0; i < n; i++) {
		if (used[i]) {
			continue;
		}

		queue<int> qq;
		int cn = 0;
		qq.push(i);
		used[i] = 1;
		vector<long long> xors;
		vector<int> vs;
		while (!qq.empty()) {
			int v = qq.front();
			qq.pop();
			cn++;
			vs.push_back(v);
			for (auto p : a[v]) {
				if (!used[p.first]) {
					qq.push(p.first);
					used[p.first] = 1;
					val[p.first] = val[v] ^ p.second;
				} else if (val[p.first] != (val[v] ^ p.second)) {
					xors.push_back(val[p.first] ^ val[v] ^ p.second);
				}
			}
		}
		make_good(xors);
		int cnt = xors.size();
		for (long long q = 1; q < DD; q <<= 1) {
			bool ok = false;
			for (auto w : xors) {
				if (w & q) {
					ok = true;
				}
			}
			if (ok) {
				ans += q % mod * ((1ll << (cnt - 1)) % mod * ((1ll * cn * (cn - 1) / 2) % mod) % mod) % mod;
			} else {
				int tmp = 0;
				for (int x : vs) {
					if (val[x] & q) {
						tmp++;
					}
				}
				ans += q % mod * tmp % mod * (cn - tmp) % mod * ((1ll << cnt) % mod) % mod;
			}
		}
	}

	cout << ans % mod << "\n";

	return 0;
}