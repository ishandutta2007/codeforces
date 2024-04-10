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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <int> cnt = {a, b, c, d};
    vector <int> ans;
    for (int mask = 0; mask < (1 << 4); ++mask) {
    	cnt = {a, b, c, d};
    	bool bad = false;
    	vector <int> cur;
    	int ndb = max(0, a - 1) + ((mask >> 0) & 1) + ((mask >> 1) & 1);
    	if (ndb > b) continue;
    	int ndc = max(0, d - 1) + ((mask >> 2) & 1) + ((mask >> 3) & 1);
    	if (ndc > c) continue;
    	cnt[1] -= ndb, cnt[2] -= ndc;
    	if (cnt[1] != cnt[2]) continue;

    	if (mask & 1) cur.push_back(1);
    	for (int i = 0; i < cnt[0]; ++i) {
    		cur.push_back(0);
    		if (i != cnt[0] - 1) cur.push_back(1);
    	}
    	if ((mask >> 1) & 1) cur.push_back(1);

    	for (int i = 0; i < cnt[1]; ++i) {
    		cur.push_back(2);
    		cur.push_back(1);
    	}

    	if ((mask >> 2) & 1) cur.push_back(2);

    	for (int i = 0; i < cnt[3]; ++i) {
    		cur.push_back(3);
    		if (i != cnt[3] - 1) cur.push_back(2);
    	}
    	if ((mask >> 3) & 1) cur.push_back(2);
    	for (int i = 0; i + 1 < cur.size(); ++i) {
    		if (abs(cur[i] - cur[i + 1]) != 1) {
    			bad = true;
    		}
    	}
    	if (!bad) ans = cur;
    }
    if (ans.empty()) {
    	cout << "NO\n";
    } else {
    	cout << "YES\n";
    	for (int x : ans) cout << x << ' ';
    }
}