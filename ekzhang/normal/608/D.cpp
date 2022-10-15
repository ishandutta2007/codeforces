#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 502
#define INF 1<<30;

int N;
int C[MAXN];
int dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}

	for (int len = 1; len <= N; len++) {
		for (int s = 0; s <= N - len; s++) {
			int e = s + len - 1;
			dp[s][e] = len;

			if (len > 1) {
				dp[s][e] = min(dp[s][e], dp[s + 1][e] + 1);
				if (C[s] == C[s + 1]) {
					dp[s][e] = min(dp[s][e], dp[s + 2][e] + 1);
				}
			}
			if (len > 2) {
				for (int k = s + 2; k <= e; k++) {
					if (C[s] == C[k]) {
						dp[s][e] = min(dp[s][e], dp[s + 1][k - 1] + dp[k + 1][e]);
					}
				}
			}

			for (int j = s; j < e; j++) {
				dp[s][e] = min(dp[s][e], dp[s][j] + dp[j + 1][e]);
			}
		}
	}

	cout << dp[0][N - 1] << endl;
	return 0;
}