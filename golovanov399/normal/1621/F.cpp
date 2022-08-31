#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), a = nxt(), b = nxt(), c = nxt();
	string s;
	cin >> s;
	int can_z = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '0' && s[i + 1] == '0') {
			++can_z;
		}
	}
	int zs = count(all(s), '0');
	vector<int> cnts;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			continue;
		}
		int j = i + 1;
		while (j < n && s[j] == '0') {
			++j;
		}
		if (j < n) {
			cnts.push_back(j - i - 1);
		}
	}
	sort(all(cnts));
	long long ans = 0;
	for (int before : {0, 1}) {
		long long cur = 0;
		int free_ops = before - 1;
		int can_lone_z = zs - can_z;
		int can_just_z = can_z;
		for (int i = 0; i <= (int)cnts.size(); ++i) {
			int ez = min(free_ops, can_just_z);
			int bad = free_ops - ez;
			if (ez < can_just_z) {
				++ez;
			}
			if (bad > can_lone_z) {
				break;
			}
			// cerr << before << " " << i << ": " << free_ops << "\n";
			// cerr << before << ": " << cur << ", " << ez << " " << i << " " << bad << "\n";
			// cerr << before << " " << i << ": " << free_ops << " " << cur << " " << cur + 1ll * ez * a - 1ll * bad * c << "\n";
			ans = max(ans, cur + 1ll * ez * a - 1ll * bad * c);

			if (i == (int)cnts.size()) {
				break;
			}
			int cnt = cnts[i];
			cur += b;
			if (cnt) {
				cur += 1ll * (cnt - 1) * a - c;
			}
			free_ops -= cnt;
			free_ops += 1;
			can_lone_z -= !!cnt;
			can_just_z -= max(0, cnt - 1);
			if (free_ops < 0) {
				break;
			}
		}
	}
	// for (int cnt_2 = 0, necessary = 0; cnt_2 <= (int)cnts.size(); ++cnt_2) {
	// 	if (necessary <= cnt_2 + 1) {
	// 		int max_ez = cnt_2 + 1 - necessary;
	// 		int ez = min(max_ez, can_z);
	// 		int need_z = max_ez - ez;
	// 		if (need_z > 0) {
	// 			need_z -= 2;
	// 		}
	// 	}
	// 	if (cnt_2 < (int)cnts.size()) {
	// 		necessary += cnts[cnt_2];
	// 	}
	// }
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}