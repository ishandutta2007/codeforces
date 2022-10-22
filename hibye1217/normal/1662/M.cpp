#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define all(v) (v).begin(), (v).end()
#define rmin(r, x) r = min(r, x)
#define rmax(r, x) r = max(r, x)
#define ends ' '
#define endl '\n'
#define rep(i, s, e) for(int i = s; i <= e; ++i)
#define print(v) copy(all(v), ostream_iterator<int>(cout, " ")), cout << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	fastio;
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int rm = 0, wm = 0;
		while (m--){
			int r, w; cin >> r >> w;
			rm = max(r, rm); wm = max(w, wm);
		}
		//cout << rm << ' ' << wm << endl;
		if (rm+wm > n){ cout << "IMPOSSIBLE" << endl; }
		else{
			for (int i = 1; i <= rm; i++){ cout << "R"; }
			for (int i = rm+1; i <= n; i++){ cout << "W"; }
			cout << endl;
		}
	}
	return 0;
}