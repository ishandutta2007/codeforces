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
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> p(m);
	unordered_map<ll, int> posToInd;
	rep(i,0,m) {
		cin >> p[i].second >> p[i].first;
		posToInd[p[i].second] = i+1;
	}
	sort(all(p));
	vector<ll> q;
	ll ans = 0;
	rep(i,0,2*n) {
		ans += p[i].first;
		q.push_back(p[i].second);
	}
	sort(all(q));
	cout << ans << endl;
	rep(i,0,n) {
		cout << posToInd[q[i]] << " " << posToInd[q[2*n-1-i]] << endl;
	}
	cout << endl;
	//vector<pair<int, int>> pairs;
//	rep(i,0,n) {
//		pairs.emplace
//	}

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}