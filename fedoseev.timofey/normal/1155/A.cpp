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
    string s;
    cin >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i + 1] < s[i]) {
            cout << "YES\n";
            cout << i + 1 << ' ' << i + 2 << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}