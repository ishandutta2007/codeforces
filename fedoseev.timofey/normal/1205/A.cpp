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
    if (n % 2 == 0) {
    	cout << "NO\n";
    	return 0;
    }
    vector <int> ans(2 * n);
    int uk = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
    	int j = i + 1;
    	if (i % 4 == 1) {
    		ans[uk] = i;
    		ans[uk + n] = j;
    	} else {
    		ans[uk] = j;
    		ans[uk + n] = i;
    	}
    	++uk;
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n; ++i) cout << ans[i] << ' ';
}