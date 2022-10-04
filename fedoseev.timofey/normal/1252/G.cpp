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
    	vector <int> p(n);
    	for (int i = 0; i < n; ++i) cin >> p[i];
    	sort(p.begin(), p.end());
    	vector <int> c = p;	
    	c.resize(unique(c.begin(), c.end()) - c.begin());
    	int m = c.size();
    	vector <int> cnt(m);
    	for (int i = 0; i < n; ++i) {
    		int id = lower_bound(c.begin(), c.end(), p[i]) - c.begin();
    		++cnt[id];
    	}
    	int ans = 0, g = 0, s = 0, b = 0;
    	g = cnt[m - 1];
    	for (int i = m - 2; i >= 0; --i) {
    		if (s <= g) {
    			s += cnt[i];
    		} else if (2 * (g + s + b + cnt[i]) <= n) {
    			b += cnt[i];
    		} else {
    			break;
    		}
    	}
    	if (g < s && g < b && 2 * (g + s + b) <= n) cout << g << ' ' << s << ' ' << b << '\n';
    	else cout << "0 0 0\n";
    }
}