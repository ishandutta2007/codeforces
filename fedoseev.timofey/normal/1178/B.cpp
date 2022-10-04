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
    int n = s.size();
    vector <int> pref(n + 1), suf(n + 1);
    for (int i = 1; i < n; ++i) {
    	pref[i + 1] = pref[i];
    	if (s[i] == s[i - 1] && s[i] == 'v') {
    		++pref[i + 1];
    	}
    }
    for (int i = n - 2; i >= 0; --i) {
    	suf[i] = suf[i + 1];
    	if (s[i] == s[i + 1] && s[i] == 'v') {
    		++suf[i];
    	}
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'o') {
    		ans += (ll)pref[i] * suf[i + 1];
    	}
    }
    cout << ans << '\n';
}