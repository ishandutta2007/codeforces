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

const int N = 30;
long long cnt[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	int n = s.length();
	vector<int> cur(N);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < N; ++j) {
			cnt[j][s[i] - 'a'] += cur[j];
		}
		cur[s[i] - 'a'] += 1;
	}
	long long ans = *max_element(all(cur));
	for (int i = 0; i < N; ++i) {
		ans = max(ans, *max_element(cnt[i], cnt[i] + N));
	}
	cout << ans << "\n";

	return 0;
}