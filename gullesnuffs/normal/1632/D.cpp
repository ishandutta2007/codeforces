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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> g(20, vector<int>(n));
	rep(i,0,n) {
		cin >> a[i];
		g[0][i] = a[i];
	}
	rep(i,1,20) {
		rep(j,0,n+1-(1<<i)) {
			g[i][j] = __gcd(g[i-1][j], g[i-1][j+(1<<(i-1))]);
		}
	}
	int last_ok = -1;
	int ans = 0;
	rep(i,0,n) {
		int lo = 0, hi = i+2;
		bool ok = true;
		while (hi-lo > 1) {
			int mid = (lo+hi)/2;
			if (i-mid < last_ok) {
				hi = mid;
				continue;
			}
			int x = 0;
			while((2<<x) < mid)
				x++;
			int G=__gcd(g[x][i-mid+1], g[x][i-(1<<x)+1]);
			if (G == mid) {
				ok = false;
				break;
			}
			if (G > mid) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		if (!ok) {
			last_ok = i;
			++ans;
		}
		cout << ans << " ";
	}
	cout << endl;
}