#include <iostream>
#include <vector>
#include <algorithm>

#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    int cnt1 = 0, cnt2 = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            ++cnt1;
        else
            ++cnt2;
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 2) {
            if (cnt1 >= x)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else {
            if (a[x - 1] == 1)
                ++cnt2, --cnt1;
            else
                ++cnt1, --cnt2;
            a[x - 1] = 1 - a[x - 1];
        }
    }
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	// int t;
	// cin >> t;
	// while (t--)
	// 	solve();
}