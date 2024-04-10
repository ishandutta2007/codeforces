#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXM 700013
#define MOD 1000003
#define MAXLG 22
LL N, C;
LL dp[MAXLG];

LL inv(LL x) {
	dp[0] = x;
	for (int i = 1; i < MAXLG; i++) {
		dp[i] = (dp[i - 1] * dp[i - 1]) % MOD;
	}
	int p = MOD - 2;
	LL ans = 1;
	for (int i = MAXLG - 1; i >= 0; i--) {
		if (p >= (1<<i)) {
			p -= (1<<i);
			ans = (ans * dp[i]) % MOD;
		}
	}
	return ans;
}

int main() {
	/* Compute C(N+C, C) - 1 and output */
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> C;
	LL ans = 1;
	for (int i = 0; i < N; i++) {
		ans = (ans * (N + C - i)) % MOD;
		ans = (ans * inv(i + 1)) % MOD;
	}

	cout << ans - 1 << endl;
	return 0;
}