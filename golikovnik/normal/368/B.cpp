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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read(), m = read();
	vector<int> a(n);
	for (int &x: a) cin >> x;
	set<int> st;
	vector<int> dp(n);
	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1) {
			dp[i] = 1;
			st.insert(a[i]);
			continue;
		}
		dp[i] = dp[i + 1] + (st.find(a[i]) == st.end());
		st.insert(a[i]);
	}	
	for (int i = 0; i < m; ++i) {
		int L = read() - 1;
		cout << dp[L] << endl;
	}
	return 0;
}