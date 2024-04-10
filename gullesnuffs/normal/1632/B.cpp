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
	vector<bool> done(n);
	int x = n-1;
	cout << x << " ";
	while (true) {
		done[x] = true;
		bool d = false;
		rep(i,0,20) {
			if ((x^(1<<i)) < n && !done[x^(1<<i)]) {
				x ^= 1<<i;
				cout << x << " ";
				d = true;
				break;
			}
		}
		if (!d)
			break;
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) solve();
}