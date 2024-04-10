#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAX 100013
#define MAXN 5013
int N;
int A[MAXN];
int dp[MAXN][MAXN];
int best[MAX];
int bestmod[7];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int y = 0; y <= N; y++) {
		fill(best, best + MAX, dp[0][y]);
		fill(bestmod, bestmod + 7, dp[0][y]);

		for (int x = 0; x < y; x++) {
			best[A[x]] = max(best[A[x]], dp[x][y]);
			bestmod[A[x] % 7] = max(bestmod[A[x] % 7], dp[x][y]);
		}

		for (int x = y + 1; x <= N; x++) {
			// here we will calculate dp[x][y] (also dp[y][x])
			// maximum sum-length subsequences with first ending at x, second ending at y
			dp[x][y] = 1;
			dp[x][y] = max(dp[x][y], bestmod[A[x] % 7] + 1);
			dp[x][y] = max(dp[x][y], best[A[x] - 1] + 1);
			dp[x][y] = max(dp[x][y], best[A[x]] + 1);
			dp[x][y] = max(dp[x][y], best[A[x] + 1] + 1);
			dp[y][x] = dp[x][y];

			best[A[x]] = max(best[A[x]], dp[x][y]);
			bestmod[A[x] % 7] = max(bestmod[A[x]], dp[x][y]);

			ans = max(ans, dp[x][y]);
			// error(x, y, dp[x][y]);
		}
	}

	cout << ans << endl;
	return 0;
}