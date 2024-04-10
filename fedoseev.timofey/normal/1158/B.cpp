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
    int n, k;
    cin >> n >> k;
    if (k == 1) {
    	cout << '1';
    	for (int i = 0; i + 1 < n; ++i) cout << '0';
    	return 0;
    }
    int dt = (n - k) / 2 + 1;
    for (int i = 0; i < n; ++i) {
    	if (i % dt == 0) {
    		cout << '1';
    	}
    	else cout << '0';
    }
}