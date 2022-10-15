#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXN 213
#define MAXM 213
#define MAXLG 48
#define NINF (-(1LL << 60))
int N;
LL L;
int A[MAXN];
string lines[MAXN];

int M; // number of nodes in the trie
int g[MAXM][26]; // trie graph
int f[MAXM]; // "fail" function
int out[MAXM]; // "output"

LL dp[MAXLG][MAXM][MAXM];
LL ans[2][MAXM][MAXM];

int aho_corasick() {
	memset(g, -1, sizeof g);
	memset(out, 0, sizeof out);

	int nodes = 1;

	// iterate through the pickup lines (patterns)
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (int j = 0; j < lines[i].size(); j++) {
			// error(lines[i][j]);
			if (g[cur][lines[i][j] - 'a'] == -1) {
				g[cur][lines[i][j] - 'a'] = nodes++;
			}
			cur = g[cur][lines[i][j] - 'a'];
		}
		// error(cur);
		out[cur] += A[i];
	}

	// goto edges from state 0 to itself
	for (int i = 0; i < 26; i++) {
		if (g[0][i] == -1) {
			g[0][i] = 0;
		}
	}

	memset(f, -1, sizeof f);

	// BFS time! (calculate the fail function)
	queue<int> q;
	for (int ch = 0; ch < 26; ch++) {
		if (g[0][ch] != 0) {
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (!q.empty()) {
		int state = q.front();
		q.pop();

		for (int ch = 0; ch < 26; ch++) {
			if (g[state][ch] == -1) continue;

			int fail = f[state];
			while (g[fail][ch] == -1) {
				fail = f[fail];
			}

			f[g[state][ch]] = g[fail][ch];
			out[g[state][ch]] += out[f[g[state][ch]]];

			q.push(g[state][ch]);
		}
	}

	return nodes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> lines[i];
	}

	// ok build the aho-corasick prefix automation
	M = aho_corasick();

	// now build the matrices
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			ans[0][i][j] = NINF;
			for (int k = 0; k < MAXLG; k++) {
				dp[k][i][j] = NINF;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		// ans is currently at 0-steps
		ans[0][i][i] = 0;

		// dp[0] is at 2^0 = 1st step
		for (int ch = 0; ch < 26; ch++) {
			int nex = i;
			while (g[nex][ch] == -1) {
				nex = f[nex];
			}

			dp[0][i][g[nex][ch]] = out[g[nex][ch]];
		}
	}

	// okay calculate the sparse table now!
	for (int lg = 1; lg < MAXLG; lg++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) {
					dp[lg][i][j] = max(dp[lg][i][j],
							dp[lg - 1][i][k] + dp[lg - 1][k][j]);
				}
			}
		}
	}

	int d = 0;
	for (int lg = MAXLG - 1; lg >= 0; lg--) {
		LL x = (1LL<<lg);
		if (L - x >= 0) {
			L -= x;
			d ^= 1;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < M; j++) {
					ans[d][i][j] = NINF;
					for (int k = 0; k < M; k++) {
						ans[d][i][j] = max(ans[d][i][j],
								ans[!d][i][k] + dp[lg][k][j]);
					}
				}
			}
		}
	}

	LL finalans = NINF;
	for (int i = 0; i < M; i++) {
		finalans = max(finalans, ans[d][0][i]);
	}

	cout << finalans << endl;
	return 0;
}