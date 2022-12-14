#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> s(a);
        sort(s.begin(), s.end());

        vector<int> ans;

        auto f = [&](int i) {
            ans.push_back(i + 1);
            tie(a[i], a[i + 1], a[i + 2]) =
                make_tuple(a[i + 2], a[i], a[i + 1]);
        };

        for (int k = n - 1; k > 1; k--) {
            if (a[0] == s[k]) f(0);
            for (int i = 1; i < k; i++) {
                if (a[i] == s[k]) f(i - 1);
            }
        }

        if (a[0] > a[1]) {
            if (a[0] == a[2]) {
                f(0);
                f(0);
            } else {
                int dupe = -1;
                for (int i = 0; i < n - 1; i++) {
                    if (a[i] == a[i + 1]) {
                        dupe = i;
                        break;
                    }
                }

                if (dupe == -1) {
                    cout << "-1\n";
                    continue;
                }

                f(dupe - 1);

                for (int k = dupe; k > 1; k--) {
                    if (a[0] == s[k]) f(0);
                    for (int i = 1; i < k; i++) {
                        if (a[i] == s[k]) f(i - 1);
                    }
                }
            }
        }

        assert(a == s);

        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}