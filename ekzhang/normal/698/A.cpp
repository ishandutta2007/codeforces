#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 113
int N;
bool A[MAXN][2];
int dp[MAXN][3];

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A[i][0] = (x & 1);
		A[i][1] = (bool) (x & 2);
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = MAXN;
		if (A[i-1][0]) {
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
		}
		if (A[i-1][1]) {
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		}
		dp[i][2] = 1 + min(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
	}

	cout << min(dp[N][1], dp[N][0], dp[N][2]) << endl;
	return 0;
}