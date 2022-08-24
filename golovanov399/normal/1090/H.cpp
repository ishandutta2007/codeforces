#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int L = 18;
const int N = 1 << L;

int cnt[L][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n = nxt();
	string s;
	cin >> s;

	vector<int> a(n - 1);
	for (itn i = 0; i < n - 1; ++i) {
		a[i] = (s[i] - '0') ^ (s[i + 1] - '0');
	}
	for (int l = 0; l < L; ++l) {
		int ll = 1 << l;
		for (int i = 0; i < n - 1; ++i) {
			cnt[l][i] = a[i];
			if (i >= ll) {
				cnt[l][i] += cnt[l][i - ll];
			}
		}
	}

	int q = nxt();
	while (q--) {
		int l = nxt() - 1, r = nxt();
		int len = r - l;
		int cn = 0;
		for (int i = 0; (1 << i) < len; ++i) {
			int off = 1 << i;
			int tmp = cnt[i + 1][r - off];
			if (l >= off) {
				tmp -= cnt[i + 1][l - off];
			}
			tmp = min(tmp, (len >> (i + 1)) - tmp);
			cn += tmp;
		}
		cout << (cn + 1) / 2 << "\n";
	}

	return 0;
}