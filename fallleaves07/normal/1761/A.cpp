#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a + b + 1 >= n) {
		return a == b && a == n;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		puts(solve() ? "Yes" : "No");
	}
	return 0;
}