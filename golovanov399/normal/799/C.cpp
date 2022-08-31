#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int n = nxt();
	int res[2];
	for (int i = 0; i < 2; ++i) {
		res[i] = nxt();
	}

	vector<vector<pair<int, int>>> fonts(2);
	for (int i = 0; i < n; ++i) {
		int b, p;
		char c;
		scanf("%d %d %c\n", &b, &p, &c);
		int idx = c - 'C';
		if (res[idx] < p) {
			continue;
		}
		fonts[idx].push_back({p, b});
	}
	for (int i = 0; i < 2; ++i) {
		sort(all(fonts[i]));
	}

	vector<vector<int>> mxs(2);
	for (int i = 0; i < 2; ++i) {
		for (auto x : fonts[i]) {
			if (mxs[i].empty()) {
				mxs[i].push_back(x.second);
			} else {
				int z = max(mxs[i].back(), x.second);
				mxs[i].push_back(z);
			}
		}
	}

	int ans = 0;
	if (!fonts[0].empty() && !fonts[1].empty()) {
		ans = max(ans, mxs[0].back() + mxs[1].back());
	}

	for (int idx = 0; idx < 2; ++idx) {
		int l = -1, r = (int)mxs[idx].size() - 1;
		while (r >= 0) {
			while (l + 1 < r && fonts[idx][l + 1].first + fonts[idx][r].first <= res[idx]) {
				++l;
			}
			if (l >= r) {
				l = r - 1;
			}
			if (l >= 0) {
				ans = max(ans, mxs[idx][l] + fonts[idx][r].second);
			}
			--r;
		}
	}

	printf("%d\n", ans);

	return 0;
}