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
    int cnt = (n - 11) / 2;
    int pos = -1;
    int kek = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '8') {
            ++kek;
            if (kek == cnt + 1) {
                pos = i;
            }
        }
    }
    if (kek <= cnt || (pos - cnt) > cnt) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}