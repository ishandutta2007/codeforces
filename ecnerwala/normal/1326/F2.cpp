#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

bool adj[18][18];
i64 ans[1<<17];

template <typename T> void subset_transform(int N, T a[1<<18]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1<<N); j++) {
			if (j & (1<<i)) continue;
			a[j | (1<<i)] += a[j];
		}
	}
}

template <typename T> void inverse_superset_transform(int N, T a[1<<18]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1<<N); j++) {
			if (j & (1<<i)) continue;
			a[j] -= a[j | (1<<i)];
		}
	}
}


int pNeg1(int a) {
	return (a&1) ? -1 : 1;
}

i64 dp[1<<18][18];

i64 lenCnt[18+1][1<<18];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			assert(s[j] == '0' || s[j] == '1');
			adj[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		dp[1<<i][i] = 1;
	}
	for (int m = 1; m < (1<<N); m++) {
		for (int i = 0; i < N; i++) {
			if (!(m & (1<<i))) continue;
			for (int j = 0; j < N; j++) {
				if (m & (1<<j)) continue;
				if (adj[i][j]) {
					dp[m|(1<<j)][j] += dp[m][i];
				}
			}
		}
	}

	for (int m = 1; m < (1<<N); m++) {
		for (int i = 0; i < N; i++) {
			lenCnt[__builtin_popcount(m)][m] += dp[m][i];
		}
	}

	for (int l = 1; l <= N; l++) subset_transform(N, lenCnt[l]);

	map<vector<int>, i64> partitionMem;
	for (int p = 0; p < (1<<(N-1)); p++) {
		vector<int> partition;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt++;
			if (!(p & (1<<i))) {
				partition.push_back(cnt);
				cnt = 0;
			}
		}
		sort(partition.begin(), partition.end());
		if (!partitionMem.count(partition)) {
			i64 res = 0;
			for (int m = 0; m < (1<<N); m++) {
				i64 curVal = 1;
				for (int l : partition) {
					curVal *= lenCnt[l][m];
				}
				res += pNeg1(N-__builtin_popcount(m)) * curVal;
			}
			partitionMem[partition] = res;
		}
		ans[p] = partitionMem[partition];
	}

	inverse_superset_transform(N-1, ans);
	for (int p = 0; p < (1<<(N-1)); p++) { cout << ans[p] << ' '; } cout << '\n';

	return 0;
}