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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,0,n)
		cin >> a[i];
	auto b = a;
	sort(all(b));
	map<int, int> nextVal;
	rep(i,0,n-1) {
		nextVal[b[i]] = b[i+1];		
	}
	int ans = n;
	rep(i,0,n-1) {
		if (nextVal.count(a[i]) && a[i+1] == nextVal[a[i]])
			--ans;
	}
	puts((ans <= k)?"Yes":"No");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}