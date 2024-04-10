#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXW 113
#define MOD 1000003LL
LL C, W, H;
LL dp[MAXW + 1];
LL ans = 0;
LL t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> C >> W >> H;
	dp[0] = 1;
	LL hash = 0;

	t = 1;
	for (int i = 0; i < W; i++) {
		t *= H;
		t %= MOD;
	}

	LL p = 0;
	for (int i = 1; i <= C + 1; i++) {
		int idx = i % (W + 1);
		
		// roll the hash
		hash += MOD * MOD - t * p;
		hash %= MOD;
		hash *= H;
		hash += dp[(idx + W) % (W + 1)];
		hash %= MOD;

		// update dp
		p = dp[idx];
		dp[idx] = hash;
		// error(i, dp[idx]);
	}

	cout << hash << endl;
	return 0;
}