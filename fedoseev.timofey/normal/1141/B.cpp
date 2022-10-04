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
    string s;
    for (int i = 0; i < n; ++i) {
    	char c;
    	cin >> c;
    	s += c;
    }
    s += s;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
    	if (s[i] == '1') {
    		++cnt;
    		ans = max(ans, cnt);
    	}
    	else {
    		cnt = 0;
    	}
    }
    cout << ans << '\n';
}