#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

string s;
int pos;

vector<int> ar;
vector<int> ans;
vector<int> buf;

void handle(int l, int r, bool fill_ans = false) {
	if (r - l <= 1) {
		return;
	}
	int m = (l + r) / 2;
	handle(l, m, fill_ans);
	handle(m, r, fill_ans);
	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (pos >= (int)s.size()) {
			pos = (int)s.size() + 1;
			return;
		}
		if (s[pos] == '0') {
			if (fill_ans) {
				buf[k++] = ans[i];
			}
			++i;
		} else {
			if (fill_ans) {
				buf[k++] = ans[j];
			}
			++j;
		}
		++pos;
	}
	if (fill_ans) {
		while (i < m) {
			buf[k++] = ans[i++];
		}
		while (j < r) {
			buf[k++] = ans[j++];
		}
		for (int it = l; it < r; ++it) {
			ans[it] = buf[it];
		}
	}
}

int main() {
	cin >> s;
	int l = 1, r = 2e5;
	while (r > l + 1) {
		int m = (l + r) / 2;
		pos = 0;
		handle(0, m);
		if (pos > (int)s.size()) {
			r = m;
		} else {
			l = m;
		}
	}

	int n = l;
	pos = 0;
	ans.resize(n);
	iota(all(ans), 0);
	buf.resize(n);
	handle(0, n, true);
	assert(pos == (int)s.size());

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[ans[i]] = i;
	}
	cout << n << "\n";
	for (int i = 0; i < n; ++i) {
		cout << p[i] + 1 << " ";
	}
	cout << "\n";

	return 0;
}