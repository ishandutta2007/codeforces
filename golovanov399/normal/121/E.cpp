#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

bool isLucky(int n) {
	while (n) {
		if (n % 10 == 4 || n % 10 == 7) {
			// pass
		} else {
			return false;
		}
		n /= 10;
	}
	return true;
}

const int BLOCK = 300;
const int N = 111111;
const int M = 11111;

int add[N / BLOCK];
int cnt[N / BLOCK][M];
int a[N];
int lucky[M];

int main() {
	cin.sync_with_stdio(0);

	for (int i = 1; i < M; ++i) {
		lucky[i] = isLucky(i);
	}
	vector<int> ln;

	for (int i = 1; i < M; ++i) {
		if (lucky[i]) {
			ln.push_back(i);
		}
	}

	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		cnt[i / BLOCK][a[i]] += 1;
	}

	#define num a

	while (m--) {
		string s;
		cin >> s;
		if (s == "add") {
			int l = nxt() - 1, r = nxt(), d = nxt();
			int num_it = (BLOCK - l % BLOCK) % BLOCK;
			if (l + num_it >= r) {
				num_it = r - l;
			}
			int block = l / BLOCK;
			for (int i = 0; i < num_it; ++i) {
				cnt[block][num[l + i]] -= 1;
				num[l + i] += d;
				cnt[block][num[l + i]] += 1;
			}
			l += num_it;
			block = l / BLOCK;
			while (l + BLOCK <= r) {
				add[block++] += d;
				l += BLOCK;
			}
			while (l < r) {
				cnt[block][num[l]] -= 1;
				num[l] += d;
				cnt[block][num[l]] += 1;
				++l;
			}
		} else {
			int l = nxt() - 1, r = nxt();
			int ans = 0;

			int num_it = (BLOCK - l % BLOCK) % BLOCK;
			if (l + num_it >= r) {
				num_it = r - l;
			}
			int block = l / BLOCK;
			for (int i = 0; i < num_it; ++i) {
				if (lucky[add[block] + num[l + i]]) {
					++ans;
				}
			}
			l += num_it;
			block = l / BLOCK;
			while (l + BLOCK <= r) {
				for (int x : ln) {
					if (x > add[block]) {
						ans += cnt[block][x - add[block]];
					}
				}
				++block;
				l += BLOCK;
			}
			while (l < r) {
				if (lucky[add[block] + num[l]]) {
					++ans;
				}
				++l;
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}