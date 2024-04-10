#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MOD 1000000007
typedef long long LL;
#define MAXN 13
int N, M, K;
int A[MAXN][MAXN];
int C[MAXN][MAXN];
int cur = 1;
LL ans = 0;
bool bad[33][MAXN];
int bi = 0;
int rightcolor[MAXN];
bool seen[MAXN];

void dfs(int idx) {
	if (idx == N * M) {
		// postcomputation
		memset(rightcolor, 0, sizeof rightcolor);
		memset(seen, 0, sizeof seen);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j]) {
					if (rightcolor[C[i][j]] && rightcolor[C[i][j]] != A[i][j]) {
						return;
					}
					else {
						rightcolor[C[i][j]] = A[i][j];
					}
				}
			}
		}
		int freedom = 0;
		LL curans = 1;
		for (int c = 1; c <= K; c++) {
			if (!rightcolor[c]) {
				++freedom;
			}
			else {
				if (seen[rightcolor[c]]) return;
				seen[rightcolor[c]] = true;
			}
		}
		for (int x = freedom; x > K - cur + 1; x--) {
			curans *= x;
		}
		// error(curans);
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < M; j++) {
		// 		cerr << C[i][j] << ' ';
		// 	}
		// 	cerr << endl;
		// }
		ans += curans;
		ans %= MOD;
		return;
	}
	int i = idx / M;
	int j = idx % M;
	if (cur <= K) {
		C[i][j] = cur++;
		dfs(idx+1);
		C[i][j] = 0;
		cur--;
	}
	for (int c = 1; c < cur; c++) {
		bad[bi][c] = false;
	}
	for (int i2 = 0; i2 <= i; i2++) {
		for (int j2 = 0; j2 <= j; j2++) {
			bad[bi][C[i2][j2]] = true;
		}
	}
	for (int c = 1; c < cur; c++) {
		if (!bad[bi][c]) {
			++bi;
			C[i][j] = c;
			dfs(idx+1);
			C[i][j] = 0;
			--bi;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	if (N + M - 1 > K) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	dfs(0);

	cout << ans << endl;
	return 0;
}