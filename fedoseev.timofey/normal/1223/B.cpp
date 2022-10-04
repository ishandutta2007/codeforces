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
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        vector <bool> a(26), b(26);
        for (char c : s) a[c - 'a'] = 1;
        for (char c : t) b[c - 'a'] = 1;
        bool good = false;
        for (int i = 0; i < 26; ++i) {
            if (a[i] && b[i]) {
                cout << "YES\n";
                good = true;
                break;
            }
        }
        if (!good) cout << "NO\n";
    }
}