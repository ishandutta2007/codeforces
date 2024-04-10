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

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int num_ones = 0;
	rep(i,0,n)
		num_ones += (s[i] == '1');
	int num_zeroes = n - num_ones;
	vector<int> ans;
	rep(i,0,n) {
		if ((s[i] == '1' && i < num_zeroes) || (s[i] == '0' && i >= num_zeroes)) {
			ans.push_back(i);
		}
	}
	if (sz(ans) == 0)
		cout << "0" << endl;
	else {
		cout << "1" << endl << ans.size();
		for (int x : ans)
			cout << " " << x+1;
		cout << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}