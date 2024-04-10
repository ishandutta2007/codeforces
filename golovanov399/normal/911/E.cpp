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
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		a[i] = nxt() - 1;
	}

	vector<int> res;
	int cur = -1;
	vector<int> st;

	for (int i = 0; i < k; ++i) {
		st.push_back(a[i]);
		while (!st.empty() && st.back() == cur + 1) {
			++cur;
			st.pop_back();
		}
	}
	while (cur < n - 1) {
		if (st.empty()) {
			for (int i = n - 1; i > cur; --i) {
				res.push_back(i);
			}
			break;
		}
		int x = st.back();
		if (x <= cur) {
			puts("-1");
			return 0;
		}
		for (int i = x - 1; i > cur; --i) {
			res.push_back(i);
		}
		cur = x;
		st.pop_back();
	}

	if (a.size() + res.size() != n) {
		puts("-1");
		return 0;
	}
	for (int x : a) {
		printf("%d ", x + 1);
	}
	for (int x : res) {
		printf("%d ", x + 1);
	}
	printf("\n");
	
	return 0;
}