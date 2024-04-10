#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.rbegin(), x.rend()
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve()
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

#define int long long

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
	//srand(time(NULL));
}

void solve() {

}

signed main() {
	setup();
	//SOLVE;
	
	int n;
	cin >> n;
	vector<pair<int, int>> a;
	int ans = 0;
	int kol_v = 0;
	fr(i, n) {
		int m;
		cin >> m;
		pair<int, int> z;
		z.second = 1e9;
		vi p(m);
		ci(p);
		bool v = false;
		for(int j = 0; j < m - 1; ++j) {
			if (p[j] < p[j + 1])
				v = true;
		}
		if (v)
			++kol_v;
		else {
			fr(j, m) {
				z.second = min(z.second, p[j]);
				z.first = max(z.first, p[j]);
			}
			a.push_back(z);
		}
	}
	sort(all(a));
	fr(i, a.size()) {
		int l = -1, r = a.size();
		while(r - l > 1) {
			int m = (l + r) / 2;
			//cout << m << ' ' << a[m].first << ' ' << a[i].second << '\n';
			if (a[m].first > a[i].second)
				l = m;
			else 
				r = m;
		}
		//cout << l << ' ' << a[l].first << ' ' << a[i].second << '\n';
		ans += l + 1;
	}
	ans += kol_v * (n - kol_v) * 2 + (kol_v * kol_v);
	cout << ans;
}