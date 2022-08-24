#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mm = 20;
const int M = 1 << mm;
const int N = 77;
const int mod = 1000000007;

int ans[N][M];

int main(){

	int n = nxt();
	string s;
	cin >> s;
	vector<int> a(n);
	for (itn i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	ans[0][0] = 1;
	vector<int> pos(n + 1);
	for (int i = 0; i <= n; ++i) {
		pos[i] = i % N;
	}
	vector<int> chain(n);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			chain[i] = 1 - a[i];
		} else {
			chain[i] = (a[i] ? 0 : chain[i - 1] + 1);
		}
	}
	long long result = 0;
	for (itn i = 0; i < n; ++i) {
		int index = pos[i + 1];
		memset(ans[index], 0, sizeof(ans[index]));
		ans[index][0] = 1;
		int cur = 0;
		int dg = 1;
		for (int j = i; j >= 0 && cur <= mm; --j) {
			cur += dg * a[j];
			if (dg > 128) {
				dg = 128;
			}
			dg *= 2;
			int ps = pos[j];
			if (cur > 0 && cur <= mm) {
				int C = 1 << (cur - 1);
				for (int k = 0; k < M; ++k) {
					ans[index][k | C] += ans[ps][k];
					if (ans[index][k | C] >= mod) {
						ans[index][k | C] -= mod;
					}
				}
			}
		}
		for (int k = 1; k <= mm; ++k) {
			// cerr << ans[j][(1 << i) - 1] << " ";
			result += ans[index][(1 << k) - 1];
		}

	}

	cout << result % mod << "\n";

	return 0;
}