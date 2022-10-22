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

bool ydj[22][362], xdj[22][362];
bool chk[22][362];

bool ans = 0;
void dfs(int r, int o){
	chk[r][o] = 1; if (r == 20){ ans = 1; return; }
	if (!ydj[r+1][o] && !chk[r+1][o]){ dfs(r+1, o); }
	if (r > 0 && !ydj[r][o] && !chk[r-1][o]){ dfs(r-1, o); }
	if (!xdj[r][(o+1)%360] && !chk[r][(o+1)%360]){ dfs(r, (o+1)%360); }
	if (!xdj[r][o] && !chk[r][(o+359)%360]){ dfs(r, (o+359)%360); }
}

int main() {
	fastio;
	int t; cin >> t;
	while (t--){
		memset(ydj, 0, sizeof(ydj)); memset(xdj, 0, sizeof(xdj));
		int n; cin >> n;
		while (n--){
			char typ; cin >> typ;
			if (typ == 'C'){
				int r, o1, o2; cin >> r >> o1 >> o2;
				for (int i = o1; i != o2; i=(i+1)%360){
					ydj[r][i] = 1;
				}
			}
			if (typ == 'S'){
				int r1, r2, o; cin >> r1 >> r2 >> o;
				for (int i = r1; i < r2; i++){
					xdj[i][o] = 1;
				}
			}
		}
		memset(chk, 0, sizeof(chk));
		ans = 0; dfs(0, 0);
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}