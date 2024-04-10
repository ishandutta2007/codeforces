#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		multiset<int> m1(a.begin(), a.end()), m2(b.begin(), b.end());
		multiset<pair<int, int>> ms;
		for (int i = 0; i < n>>1; ++i) ms.insert(make_pair(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])));
		for (int i = 0; i < n>>1; ++i) {
			pair<int, int> p = make_pair(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]));
			if (ms.count(p)) ms.erase(ms.find(p));
		}
		cout << (m1 == m2 && (!(n&1) || a[n>>1] == b[n>>1]) && ms.empty() ? "Yes" : "No") << '\n';
	}
}