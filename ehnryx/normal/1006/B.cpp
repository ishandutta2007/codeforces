#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	int a[n+1];
	vector<pii> idx;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		idx.push_back(pii(a[i], i));
	}
	sort(idx.begin(), idx.end(), greater<pii>());

	vector<int> ans;
	int val = 0;
	for (int i=0; i<k; i++) {
		ans.push_back(idx[i].second);
		val += idx[i].first;
	}
	sort(ans.begin(), ans.end());
	ans.back() = n;

	cout << val << nl;
	int pre = 0;
	for (int i=0; i<k; i++) {
		cout << ans[i] - pre << " ";
		pre = ans[i];
	}
	cout << nl;

	return 0;
}