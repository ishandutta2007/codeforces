#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

const int MAXN = 111111;
int dp[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	string s = read<string>();
	for (int i = 2; i <= sz(s); ++i) {
		dp[i] = dp[i - 1] + (s[i - 1] == s[i - 2]);
	}
	int m = read();
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a] << endl;
	}
	return 0;
}