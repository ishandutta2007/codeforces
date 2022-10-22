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
	vector<int> sorted = a;
	sort(all(sorted));
	int lo = -1, hi = n+5;
	int x, y;
	while (hi-lo > 1) {
		int mid = (lo+hi)/2;
		int i = 0, j = 0;
		int max_good = 0;
		int xtmp, ytmp;
		while (j < n) {
			j++;
			while (sorted[j-1] > sorted[i]+mid) {
				i++;
			}
			if (j-i > max_good) {
				max_good = max(max_good, j-i);
				xtmp = sorted[i];
				ytmp = sorted[j-1];
			}
		}
		if (max_good >= n-max_good+k) {
			hi = mid;
			x = xtmp;
			y = ytmp;
		} else {
			lo = mid;
		}
	}
	assert(y-x == hi);
	cout << x << " " << y << endl;
	int i = 0;
	vector<pair<int, int>> ans;
	while (i < n) {
		int good = 0;
		int bad = 0;
		int j = i;
		while (bad >= good && j < n) {
			if (a[j] >= x && a[j] <= y)
				++good;
			else
				++bad;
			++j;
		}
		ans.emplace_back(i+1, j);
		i = j;
	}
	while (sz(ans) > k) {
		auto b = make_pair(ans[sz(ans)-2].first, ans.back().second);
		ans.pop_back();
		ans.pop_back();
		ans.push_back(b);
	}
	for (auto b : ans) {
		cout << b.first << " " << b.second << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) solve();
}