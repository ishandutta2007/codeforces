#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    map <int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	int bal = 0;
    	int min_bal = 0;
    	for (int j = 0; j < (int)s.size(); ++j) {
    		if (s[j] == '(') ++bal;
    		else --bal;
    		min_bal = min(min_bal, bal);
    	}
    	if (min_bal < 0) {
    		if (bal >= 0) continue;
    		if (bal < 0 && abs(min_bal) > abs(bal)) {
    			continue;
    		}
    	}
    	++cnt[bal];
    }
    int ans = 0;
    ans += cnt[0] / 2;
    for (int i = 1; i <= N; ++i) {
    	ans += min(cnt[i], cnt[-i]);
    }
    cout << ans << '\n';
}