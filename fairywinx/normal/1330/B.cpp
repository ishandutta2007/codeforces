#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>

// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int ,int>> res;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> cnt(n);
	vector<int> cnt1(n);
	int kol_1 = 0, kol_2 = 0;
	int mx = 0;
	multiset<int> z;
	int kol_11 = 0, kol_22 = 0;
	for(int i = 0; i < n; ++i) {
		z.insert(a[i]);
		++cnt1[a[i]];
		if (cnt1[a[i]] == 1)
			++kol_11;
		else if (cnt1[a[i]] == 2)
			--kol_11, ++kol_22;
	}
	for(int i = 0; i < n - 1; ++i) {
		if (cnt1[a[i]]-- == 1) {
			--kol_11;
			z.erase(z.find(a[i]));
		}
		else if (cnt1[a[i]] == 1) {
			--kol_22;
			++kol_11;
		}
		if (++cnt[a[i]] == 1) {
			++kol_1;
			mx = max(mx, a[i]);
		}
		else if (cnt[a[i]] > 1)
			++kol_2;
		if (kol_2 == 0 && kol_1 == mx && kol_22 == 0 && *z.rbegin() == kol_11) {
			res.emplace_back(kol_1, kol_11);
		}
	}
	cout << res.size() << '\n';
	for(auto i: res)
		cout << i.first << ' ' << i.second << '\n';
}
signed main() {
	setup();
	SOLVE;



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}