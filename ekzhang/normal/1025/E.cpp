#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 53
#define MAXM MAXN
int N, M;
int X[MAXM], Y[MAXM];
int GX[MAXN], GY[MAXN];

int order[MAXM];
vector<vector<int> > ans;

vector<pair<int, int> > mv1d(vector<int> x, vector<int> goal) {
	vector<pair<int, int> > moves;
	while (true) {
		bool diff = false;
		for (int i = 0; i < x.size(); i++) {
			int fr = x[i], to = goal[i];
			if (to > fr) {
				diff = true;
				if (i == x.size() - 1 || fr + 1 != x[i + 1]) {
					++x[i];
					moves.emplace_back(fr, fr + 1);
					break;
				}
			}
			else if (to < fr) {
				diff = true;
				if (i == 0 || fr - 1 != x[i - 1]) {
					--x[i];
					moves.emplace_back(fr, fr - 1);
					break;
				}
			}
		}
		if (!diff)
			break;
	}
	return moves;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> GX[i] >> GY[i];
	}

	for (int i = 0; i < M; i++)
		order[i] = i;

	sort(order, order + M, [](int i, int j) {
		return X[i] < X[j];
	});

	for (int y = 1; y <= N; y++) {
		vector<int> v, v2;
		for (int j = 0; j < M; j++) {
			int k = order[j];
			if (Y[k] == y) {
				v.push_back(X[k]);
				v2.push_back(j + 1);
			}
		}
		auto moves = mv1d(v, v2);
		for (auto p : moves) {
			ans.push_back({p.first, y, p.second, y});
		}
	}

	for (int i = 0; i < M; i++) {
		int j = order[i];
		// moved rock j to x-position i
		X[j] = i + 1;
	}

	sort(order, order + M, [](int i, int j) {
		return GY[i] < GY[j];
	});

	for (int i = 0; i < M; i++) {
		int j = order[i];
		while (Y[j] != i + 1) {
			if (Y[j] < i + 1) {
				ans.push_back({X[j], Y[j], X[j], Y[j] + 1});
				++Y[j];
			}
			else {
				ans.push_back({X[j], Y[j], X[j], Y[j] - 1});
				--Y[j];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int to = GX[i];
		while (X[i] != to) {
			if (X[i] < to) {
				ans.push_back({X[i], Y[i], X[i] + 1, Y[i]});
				++X[i];
			}
			else {
				ans.push_back({X[i], Y[i], X[i] - 1, Y[i]});
				--X[i];
			}
		}
	}

	for (int x = 1; x <= N; x++) {
		vector<int> v, v2;
		for (int j = 0; j < M; j++) {
			int k = order[j];
			if (X[k] == x) {
				v.push_back(Y[k]);
				v2.push_back(GY[k]);
			}
		}
		auto moves = mv1d(v, v2);
		for (auto p : moves) {
			ans.push_back({x, p.first, x, p.second});
		}
	}

	cout << ans.size() << '\n';
	for (auto v : ans) {
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';
	}

	cout.flush();
	return 0;
}