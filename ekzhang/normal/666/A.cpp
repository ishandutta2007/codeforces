#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 10000

string S;
int N;
bool dp[MAXN][2]; // dp[][0] is length 2, dp[][1] is length 3

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> S;
	S = S.substr(5);
	N = S.size();

	for (int i = N - 1; i >= 0; i--) {
		if (i + 2 == N) {
			dp[i][0] = true;
		}
		else if (i + 2 < N) {
			if (dp[i + 2][1]) {
				dp[i][0] = true;
			}
			else if (dp[i + 2][0] && (S[i] != S[i + 2] || S[i + 1] != S[i + 3])) {
				dp[i][0] = true;
			}
		}

		if (i + 3 == N) {
			dp[i][1] = true;
		}
		else if (i + 3 < N) {
			if (dp[i + 3][0]) {
				dp[i][1] = true;
			}
			else if (dp[i + 3][1] && (S[i] != S[i + 3] || S[i + 1] != S[i + 4] || S[i + 2] != S[i + 5])) {
				dp[i][1] = true;
			}
		}
	}

	set<string> ans;
	for (int i = 0; i < N; i++) {
		if (dp[i][0]) {
			ans.insert(S.substr(i, 2));
		}
		if (dp[i][1]) {
			ans.insert(S.substr(i, 3));
		}
	}

	cout << ans.size() << '\n';
	for (string a : ans) {
		cout << a << '\n';
	}

	cout.flush();
	return 0;
}