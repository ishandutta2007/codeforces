#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, m;
	cin >> n >> m;
	if (m < n) {
		cout << "No" << endl;
		return;
	}
	if (n % 2) {
		cout << "Yes" << endl;
		rep(i,0,n-1)
			cout << "1 ";
		cout << m-n+1 << endl;
		return;
	}
	if ((n%2) == 0 && (m%2)) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	rep(i,0,n-2)
		cout << "1 ";
	cout << (m-n)/2+1 << " ";
	cout << (m-n)/2+1 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}