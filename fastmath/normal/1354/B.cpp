#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
//#include <unordered_map>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}

#define int long long
#define right right228
#define left left228
#define all(v) v.begin(), v.end()

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	s = " " + s;
	map< char, int > cnt;
	int r = 0;
	int ans = n + 1;
	for (int i = 1; i <= n; ++i) {
		while (r + 1 <= n && (cnt['1'] == 0 || cnt['2'] == 0 || cnt['3'] == 0)) {
			++r;
			++cnt[s[r]];
		}
		if (cnt['1'] && cnt['2'] && cnt['3']){
			uin(ans, r - i + 1);
		}
		--cnt[s[i]];
	}
	if (ans == n + 1) ans = 0;
	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

/*


*/