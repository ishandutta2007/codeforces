#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	vector<vector<int>> children(n);
	rep(i,1,n) {
		cin >> p[i];
		--p[i];
		children[p[i]].push_back(i);
	}
	vector<int> depth(n);
	queue<int> q;
	vector<int> upwards;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		upwards.push_back(cur);
		q.pop();
		for (int c : children[cur]) {
			depth[c] = depth[cur]+1;
			q.push(c);
		}
	}
	reverse(all(upwards));
	upwards.pop_back();
	int lo = -1, hi = n+1;
	while (hi-lo > 1) {
		int mid = (lo+hi)/2;
		vector<int> height(n);
		int opers = 0;
		for (int v : upwards) {
			if (!p[v])
				continue;
			if (height[v] == mid) {
				++opers;
				height[v] = 0;
			} else {
				height[p[v]] = max(height[p[v]], height[v]+1);
			}
		}
		if (opers <= k) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi+1 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}