#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), loc(n + 1), mxl(n + 1), mxr(n + 1), mnl(n + 1), mnr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		loc[a[i]] = i;
	}
	{
		stack<int> stk;
		for (int i = 1; i <= n; i++) {
			while (!stk.empty() && stk.top() > a[i]) {
				mnr[stk.top()] = a[i];
				stk.pop();
			}
			if (!stk.empty()) {
				mnl[a[i]] = stk.top();
			}
			stk.push(a[i]);
		}
	}
	{
		stack<int> stk;
		for (int i = 1; i <= n; i++) {
			while (!stk.empty() && stk.top() < a[i]) {
				mxr[stk.top()] = a[i];
				stk.pop();
			}
			if (!stk.empty()) {
				mxl[a[i]] = stk.top();
			}
			stk.push(a[i]);
		}
	}
	int ans = 0, d = loc[1], tag = 1;
	while (d > 1) {
		if (tag) {
			while (mxl[a[d]]) {
				d = loc[mxl[a[d]]];
			}
			tag ^= 1, ++ans;
		} else {
			while (mnl[a[d]]) {
				d = loc[mnl[a[d]]];
			}
			tag ^= 1, ++ans;
		}
	}
	d = loc[1], tag = 1;
	while (d < n) {
		if (tag) {
			while (mxr[a[d]]) {
				d = loc[mxr[a[d]]];
			}
			tag ^= 1, ++ans;
		} else {
			while (mnr[a[d]]) {
				d = loc[mnr[a[d]]];
			}
			tag ^= 1, ++ans;
		}
	}
	printf("%d\n", ans);
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