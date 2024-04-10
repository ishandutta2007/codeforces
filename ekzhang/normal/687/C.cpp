#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 502
#define MAXK 502

int N, K;
int C[MAXN];
bool dp[MAXN][MAXK][MAXK];
bool ans[MAXK];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	dp[0][0][0] = true;
	for (int a = 1; a <= N; a++) {
		for (int b = 0; b <= K; b++) {
			for (int c = 0; c <= K; c++) {
				dp[a][b][c] = dp[a - 1][b][c];
				if (b - C[a - 1] >= 0) {
					dp[a][b][c] |= dp[a - 1][b - C[a - 1]][c];
					if (c - C[a - 1] >= 0) {
						dp[a][b][c] |= dp[a - 1][b - C[a - 1]][c - C[a - 1]];
					}
				}
			}
		}
	}

	vector<int> good;
	for (int c = 0; c <= K; c++) {
		if (dp[N][K][c]) {
			good.push_back(c);
		}
	}

	cout << good.size() << '\n';
	for (int x : good) {
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}