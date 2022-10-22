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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a*d == b*c)
		cout << "0" << endl;
	else if (!a || !c || (a*d)%(b*c) == 0 || (b*c)%(a*d) == 0)
		cout << "1" << endl;
	else
		cout << "2" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}