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
	ll hc, dc, hm, dm, k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	rep(i,0,k+1) {
		ll DC = dc + w * i;
		ll HC = hc + a * (k - i);
		ll monster_dies = (hm + DC - 1) / DC;
		ll character_dies = (HC + dm - 1) / dm;
		if (monster_dies <= character_dies) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}