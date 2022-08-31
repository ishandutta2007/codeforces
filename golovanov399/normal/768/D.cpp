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

int main(){

	int k = nxt(), q = nxt();
	vector<vector<long double>> dp(1, vector<long double>(k + 1, 0));
	dp[0][k] = 1;
	while (dp.back()[0] < 0.51) {
		dp.push_back(vector<long double>(k + 1, 0));
		int pr = (int)dp.size() - 2;
		int nw = (int)dp.size() - 1;
		dp[nw][k] = 1;
		for (int i = 0; i < k; ++i) {
			dp[nw][i] = dp[pr][i + 1] * (k - i) / k + dp[pr][i] * i / k;
		}
	}

	vector<int> ans(1, 0);
	for (int i = 0; i < (int)dp.size(); ++i) {
		int p = (dp[i][0] + 1e-10) * 2000;
		while (ans.size() <= 1000 && ans.size() <= p) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < q; ++i) {
		int x = nxt();
		cout << ans[x] << "\n";
	}

	// cerr << "[";
	// for (int i = 0; i < (int)ans.size(); ++i) {
	// 	if (i) {
	// 		cerr << ", ";
	// 	}
	// 	cerr << ans[i];
	// }
	// cerr << "]\n";

	return 0;
}