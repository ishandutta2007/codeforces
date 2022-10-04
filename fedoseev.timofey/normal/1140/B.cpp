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
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	int ans = 1e9;
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == '>') ans = min(ans, i);
    		if (s[n - i - 1] == '<') ans = min(ans, i);
    	}
    	cout << ans << '\n';
    }
}