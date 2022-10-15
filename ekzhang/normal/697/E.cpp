#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXK 100013
#define MOD 1000000007
#define INV2 500000004
#define INV3 333333336
#define MAXLG 61

int K;
LL A[MAXK];
LL dp[MAXLG];
LL c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> K;
	bool odd = true;
	for (int i = 0; i < K; i++) {
		cin >> A[i];
		if (A[i] % 2 == 0) {
			odd = false;
		}
	}

	c = 2;
	for (int i = 0; i < K; i++) {
		// calc dp
		dp[0] = c;
		for (int i = 1; i < MAXLG; i++) {
			dp[i] = (dp[i - 1] * dp[i - 1]) % MOD;
		}
		A[i]--;
		for (int j = MAXLG - 1; j >= 0; j--) {
			LL x = (1LL<<j);
			if (A[i] - x >= 0) {
				A[i] -= x;
				c *= dp[j];
				c %= MOD;
			}
		}
	}

	// error(dp[1]);

	LL d = (c * INV2) % MOD;
	LL n = ((d + (odd ? -1 : 1)) * INV3) % MOD;

	cout << n << '/' << d << endl;
	return 0;
}