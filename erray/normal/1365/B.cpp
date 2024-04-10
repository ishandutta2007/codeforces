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
		vector<int> a2 = a;
		sort(a2.begin(), a2.end());
		int sum = accumulate(b.begin(), b.end(), 0);
		cout << (a2 == a || (sum  && sum != n) ? "Yes" : "No") << '\n';
	}
}