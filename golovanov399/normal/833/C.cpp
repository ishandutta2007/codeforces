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

long long l, r;
int cnt;
int init;
string sl, sr;

int ans;
vector<int> cnts;

int v[20];

void rec(int digit, int cur) {
	if (digit == 10) {
		for (int i = sl[init] - '0' + 1; i < sr[init] - '0'; ++i) {
			if (cnts[i]) {
				ans += 1;
				return;
			}
		}
		int sz = 0;
		bool ok = false;
		if (cnts[sl[init] - '0']) {
			ok = true;
			for (int i = 0; i < 10; ++i) {
				int cn = (i == sl[init] - '0' ? cnts[i] - 1 : cnts[i]);
				for (int j = 0; j < cn; ++j) {
					v[sz++] = i;
				}
			}
			for (int i = init + 1; i < cnt; ++i) {
				--sz;
				if (v[sz] + '0' > sl[i]) {
					ans += 1;
					return;
				} else if (v[sz] + '0' < sl[i]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans += 1;
			return;
		}
		sz = 0;
		if (cnts[sr[init] - '0']) {
			ok = true;
			for (int i = 9; i >= 0; --i) {
				int cn = (i == sr[init] - '0' ? cnts[i] - 1 : cnts[i]);
				for (int j = 0; j < cn; ++j) {
					v[sz++] = i;
				}
			}
			for (int i = init + 1; i < cnt; ++i) {
				--sz;
				if (v[sz] + '0' < sr[i]) {
					ans += 1;
					return;
				} else if (v[sz] + '0' > sr[i]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans += 1;
			return;
		}
	} else {
		int i = 0;
		if (digit == 9) {
			i = cnt - cur;
			cnts[digit] = i;
		}
		for (; cur + i <= cnt; ++i) {
			rec(digit + 1, cur + i);
			cnts[digit] += 1;
		}
		cnts[digit] = 0;
	}
}

int main() {
	cin >> l >> r;
	sl = to_string(l);
	sr = to_string(r);

	cnt = max(sl.size(), sr.size());
	cnts.assign(10, 0);

	while ((int)sl.length() < cnt) {
		sl = "0" + sl;
	}
	while ((int)sr.length() < cnt) {
		sr = "0" + sr;
	}

	int cur = 0;
	while (cur < cnt && sl[cur] == sr[cur]) {
		++cur;
	}
	if (cur == cnt) {
		puts("1");
		return 0;
	}

	// cerr << sl << " " << sr << "\n";

	init = cur;
	rec(0, cur);

	printf("%d\n", ans);

	return 0;
}