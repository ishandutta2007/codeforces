#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	bool has_good = false;
	int ones = 0;
	rep(i,0,n) {
		cin >> a[i];
		rep(j,0,m) {
			ones += a[i][j] - '0';
		}
	}
	rep(i,0,n-1)
	rep(j,0,m-1) {
		rep(s1,0,2)
		rep(s2,0,2) {
			int sum = 0;
			rep(t1,0,2)
			rep(t2,0,2) {
				sum += a[i+t1][j+t2]-'0';
			}
			sum -= a[i+s1][j+s2]-'0';
			if (sum == 1) {
				has_good = true;
			}
		}
	}
	if (ones == n*m) {
		cout << n*m-2 << endl;
	} else if (ones == 0) {
		cout << 0 << endl;
	} else if (has_good) {
		cout << ones << endl;
	} else {
		cout << ones-1 << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}