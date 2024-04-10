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

const int N = 1 << 10;
int cnt[N], tmp[N];

int main(){

	int n = nxt(), k = nxt(), x = nxt();
	for (int i = 0; i < n; ++i) {
		int q = nxt();
		cnt[q] += 1;
	}

	for (int i = 0; i < k; ++i) {
		memset(tmp, 0, sizeof(tmp));
		int cur = 1;
		for (int j = 0; j < N; ++j) {
			tmp[j ^ x] += (cnt[j] + cur) >> 1;
			tmp[j] += (cnt[j] + 1 - cur) >> 1;
			cur ^= (cnt[j] & 1);
		}
		memcpy(cnt, tmp, N * sizeof(int));
	}

	int mn = N, mx = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt[i]) {
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}

	cout << mx << " " << mn << "\n";

	return 0;
}