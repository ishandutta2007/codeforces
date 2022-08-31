#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve(int n) {
	vector<int> p = {0};
	vector<int> q = {0, 1};
	while ((int)p.size() * 2 + 1 <= n) {
		int sz = p.size();
		p.push_back(0);
		for (int i = 0; i < sz; ++i) {
			p.push_back(p[i] ^ 1);
		}
		for (int i = 0; i <= sz; ++i) {
			q.push_back(q[i] ^ 1);
		}
	}
	reverse(all(p));
	reverse(all(q));

	int ans = 0;
	for (int c : {0, 1}) {
		int cnt = 0;
		int cur = c;
		for (int j = 0; j < (int)p.size(); ++j) {
			if (p[j] != cur) {
				assert(q[j] == cur);
				++cnt;
				cur ^= 1;
			}
			++cnt;
			cur ^= 1;
		}
		if (cnt == n) {
			++ans;
		}
		if (q.back() == cur && cnt + 1 == n) {
			++ans;
		}
	}

	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	solve(n);

	return 0;
}