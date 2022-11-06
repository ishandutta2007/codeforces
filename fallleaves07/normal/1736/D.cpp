#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> b(n * 2);
	int c1 = 0;
	for (int i = 0; i < n * 2; i++) {
		b[i] = s[i] - '0';
		c1 += b[i];
	}
	if (c1 % 2 != 0) {
		puts("-1");
		return;
	}
	vector<int> p;
	for (int i = 0, d = 0; i < n * 2; i += 2) {
		if (b[i] != b[i + 1]) {
			if (b[i] == d) {
				p.push_back(i);
			} else {
				p.push_back(i + 1);
			}
			d ^= 1;
		}
	}
	printf("%d ", (int)p.size());
	for (int i = 0; i < (int)p.size(); i++) {
		printf("%d ", p[i] + 1);
	}
	puts("");
	for (int i = 0; i < n * 2; i += 2) {
		printf("%d ", i + 1);
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