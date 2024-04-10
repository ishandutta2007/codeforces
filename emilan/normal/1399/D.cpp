#include <iostream>
#include <string>
#include <vector>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> ans(n), z, o;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (z.empty()) z.push_back(++cnt);
                ans[i] = z.back();
                o.push_back(z.back());
                z.pop_back();
            } else {
                if (o.empty()) o.push_back(++cnt);
                ans[i] = o.back();
                z.push_back(o.back());
                o.pop_back();
            }
        }

        cout << cnt << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}