#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (int m = 0; m < (1 << n); ++m) {
    	int res = 0;
    	for (int i = 0; i < n; ++i) {
    		if (m & (1 << i)) res += a[i];
    		else res -= a[i];
    	}
    	res %= 360;
    	if (res == 0) {
    		cout << "YES\n";
    		return 0;
    	}
    }
    cout << "NO\n";
}