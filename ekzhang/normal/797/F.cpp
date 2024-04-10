#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAX 5013
#define INF 1123456789123456789LL
int N, M;
int X[MAX];
pair<LL, int> H[MAX];
LL dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	LL housing = 0;
	for (int i = 1; i <= M; i++) {
		cin >> H[i].first >> H[i].second;
		housing += H[i].second;
	}
	if (N > housing) {
		cout << -1 << endl;
		return 0;
	}

	sort(X, X + N);
	sort(H + 1, H + M + 1);

	for (int i = 0; i < N; i++) {
		dp[0][i] = INF;
	}
	for (int i = 1; i <= M; i++) {
		LL allin = 0;
		deque<pair<LL, int> > mpq;
		mpq.push_back({0, -1});
		for (int j = 0; j < N; j++) {
			allin += abs(X[j] - H[i].first);
			LL diff = dp[i-1][j] - allin;
			while (mpq.size() && diff <= mpq.back().first) {
				mpq.pop_back();
			}
			// error(allin, diff);
			mpq.push_back({diff, j});
			while (j - mpq.front().second > H[i].second) {
				mpq.pop_front();
			}
			dp[i][j] = allin + mpq.front().first;
			// error(i, j, dp[i][j]);
		}
	}

	cout << dp[M][N-1] << endl;
	return 0;
}