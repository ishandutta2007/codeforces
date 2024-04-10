#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 41
int N, M, Q;
string g[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN]; // a, c, b, d
int good[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		cin >> g[i];
	}

	for (int a = 0; a < N; a++) {
		for (int c = a; c < N; c++) {
			// everything here is self-sufficient / isolated / whatever
			for (int b = M - 1; b >= 0; b--) {
				for (int d = b; d < M; d++) {
					dp[a][c][b][d] = dp[a][c][b+1][d];
					for (int t = 1; t <= c - a + 1; t++) {
						for (int i = a; i + t - 1 <= c; i++) {
							if (t == 1) {
								good[i][i] = 0;
								while (g[i][b + good[i][i]] == '0' && b + good[i][i] <= d) {
									good[i][i]++;
								}
							}
							else {
								good[i][i + t - 1] = min(good[i + 1][i + t - 1], good[i][i]);
							}
							dp[a][c][b][d] += good[i][i + t - 1];
						}
					}
				}
			}
		}
	}

	for (int q = 0; q < Q; q++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		cout << dp[a][c][b][d] << '\n';
	}

	cout.flush();
	return 0;
}