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

const int D = 21;
const int N = 1111111;
const int mod = 1000000007;
long long sum[N][D];

int erat[N];

// int get_ans(int r, int c) {
// 	int lst = 0;
// 	vector<int> degs;
// 	while (c > 1) {
// 		if (erat[c] != lst) {
// 			degs.push_back(0);
// 		}
// 		lst = erat[c];
// 		degs.back() += 1;
// 		c /= erat[c];
// 	}
// 	if (r == 0) {
// 		return 1 << degs.size();
// 	} else {
// 		int ans = 1;
// 		for (int d : degs) {
// 			ans = 1ll * ans * sum[r][d];
// 		}
// 		return ans;
// 	}
// }

int main(){

	for (int i = 0; i < D; ++i) {
		sum[1][i] = 1 + 2 * i;
	}
	for (int i = 2; i < N; ++i) {
		for (itn j = 0; j < D; ++j) {
			for (int k = 0; k <= j; ++k) {
				sum[i][j] += sum[i - 1][k];
			}
			sum[i][j] %= mod;
		}
	}

	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
	}

	int q = nxt();
	while (q--) {
		int r = nxt(), c = nxt();
		int lst = 0;
		vector<int> degs;
		while (c > 1) {
			if (erat[c] != lst) {
				degs.push_back(0);
			}
			lst = erat[c];
			degs.back() += 1;
			c /= erat[c];
		}
		if (r == 0) {
			printf("%d\n", 1 << degs.size());
		} else {
			int ans = 1;
			for (int d : degs) {
				ans = 1ll * ans * sum[r][d] % mod;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}