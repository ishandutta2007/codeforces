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
	ll s;
	int n;
	cin >> s >> n;
	vector<ll> parts;
	ll ten = 1;
	while (s) {
		while (s%10) {
			parts.push_back(ten);
			s--;
		}
		s /= 10;
		ten *= 10;
	}
	sort(all(parts));
	rep(i,0,sz(parts)) {
		if (sz(parts) < n && parts[i] >= 10) {
			rep(j,0,9)
				parts.push_back(parts[i]/10);
			parts[i] = parts[i]/10;
			sort(all(parts));
		}
	}
	while (sz(parts) > n) {
		ll a = parts.back();
		parts.pop_back();
		a += parts.back();
		parts.pop_back();
		parts.push_back(a);
	}
	for (auto x : parts)
		cout << x << " ";
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}