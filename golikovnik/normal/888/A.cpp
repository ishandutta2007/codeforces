#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	int cnt = 0;
	for (int i = 1; i < n-1; ++i) {
		if (a[i] < a[i-1] && a[i] < a[i+1] || a[i] > a[i-1] && a[i] > a[i+1]) ++cnt;
	}
	cout << cnt;
	return 0;
}