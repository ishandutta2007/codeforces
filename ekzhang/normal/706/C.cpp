#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
#define INF (1LL<<60)
int N;
int C[MAXN];
string ar[MAXN][2];
LL dp[MAXN][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> ar[i][0];
		ar[i][1] = string(ar[i][0]);
		reverse(begin(ar[i][1]), end(ar[i][1]));
	}

	dp[0][1] = C[0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i][1] = INF;
		if (ar[i][0] >= ar[i-1][0]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
		if (ar[i][1] >= ar[i-1][0]) dp[i][1] = min(dp[i][1], dp[i-1][0] + C[i]);
		if (ar[i][0] >= ar[i-1][1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
		if (ar[i][1] >= ar[i-1][1]) dp[i][1] = min(dp[i][1], dp[i-1][1] + C[i]);
	}

	LL ans = min(dp[N-1][0], dp[N-1][1]);
	if (ans >= INF) ans = -1;
	cout << ans << endl;
	return 0;
}