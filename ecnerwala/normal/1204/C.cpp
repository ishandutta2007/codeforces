#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 120;
int N;
bool adj[MAXN][MAXN];
int dist[MAXN][MAXN];

const int MAXM = 1.1e6;
int M;
int P[MAXM];
int dp[MAXM];
int prv[MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			adj[i][j] = (s[j] - '0');
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = (adj[i][j] ? 1 : INF);
		}
		dist[i][i] = 0;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> P[i];
		P[i] --;
	}
	dp[0] = 1;
	prv[0] = -1;

	for (int i = 1; i < M; i++) {
		dp[i] = dp[i-1];
		prv[i] = i-1;
		for (int d = 2; d <= i && d <= N; d++) {
			if (dist[P[i-d]][P[i]] == d) {
				if (dp[i-d] < dp[i]) {
					dp[i] = dp[i-d];
					prv[i] = i-d;
				}
			} else {
				break;
			}
		}
		dp[i]++;
	}

	vector<int> res;
	for (int cur = M-1; cur != -1; cur = prv[cur]) {
		res.push_back(cur);
	}

	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i : res) { cout << P[i]+1 << ' '; } cout << '\n';

	return 0;
}