#include<bits/stdc++.h>
using namespace std;

const int MAXK = 600;
const int MAXN = 600;

int N, K;
bool dp[MAXK][MAXK];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	dp[0][0] = true;
	for(int i = 0; i < N; i++) {
		int c; cin >> c;
		for(int t = K - c; t >= 0; t--) {
			for(int v = 0; v <= t; v++) {
				if(dp[t][v]) {
					dp[t + c][v] = true;
					dp[t + c][v + c] = true;
				}
			}
		}
	}
	vector<int> res;
	for(int i = 0; i <= K; i++) {
		if(dp[K][i]) res.push_back(i);
	}
	cout << res.size() << '\n';
	for(int i : res) cout << i << ' ';
	cout << '\n';
	return 0;
}