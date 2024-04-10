#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 53
#define MAXP 103
#define INF 112345678901234
int N;
int proct;
pair<int, int> A[MAXN];
LL dp[2][MAXN*MAXP][MAXN]; // size 5e5

int P[MAXN];
vector<int> proc[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i].first;
	for (int i = 0; i < N; i++) {
		cin >> A[i].second;
		proct += A[i].second;
	}

	sort(A, A + N);

	// compress :/
	int amt = 0;
	int pre = -1;
	for (int i = 0; i < N; i++) {
		int power = A[i].first;
		int processors = A[i].second;
		if (power != pre) {
			pre = power;
			P[amt++] = power;
		}
		proc[amt - 1].push_back(processors);
	}

	for (int p = 1; p <= proct; p++) {
		for (int d = 0; d <= N; d++) {
			dp[0][p][d] = INF;
		}
	}

	for (int n = 0; n < amt; n++) {
		int k = n%2;
		LL power = P[n];

		for (int p = 0; p <= proct; p++) {
			for (int d = 0; d <= N; d++) {
				LL cur = INF;

				int cproc = 0;
				for (int p : proc[n])
					cproc += p;

				for (int x = 0; x <= proc[n].size(); x++) {
					// num. sidelined

					int ex = proc[n].size() - x; // num exec
					LL totpow = power * ex;
					if (x)
						cproc -= proc[n][x - 1];

					if (x > d)
						break;
					int rem = d - x;

					if (p >= cproc) {
						if (rem+ex <= N)
							cur = min(cur, totpow + dp[k][p-cproc][rem+ex]);
						if (rem == 0) {
							for (int i = 0; i < ex; i++) {
								cur = min(cur, totpow + dp[k][p-cproc][i]);
							}
						}
					}
				}

				dp[!k][p][d] = cur;
			}
		}
	}

	LL ans = INF;
	for (int p = 1; p <= proct; p++) {
		LL cur = dp[amt%2][p][0];
		if (cur != INF) {
			ans = min(ans, (cur * 1000 + p - 1) / p);
		}
	}


	cout << ans << endl;
	return 0;
}