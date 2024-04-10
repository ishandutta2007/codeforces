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

int main() {
	int n = nxt();
	vector<int> a(n, -1);
	for (int i = 1; i < n; ++i) {
		a[i] = nxt() - 1;
	}
	vector<int> ans;
	for (int i = n - 1; i > -1; i = a[i]) {
		ans.push_back(i);
	}
	reverse(all(ans));
	for (int x : ans) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}