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

int x[1000005];

void solve() {
	int a, b;
	cin >> a >> b;
	if (x[a-1] == b) {
		cout << a << endl;
		return;
	}
	int c = x[a-1]^b;
	if (c == a)
		cout << a+2 << endl;
	else
		cout << a+1 << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	x[0] = 0;
	for (int i = 1; i <= 1000000; i++)
		x[i] = x[i-1]^i;
	int T;
	cin >> T;
	while (T--)
		solve();
}