#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

int dp[1<<18], ok[1<<18];
bitset<18> A[18];

int N, M, Ans;

int main() {
	cin >> N >> M;
	for(int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		A[a][b] = A[b][a] = true;
	}
	for(int key = 1<<N; key--;) {
		ok[key] = 1;
		for(int i = 0; i < N; i++) if(key & (1<<i))
			for(int j = i+1; j < N; j++) if(key & (1<<j))
				if(A[i][j]) ok[key] = 0;
	}

	dp[0] = 1;
	for(int key = 1; key < (1<<N); key++) {
		int r = 0;
		for(int leaf = key; leaf; leaf = (leaf-1) & key) if(ok[leaf]) {
			if(__builtin_popcount(leaf) & 1) {
				r += dp[key^leaf];
				if(MOD <= r) r -= MOD;
			} else {
				r -= dp[key^leaf];
				if(r < 0) r += MOD;
			}
		}
		dp[key] = r;
	}

	Ans = dp[(1<<N)-1];
	if(Ans & 1) Ans += MOD;
	Ans >>= 1;
	cout << ll(Ans) * M % MOD << endl;
	return 0;
}