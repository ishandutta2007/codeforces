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
	vector<ll> a(n);
	vector<pair<ll, int>> scores;
	rep(i,0,n) {
		cin >> a[i];
		scores.emplace_back(a[i]+i, i);
	}
	sort(all(scores));
	reverse(all(scores));
	vector<bool> jump(n);
	rep(i,0,k)
		jump[scores[i].second] = true;
	ll ans = 0;
	ll num_jumped = 0;
	rep(i,0,n) {
		if (jump[i]) {
			++num_jumped;
		} else {
			ans += num_jumped+a[i];
		}
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}