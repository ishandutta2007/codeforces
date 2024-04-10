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

int score(const vector<int>& a) {
	int res = a[0]-1;
	rep(i,0,sz(a)-1) {
		res = min(res, a[i+1]-a[i]-1);
	}
	return res;
}

int solve2(const vector<int>& a, int d) {
	int widest_gap = a[0]-1;
	rep(i,0,sz(a)-1) {
		widest_gap = max(widest_gap, a[i+1]-a[i]-1);
	}
	return min(score(a), max(d-a.back()-1, (widest_gap-1)/2));
}

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	rep(i,0,n)
		cin >> a[i];
	vector<int> worst;
	int res = a[0]-1;
	worst.push_back(0);
	rep(i,0,sz(a)-1) {
		int diff = a[i+1]-a[i]-1;
		if (diff < res) {
			res = diff;
			worst.clear();
			worst.push_back(i);
			worst.push_back(i+1);
		}
	}
	auto aorig = a;
	int ans = 0;
	for (int w : worst) {
		a = aorig;
		a.erase(a.begin()+w);
		ans = max(ans, solve2(a, d));
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