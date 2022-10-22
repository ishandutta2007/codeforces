#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve2(string s) {
	int n = sz(s);
	vector<int> asum(n+1);
	auto bsum = asum;
	auto csum = asum;
	auto bdiff = asum;
	auto cdiff = asum;
	rep(i,1,n+1) {
		asum[i] = asum[i-1];
		bsum[i] = bsum[i-1];
		csum[i] = csum[i-1];
		if (s[i-1] == 'a')
			asum[i]++;
		if (s[i-1] == 'b')
			bsum[i]++;
		if (s[i-1] == 'c')
			csum[i]++;
		bdiff[i] = bsum[i] - asum[i];
		cdiff[i] = csum[i] - asum[i];
	}
	map<int, map<int, int>> c_for_b;
	int ans = n+1;
	rep(i,0,n+1) {
		const auto& m = c_for_b[bdiff[i]+1];
		auto it = m.upper_bound(cdiff[i]);
		if (it != m.end()) {
			ans = min(ans, i-it->second);
		}
		if (i) {
			auto& m2 = c_for_b[bdiff[i-1]];
			m2[cdiff[i-1]] = i-1;
			while (m2.begin()->first < cdiff[i-1])
				m2.erase(m2.begin());
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = solve2(s);
	rep(i,0,n) {
		if (s[i] == 'b')
			s[i] = 'c';
		else if (s[i] == 'c')
			s[i] = 'b';
	}
	ans = min(ans, solve2(s));
	rep(i,0,n-1) {
		if (s[i] == 'a' && s[i+1] == 'a')
			ans = 2;
	}
	/*rep(i,0,n-2) {
		if (s[i] == 'a' && s[i+2] == 'a')
			ans = min(ans, 3);
	}*/
	if (ans > n)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}