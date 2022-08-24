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

const int mod = 1000000007;
const int N = 1111111;

int fact[N];

int ph = 0;
int phase[N];
int cnt[N];

int main(){

	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * 1ll * i % mod;
	}

	int n = nxt(), m = nxt();
	// int n = 1e5, m = 1e6;
	vector<vector<pair<int, int>>> lol(m);
	for (int i = 0; i < n; ++i) {
		int c = nxt();
		// int c = 5;
		++ph;
		vector<int> tmp;
		for (int j = 0; j < c; ++j) {
			int x = nxt() - 1;
			// int x = rand() % m;
			if (phase[x] != ph) {
				phase[x] = ph;
				tmp.push_back(x);
				cnt[x] = 0;
			}
			cnt[x] += 1;
		}
		for (int x : tmp) {
			lol[x].push_back({i, cnt[x]});
		}
	}

	sort(all(lol));
	int cur = 1;
	long long ans = 1;
	for (int i = 1; i < m; ++i) {
		if (lol[i] == lol[i - 1]) {
			cur += 1;
		} else {
			ans = ans * fact[cur] % mod;
			cur = 1;
		}
	}

	ans = ans * fact[cur] % mod;
	cout << ans << "\n";

	return 0;
}