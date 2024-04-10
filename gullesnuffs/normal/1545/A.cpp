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
	vector<int> a(n);
	rep(i,0,n) {
		cin >> a[i];
	}
	auto b = a;
	sort(all(b));
	map<int, int> left[2];
	rep(i,0,n) {
		left[i%2][b[i]]++;
	}
	bool ok = true;
	rep(i,0,n) {
		--left[i%2][a[i]];
		if (left[i%2][a[i]] < 0)
			ok = false;		
	}
	puts(ok?"YES":"NO");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}