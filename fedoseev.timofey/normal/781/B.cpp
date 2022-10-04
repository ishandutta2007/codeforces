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
    vector <string> ans(n);
    vector <string> a(n), b(n);
    set <string> used;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        a[i] = s.substr(0, 3);
        b[i] = s.substr(0, 2) + t[0];
        if (used.count(a[i]) && used.count(b[i])) {
            cout << "NO\n";
            exit(0);
        }
        if (!used.count(b[i])) {
            ans[i] = b[i];
        }
        else {
            ans[i] = a[i];
        }
        used.insert(ans[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j] && (ans[i] != b[i] || ans[j] != b[j])) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}