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
    string s;
    cin >> s;
    for (int i = 0; i < 5; ++i) {
    	string t;
    	cin >> t;
    	if (t[0] == s[0] || t[1] == s[1]) {
    		cout << "YES\n";
    		return 0;
    	}
    }
    cout << "NO\n";
}