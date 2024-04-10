#include<bits/stdc++.h>
using namespace std;

const double INF = 1e99;

void setmin(double& a, double b) {
	if (b < a) a = b;
}

const int MAXN = 200;
int N;
double C, T;
pair<int, int> probs[MAXN];

const int MAXP = MAXN * 10;
int P;
double minTime[MAXN][MAXP];

int go() {
	cin >> N;
	cin >> C >> T;
	for (int i = 0; i < N; i++) {
		cin >> probs[i].first >> probs[i].second;
	}
	sort(probs, probs + N);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 10 * N; j++) {
			minTime[i][j] = INF+1;
		}
	}
	P = 0;
	minTime[0][P] = 0;
	for (int i = 0; i < N; i++) {
		for (int k = i; k >= 0; k--) {
			for (int j = P; j >= 0; j--) {
				if (minTime[k][j] >= INF) continue;
				setmin(minTime[k+1][j+probs[i].second], (minTime[k][j] + probs[i].first) / 0.9);
			}
		}
		P += probs[i].second;
	}
	for (int j = P; j >= 0; j--) {
		for (int k = 0; k <= N; k++) {
			double a = minTime[k][j];
			if (a >= INF) continue;
			// is there a t such that
			// a / (1 + Ct) + t <= T
			// derivative is -a * C / (1+Ct)^2 + 1
			// minimum is at (1+Ct)^2 = aC
			double t = max(0., (sqrt(a * C) - 1) / C);
			//cerr << j << ' ' << a << ' ' << t << '\n';
			//cerr << a / (1 + C * t) + t + 10 * k << '\n';
			if (a / (1 + C * t) + t + 10 * k <= T) {
				return j;
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Z; cin >> Z;
	while (Z--) {
		int res = go();
		cout << res << '\n';
	}

	return 0;
}