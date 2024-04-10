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
	int n;
	cin >> n;
	vector<int> d(n);
	int sum = 0;
	rep(i,0,n) {
		cin >> d[i];
	}
	rep(i,0,n) {
		if (d[i] && d[i] <= sum) {
			cout << "-1" << endl;
			return;
		}
		sum += d[i];
	}
	sum = 0;
	rep(i,0,n) {
		sum += d[i];
		cout << sum << " ";
	}
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}