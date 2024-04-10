#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 5005
#define MOD 1000000007
#define INF (1<<30)
int N;
string S;
LL dp[MAXN][MAXN];
LL dpsuf[MAXN][MAXN]; // suffix sums [j..end]
int firstdiff[MAXN][MAXN];

bool bigcmp(int a, int b, int d) {
	// returns a < b
	int fd = firstdiff[a][b];
	if (fd < 0 || fd >= d) {
		return false;
	}
	return S[a + fd] < S[b + fd];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;

	// precompute stuff
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (S[i] != S[j]) {
				firstdiff[i][j] = 0;
			}
			else if (i < N - 1 && j < N - 1) {
				firstdiff[i][j] = firstdiff[i + 1][j + 1] + 1;
			}
			else {
				firstdiff[i][j] = -INF;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == '0') {
			continue;
		}
		dp[i][N - i] = 1;
		for (int d = 1; d < N - i; d++) {
			dp[i][d] += dpsuf[i + d][d + 1];
			if (dp[i + d][d] > 0) {
				if (bigcmp(i, i + d, d)) {
					dp[i][d] += dp[i + d][d];
				}
			}
			dp[i][d] %= MOD;
		}
		for (int j = N; j >= 0; j--) {
			dpsuf[i][j] = dpsuf[i][j + 1] + dp[i][j];
			dpsuf[i][j] %= MOD;
		}
	}

	cout << dpsuf[0][0] << endl;
	return 0;
}