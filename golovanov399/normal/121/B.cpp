#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < 3; ++i) {
		a.push_back(-1);
	}

	map<vector<int>, int> S;
	int cur = 0;
	while (k) {
		while (cur < (int)a.size() - 1 && (a[cur] != 4 || a[cur + 1] != 7)) {
			++cur;
		}
		if (cur >= (int)a.size() - 1) {
			break;
		}
		vector<int> tmp = {cur, a[cur + 2], a[cur + 3]};
		if (S.count(tmp) && S[tmp] > k) {
			int q = S[tmp] - k;
			k %= q;
			if (k == 0) {
				k += q;
			}
		}
		S[tmp] = k;

		if (cur % 2) {
			a[cur--] = 7;
		} else {
			a[cur + 1] = 4;
		}
		--k;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}