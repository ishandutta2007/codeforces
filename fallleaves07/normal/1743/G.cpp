#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

int mod(int val) {
	return (val < 0) ? (val + M) : ((val >= M) ? (val - M) : val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	vector<int> fib(32);
	unordered_set<int> isf;
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 32; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		isf.insert(fib[i]);
	}
	auto get = [&fib](int len) {
		for (int i = 31; i >= 2 && len > 2; i--) {
			if (len > fib[i]) {
				len -= fib[i];
			}
		}
		return len & 1;
	};
	int n, sum = 1, lst = 1;
	cin >> n;
	vector<pair<int, int>> prefix;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto c : s) {
			vector<pair<int, int>> upd;
			int ans = mod(sum - lst);
			for (auto [len, val] : prefix) {
				if (get(len + 1) == c - '0') {
					upd.emplace_back(len + 1, val);
					if (isf.find(len + 1) != isf.end()) {
						ans = mod(ans - val);
					}
				}
			}
			if (c == '1') {
				upd.emplace_back(1, lst);
			}
			sum = mod(sum + ans), lst = ans;
			swap(prefix, upd);
		}
		printf("%d\n", lst);
	}
    return 0;
}