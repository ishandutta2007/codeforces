#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
	int ans = n;
	rep(i,0,sz(s)-1) {
		if (s[i] == ')' && s[i+1] == '(')
			--ans;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}