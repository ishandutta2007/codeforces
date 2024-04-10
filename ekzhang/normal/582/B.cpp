#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXN 100
#define MAXLG 26
#define INF (1LL<<54);

int N, T;
int ar[MAXN];
LL dp[MAXN][MAXN][MAXLG + 1]; // LSS start >=a_i, end at a_j, exp
LL ans[MAXN][MAXN][MAXLG];
int asi = 0;

void square(int lg) {
	// use dp[][][lg] to calculate dp[][][lg+1]
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j][lg + 1] = -INF;
			for (int k = 0; k < N; k++) {
				dp[i][j][lg + 1] = max(dp[i][j][lg + 1], dp[i][k][lg] + dp[k][j][lg]);
			}
		}
	}
}

void mul(int lg) {
	// multiply ans[][][asi] by dp[][][lg], then asi++
	if (asi == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[i][j][asi] = dp[i][j][lg];
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[i][j][asi + 1] = -INF;
				for (int k = 0; k < N; k++) {
					ans[i][j][asi] = max(ans[i][j][asi], ans[i][k][asi - 1] + dp[k][j][lg]);
				}
			}
		}
	}
	asi++;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	for (int s = 0; s < N; s++) {
		for (int e = 0; e < N; e++) {
			if (ar[s] > ar[e]) {
				dp[s][e][0] = -INF;
			}
			else {
				dp[s][e][0] = 1;
				for (int i = 0; i < e; i++) {
					if (ar[i] <= ar[e]) {
						dp[s][e][0] = max(dp[s][i][0] + 1, dp[s][e][0]);
					}
				}
			}
		}
	}

	for (int lg = 0; lg < MAXLG; lg++) {
		square(lg);
	}

	int e = T;
	for (int i = MAXLG; i >= 0; i--) {
		if ((1 << i) <= e) {
			e -= (1 << i);
			error(i);
			mul(i);
		}
	}

	LL ans_final = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans_final = max(ans_final, ans[i][j][asi - 1]);
		}
	}

	cout << ans_final << endl;
	return 0;
}