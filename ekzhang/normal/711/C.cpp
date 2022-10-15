#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAX 113
#define INF (1LL<<50)
int N, M, K;
int C[MAX];
LL P[MAX][MAX];
LL dp[MAX][MAX][MAX]; // n, prev color, beauty

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> P[i][j];
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= K; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= N; i++) {
		if (C[i - 1]) {
			// dp[i][C[i - 1]][...k?]
			for (int k = 1; k <= K; k++) {
				dp[i][C[i-1]][k] = dp[i-1][C[i-1]][k];
				for (int otherc = 0; otherc <= M; otherc++) {
					if (otherc == C[i-1]) continue;
					dp[i][C[i-1]][k] = min(dp[i][C[i-1]][k], dp[i-1][otherc][k-1]);
				}
			}
		}
		else {
			for (int j = 1; j <= M; j++) {
				for (int k = 1; k <= K; k++) {
					dp[i][j][k] = dp[i-1][j][k];
					for (int otherc = 0; otherc <= M; otherc++) {
						if (otherc == j) continue;
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][otherc][k-1]);
					}
					dp[i][j][k] += P[i-1][j-1];
				}
			}
		}
	}

	LL ans = INF;
	for (int j = 1; j <= M; j++) {
		ans = min(ans, dp[N][j][K]);
	}

	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}