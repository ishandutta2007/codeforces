#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> ans(n);
	printf("1 ");
	for (int i = 1; i < n; i++) {
		printf("%d ", n - i + 1);
	}
	puts("");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}