// #define _GLIBCXX_DEBUG
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <string>
 
#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

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

const int N = 1e6 + 228;
const int osn = 239;
const int mod = 1e9 + 447;

int pw[N];

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	string z = s;
	int mxi = -1;
	// cout << z << ' ';
	for(int i = 0; i < n; ++i) {
		if (z[i] == z[n - 1 - i]) {
			mxi = i;
		}
		else
			break;
	}
	// cout << mxi << ' ';
	if (mxi + 1 == z.size()) {
		cout << z << '\n';
		return;
	}

	s = "";
	for(int i = mxi + 1; i < n - 1 - mxi; ++i) {
		s += z[i];
		// cout << z[i] << ' ';
	}
	n = s.size();
	vector<int> ans(n);
	vector<int> ch(n);
	ans[0] = 1;
	// cout << s << ' ';

	int l = 0, r = 0;
	for(int i = 1; i < n; ++i) {
		ans[i] = max((long long) 0, min(r - i, ans[l + r - i]));
		while(i - ans[i] >= 0 && i + ans[i] < n && s[i - ans[i]] == s[i + ans[i]]) ++ans[i];
		if (i + ans[i] - 1 > r) r = i + ans[i] - 1, l = i - ans[i] + 1;
	}
	l = 0, r = 0;
	for(int i = 1; i < n; ++i) {
		// cout << l << ' ' << r << ' ' << '\n';
		ch[i] = max((long long) 0, min(r - i + 1, ch[r - i + l + 1]));
		while(i + ch[i] < n && i - ch[i] - 1 >= 0 && s[i + ch[i]] == s[i - ch[i] - 1]) ++ch[i];
		if (i + ch[i] - 1 > r) l = i - ch[i], r = i + ch[i] - 1;
	}
	vector<int> d1(n);
	vector<int> d2(n);
	for(int i = 0; i < n; ++i) {
		d1[i - ans[i] + 1] = ans[i] * 2 - 1;
	}
	for(int i = 1; i < n; ++i) 
		d1[i] = max(d1[i], d1[i - 1] - 2);
	for(int i = 0; i < n; ++i) {
		d2[i - ch[i]] = ch[i] * 2;
	}
	int mx1 = max(d1[0], d2[0]);
	vector<int> _d2(n);
	vector<int> _d1(n);

	for(int i = 0; i < n; ++i) {
		_d1[d1[i] + i - 1] = max(d1[i], _d1[d1[i] + i - 1]);
		if (d2[i] != 0) _d2[d2[i] + i - 1] = max(d2[i], _d2[d2[i] + i - 1]);
	}
	// for(int i = 0; i < n; ++i) {
	// 	cout << d1[i] << ':' << d2[i] << ' ';
	// }
	int mx2 = max(_d1[n - 1], _d2[n - 1]);
	// cout << mxi << ' ' << mx1 << ' ' << mx2 << '\n';
	if (mx1 > mx2) {
		for(int i = 0; i <= mxi; ++i) 
			cout << z[i];
		for(int i = 0; i < mx1; ++i)
			cout << s[i];
		for(int i = z.size() - 1 - mxi; i < z.size(); ++i)
			cout << z[i];
	}
	else {
		for(int i = 0; i <= mxi; ++i) 
			cout << z[i];
		for(int i = n - mx2; i < n; ++i)
			cout << s[i];
		for(int i = z.size() - 1 - mxi; i < z.size(); ++i)
			cout << z[i];
	}
	cout << '\n';
}

signed main() {
	setup();
	SOLVE;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}