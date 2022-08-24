#include <bits/stdc++.h>

using namespace std;

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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

const int N = 5055;
short balp[N][N];
short baln[N][N];

int ball[N];

int main() {
	string s;
	cin >> s;

	memset(balp, -1, sizeof(balp));
	memset(baln, -1, sizeof(baln));

	int n = s.length();
	for (int i = 0; i < n; ++i) {
		int bal = 0;
		balp[i][i] = 0;
		for (int j = i; j < n; ++j) {
			if (s[j] == ')') {
				bal -= 1;
			} else {
				bal += 1;
			}
			if (bal < 0) {
				break;
			} else {
				balp[i][j + 1] = bal;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int bal = 0;
		baln[i + 1][i + 1] = 0;
		for (int j = i; j >= 0; --j) {
			if (s[j] == '(') {
				bal -= 1;
			} else {
				bal += 1;
			}
			if (bal < 0) {
				break;
			} else {
				baln[j][i + 1] = bal;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		ball[i + 1] = ball[i];
		if (s[i] == '(') {
			++ball[i + 1];
		} else if (s[i] == ')') {
			--ball[i + 1];
		}
	}

	vector<int> cnt(n + 1);
	for (int i = 0; i < n; ++i) {
		cnt[i + 1] = cnt[i] + (s[i] == '?');
	}
	vector<int> min_ind(n + 1, -1);
	for (int i = n; i >= 0; --i) {
		min_ind[cnt[i]] = i;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int len = 2; i + len <= n; len += 2) {
			int j = i + len;
			int bal = ball[j] - ball[i];
			int cn = cnt[j] - cnt[i];
			// pos + neg = cn
			// neg - pos = bal
			int pos = cn - bal;
			pos /= 2;
			if (pos < 0 || pos > cn) {
				continue;
			}

			int ind = min_ind[cnt[i] + pos];

			if (pos == 0) {
				if (baln[i][j] == 0) {
					++ans;
				}
			} else if (pos == cn) {
				if (balp[i][j] == 0) {
					++ans;
				}
			} else {
				if (balp[i][ind] == baln[ind][j] && balp[i][ind] > -1) {
					++ans;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}