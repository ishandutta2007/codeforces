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
    int n, x;
    cin >> n >> x;
    int m = (1 << n);
    set <int> can;
    for (int i = 1; i < m; ++i) can.insert(i);
	can.erase(x);
	vector <int> ans;
	int pr = 0;
	while (!can.empty()) {
		int c = *can.begin();
		ans.push_back(c ^ pr);
		pr = c;
		can.erase(c);
		can.erase(c ^ x);
	}
	cout << ans.size() << '\n';
	for (auto c : ans) cout << c << ' ';
}